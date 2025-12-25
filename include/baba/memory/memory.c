#include "memory.h"

Arena* arena_make(ArenaType type, u64 capacity)
{
    Arena* arena = malloc(sizeof(Arena));
    void*  instance;
    switch (type) {
    case ArenaTypeLinear:
        instance = arena_linear_make(capacity);
        *arena   = (Arena){
              .kill_fn      = arena_linear_kill,
              .reset_fn     = arena_linear_reset,
              .alloc_fn     = arena_linear_alloc,
              .dealloc_fn   = arena_linear_dealloc,
              .realloc_fn   = arena_linear_realloc,
              .can_alloc_fn = arena_linear_can_alloc,
              .stats_fn     = arena_linear_stats,
              .instance     = instance,
              .arena_type   = ArenaTypeLinear,
        };
        break;
    default:
        instance = arena_proxy_make(capacity);
        *arena   = (Arena){
              .kill_fn      = arena_proxy_kill,
              .reset_fn     = arena_proxy_reset,
              .alloc_fn     = arena_proxy_alloc,
              .dealloc_fn   = arena_proxy_dealloc,
              .realloc_fn   = arena_proxy_realloc,
              .can_alloc_fn = arena_proxy_can_alloc,
              .stats_fn     = arena_proxy_stats,
              .instance     = instance,
              .arena_type   = ArenaTypeProxy,
        };
    }
    return arena;
}

void arena_kill(Arena* arena)
{
    if (arena == nullptr) {
        return;
    }
    arena->kill_fn(arena->instance);
    free(arena->instance);
    free(arena);
}

void  arena_reset(const Arena* arena) { arena->reset_fn(arena->instance); }
void* arena_alloc(const Arena* arena, u64 size, u64 alignment) { return arena->alloc_fn(arena->instance, size, alignment); }
void* arena_realloc(const Arena* arena, void* ptr, u64 old_size, u64 new_size, u64 alignment)
{
    return arena->realloc_fn(arena->instance, ptr, old_size, new_size, alignment);
}
void       arena_dealloc(const Arena* arena, void* ptr) { arena->dealloc_fn(arena->instance, ptr); }
bool       arena_can_alloc(const Arena* arena, u64 size) { return arena->can_alloc_fn(arena->instance, size); }
ArenaStats arena_stats(const Arena* arena) { return arena->stats_fn(arena->instance); }
//== LINEAR ARENA IMPLEMENTATION

void* arena_linear_make(u64 capacity)
{
    LinearArena* arena = malloc(sizeof(LinearArena));
    if (arena == nullptr) {
        return nullptr;
    }
    arena->buffer = (char*)malloc(capacity);
    if (arena->buffer == nullptr) {
        free(arena);
        return nullptr;
    }
    *arena = (LinearArena){
        .buffer            = arena->buffer,
        .capacity          = capacity,
        .offset            = 0,
        .total_allocations = 0,
    };
    return arena;
}

void arena_linear_kill(void* arena)
{
    if (arena == nullptr) {
        return;
    }
    LinearArena* linear_arena = arena;
    free(linear_arena->buffer);
    free(linear_arena);
}

void arena_linear_reset(void* arena)
{
    LinearArena* linear_arena = arena;
    if (arena == nullptr) {
        return;
    }
    linear_arena->offset            = 0;
    linear_arena->total_allocations = 0;
}
void* arena_linear_alloc(void* arena, u64 size, u64 alignment)
{
    assert(IsTwoPower(alignment) && "alignment must be power of 2");
    LinearArena* linear_arena = arena;
    uptr         ptr          = (uptr)linear_arena->buffer + linear_arena->offset;
    u64          mod          = GetTwoPowerModulo(ptr, alignment);
    if (mod) {
        ptr += alignment - mod;
    }
    if (ptr - (uptr)linear_arena->buffer + size >= linear_arena->capacity) {
        return nullptr;
    }
    linear_arena->offset = ptr + size - (uptr)linear_arena->buffer;
    linear_arena->total_allocations++;
    return (void*)ptr;
}
void* arena_linear_realloc(void* arena, void* ptr, u64 old_size, u64 new_size, u64 alignment)
{
    if (old_size >= new_size || ptr == nullptr) {
        return ptr;
    }
    assert(IsTwoPower(alignment) && "alignment must be power of 2");
    LinearArena* linear_arena = (LinearArena*)arena;
    uptr         u_ptr        = (uptr)ptr;
    uptr         u_buffer     = (uptr)linear_arena->buffer;

    /**
     cases
        1. ptr is aliged to alignment
            1.1. try adding to end
            1.2. new area
        2. ptr is not alignment
            1.1. can move forward and copy and add extra space at end
            1.2 new area
    */
    if (IsTwoPowerModuloZero(u_ptr, alignment)) {
        // case 1
        if ((u_ptr - u_buffer) + old_size == linear_arena->offset) {
            // case 1.1
            if (u_ptr + (new_size - old_size) >= u_buffer + linear_arena->capacity) {
                return nullptr;
            }
            linear_arena->offset += (new_size - old_size);
            linear_arena->total_allocations++;
            return ptr;
        }
        // case 1.2
        if (linear_arena->offset + new_size >= linear_arena->capacity) {
            return nullptr;
        }
        void* new_ptr = arena_linear_alloc(arena, new_size, alignment);
        mem_copy(new_ptr, ptr, old_size);
        return new_ptr;
    }
    // case 2
    if ((u_ptr - u_buffer) + old_size == linear_arena->offset) {
        // case 2.1
        u64 move_forward_bytes = alignment - GetTwoPowerModulo(u_ptr, alignment);
        if (linear_arena->offset + (new_size - old_size) + move_forward_bytes >= linear_arena->capacity) {
            return nullptr;
        }
        void* new_ptr = (void*)(u_ptr + move_forward_bytes);
        mem_move(new_ptr, ptr, old_size);
        linear_arena->offset += move_forward_bytes + (new_size - old_size);
        linear_arena->total_allocations++;
        return new_ptr;
    }
    // case 2.2
    if (linear_arena->offset + new_size >= linear_arena->capacity) {
        return nullptr;
    }
    void* new_ptr = arena_linear_alloc(arena, new_size, alignment);
    mem_copy(new_ptr, ptr, old_size);
    return new_ptr;
}

