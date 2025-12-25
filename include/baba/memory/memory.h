#ifndef BABA_MEMORY
#define BABA_MEMORY

/**Dccumentation
# Memory

## Helper methods

Description
Copies bytes from source to destination
Input
dest    : where data will be copied
src     : from where data will be copied
size    : how many bytes to copy
Output
return copy of des pointer
function void* mem_copy(void* dest, void* src, u64 size);


Description
Moves bytes from source to destination
Input
dest    : where data will be moved
src     : from where data will be moved
size    : how many bytes to move
Output
return copy of des pointer
function void* mem_move(void* dest, void* src, u64 size);

Description
Set range of contiguous memory with given byte value
Input
ptr     : where data will be updatd
value   : what value to set
size    : how many bytes to update
Output
return copy of des pointer
void* mem_set(void* ptr, u8 value, u64 size);

Description
Compare two buffer lexicographically. nullptr is treated as empty space
Input
lhs     :  pointer of objects to compare
rhs     : pointer of objects to compare
size    : how many bytes to compare
Output
* negative value if lhs < rhs
* 0 if lhs = rhs
* positive value if lhs > rhs
function i32   mem_cmp(const void* lhs, const void* rhs, u64 size);

Description
Find first occurence of a bytes starting from given pointer. but will return nullptr for nullptr location
Input
ptr     : pointer of objects to examin
value   : byte value to find
size    : how many bytes to examin
Output
* ptr of location matching value
* nullptr otherwise
function void* mem_find(void* ptr, u8 value, u64 size);


 */

#include "../types.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

/* const char*  FREE_LIST_ARENA_TYPE    = "FREE"; */
/* const char*  HYBRID_ARENA_TYPE       = "HYBRID"; */
/* const char*  LINEAR_ARENA_TYPE       = "LINEAR"; */
/* const char*  POOL_ARENA_TYPE         = "POOL"; */
/* const char*  PROXY_ARENA_TYPE        = "PROXY"; */
/* const char*  RING_BUFFER_ARENA_TYPE  = "RING"; */
/* const char*  SLAB_ARENA_TYPE         = "SLAB"; */
/* const char*  STACK_ARENA_TYPE        = "STACK"; */
/* const char*  UNKNOWN_ARENA_TYPE      = "UNKNOWN"; */
/* const size_t STACK_ALLOC_START_MAGIC = 0xDEADBEEFCAFEBABE; */
/* const size_t STACK_ALLOC_END_MAGIC   = 0xBABECAFEDEADBEEF; */
/* const size_t FREED_MAGIC             = 0xDEADDEADDEADDEAD; */
/* const size_t DEFAULT_ALIGNMENT       = 2 * sizeof(void*); */

static const u64 DEFAULT_ALIGNMENT = 2 * sizeof(void*);

typedef enum {
    ArenaTypeLinear, // linear arena
    ArenaTypeProxy,  // proxy to malloc
} ArenaType;

typedef struct {
    u64 capacity;
    u64 used;
    u64 free;
    u64 allocation_count;
    u64 deallocation_count;
    u64 fragmentation_ratio; // percentage between [0 - 100]
    u64 larges_free_block;
} ArenaStats;

typedef void*      (*ArenaMakeFn)(u64);
typedef void       (*ArenaResetFn)(void*);
typedef void       (*ArenaKillFn)(void*);
typedef void*      (*ArenaAllocFn)(void*, u64, u64);
typedef void*      (*ArenaReallocFn)(void*, void*, u64, u64, u64);
typedef void       (*ArenaDeallocFn)(void*, void*);
typedef ArenaStats (*ArenaStatsFn)(void*);
typedef bool       (*ArenaCanAllocFn)(void*, u64);

typedef struct {
    /* ArenaMakeFn     make_fn; */
    ArenaKillFn     kill_fn;
    ArenaResetFn    reset_fn;
    ArenaAllocFn    alloc_fn;
    ArenaDeallocFn  dealloc_fn;
    ArenaReallocFn  realloc_fn;
    ArenaCanAllocFn can_alloc_fn;
    ArenaStatsFn    stats_fn;
    void*           instance;
    ArenaType       arena_type;
} Arena;

typedef struct {
    char* buffer;
    u64   capacity;
    u64   offset;
    u64   total_allocations;
} LinearArena;

typedef struct {
    u64 total_allocations;
} ProxyArena;

//***** arena
Arena*     arena_make(ArenaType type, u64 capacity);
void       arena_kill(Arena* arena);
void       arena_reset(const Arena* arena);
void*      arena_alloc(const Arena* arena, u64 size, u64 alignment);
void*      arena_realloc(const Arena* arena, void* ptr, u64 old_size, u64 new_size, u64 alignment);
void       arena_dealloc(const Arena* arena, void* ptr);
bool       arena_can_alloc(const Arena* arena, u64 size);
ArenaStats arena_stats(const Arena* arena);

//***** linear arena
void*      arena_linear_make(u64 capacity);
void       arena_linear_kill(void* arena);
void       arena_linear_reset(void* arena);
void*      arena_linear_alloc(void* arena, u64 size, u64 alignment);
void*      arena_linear_realloc(void* arena, void* ptr, u64 old_size, u64 new_size, u64 alignment);
void       arena_linear_dealloc(void* arena, void* ptr);
bool       arena_linear_can_alloc(void* arena, u64 size);
ArenaStats arena_linear_stats(void* arena);

//***** proxy arena
void*      arena_proxy_make(u64 capacity);
void       arena_proxy_kill(void* arena);
void       arena_proxy_reset(void* arena);
void*      arena_proxy_alloc(void* arena, u64 size, u64 alignment);
void*      arena_proxy_realloc(void* arena, void* ptr, u64 old_size, u64 new_size, u64 alignment);
void       arena_proxy_dealloc(void* arena, void* ptr);
bool       arena_proxy_can_alloc(void* arena, u64 size);
ArenaStats arena_proxy_stats(void* arena);

//***** memory utility
void* mem_copy(void* dest, const void* src, u64 size);
void* mem_move(void* dest, const void* src, u64 size);
void* mem_find(const void* ptr, u8 value, u64 size);
void* mem_set(void* ptr, u8 value, u64 size);
i32   mem_cmp(const void* lhs, const void* rhs, u64 size);

#endif