void arena_linear_dealloc(void* arena, void* ptr)
{
    return; // No-op for linear arena
}
bool arena_linear_can_alloc(void* arena, u64 size)
{
    if (arena == nullptr) {
        return false;
    }
    LinearArena* linear_arena = (LinearArena*)arena;
    return linear_arena->offset + size < linear_arena->capacity;
}

ArenaStats arena_linear_stats(void* arena)
{
    if (arena == nullptr) {
        return (ArenaStats){0};
    }
    LinearArena* linear_arena = (LinearArena*)arena;
    return (ArenaStats){
        .capacity            = linear_arena->capacity,
        .used                = linear_arena->offset,
        .free                = linear_arena->capacity - linear_arena->offset,
        .allocation_count    = linear_arena->total_allocations,
        .deallocation_count  = 0, // Linear arena does not track deallocations
        .fragmentation_ratio = 0, // No fragmentation in linear arena
        .larges_free_block   = linear_arena->capacity - linear_arena->offset,
    };
}

//== PROXY ARENA IMPLEMENTATION
void* arena_proxy_make(u64 capacity)
{
    ProxyArena* arena = (ProxyArena*)malloc(sizeof(ProxyArena));
    if (!arena) {
        return nullptr;
    }
    *arena = (ProxyArena){
        .total_allocations = 0,
    };
    return arena;
}
void  arena_proxy_kill(void* arena) { free(arena); }
void  arena_proxy_reset(void* arena) {}
void* arena_proxy_alloc(void* arena, u64 size, u64 alignment)
{
    void* ptr = malloc(size);
    if (ptr) {
        ((ProxyArena*)arena)->total_allocations++;
    }
    return ptr;
}
void* arena_proxy_realloc(void* arena, void* ptr, u64 old_size, u64 new_size, u64 alignment)
{
    if (ptr == nullptr) {
        return arena_proxy_alloc(arena, new_size, alignment);
    }
    // void* new_ptr = aligned_alloc(alignment, new_size);
    void* new_ptr = malloc(new_size);
    if (new_ptr) {
        mem_copy(new_ptr, ptr, old_size); // Copy old data to new location
        free(ptr);                        // Free old pointer
        ((ProxyArena*)arena)->total_allocations++;
    }
    return new_ptr;
}
void       arena_proxy_dealloc(void* arena, void* ptr) { free(ptr); }
bool       arena_proxy_can_alloc(void* arena, u64 size) { return true; }
ArenaStats arena_proxy_stats(void* arena)
{
    ArenaStats result = {0};
    result            = (ArenaStats){
                   .capacity            = SIZE_MAX, // Proxy arena does not track allocation
                   .used                = 0,
                   .free                = SIZE_MAX, // Proxy arena does not track free space
                   .allocation_count    = 0,
                   .deallocation_count  = 0,
                   .fragmentation_ratio = 0,        // Proxy arena does not track fragmentation
                   .larges_free_block   = SIZE_MAX, // Proxy arena does not track largest free block
    };
    return result;
}

void* mem_copy(void* dest, const void* src, u64 size)
{
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    return memcpy(dest, src, size);
}
void* mem_move(void* dest, const void* src, u64 size)
{
    if (dest == nullptr || src == nullptr) {
        return nullptr;
    }
    return memmove(dest, src, size);
}
void* mem_find(const void* ptr, u8 value, u64 size)
{
    if (ptr == nullptr) {
        return nullptr;
    }
    return memchr(ptr, value, size);
}
void* mem_set(void* ptr, u8 value, u64 size)
{
    if (ptr == nullptr)
        return nullptr;
    return memset(ptr, value, size);
}
i32 mem_cmp(const void* lhs, const void* rhs, u64 size)
{
    if (lhs == nullptr) {
        return rhs == nullptr ? 0 : -1;
    } else if (rhs == nullptr) {
        return 1;
    }
    return memcmp(lhs, rhs, size);
}
