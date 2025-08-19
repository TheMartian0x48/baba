#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef intptr_t  iptr;
typedef uintptr_t uptr;

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef struct {
    u64 size;
    u64 capacity;
} ArrayHeader;

typedef struct {
    ArrayHeader header;
    u8*         v;
} U8Array;

typedef struct {
    u64 cap;
} Arena;

void* arena_alloc(Arena* arena, u64 cap, u64 al) { return malloc(cap); }
void  arena_dealloc(Arena* arena, void* ptr) { free(ptr); }

U8Array u8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
U8Array u8_array_make(Arena* arena, u64 capacity);
void    u8_array_kill(Arena* arena, U8Array* array);
bool    u8_array_can_add(U8Array* array);
void    u8_array_add(U8Array* array, u8 element);
void    u8_array_clear(U8Array* array);
bool    u8_array_can_insert(U8Array* array);
void    u8_array_insert(U8Array* array, u8 element, u64 index);
void    u8_array_remove(U8Array* array, u64 index);

U8Array u8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment)
{
    assert(arena && "arena cannot be null");
    U8Array result = {0};

    void* ptr = arena_alloc(arena, sizeof(u8) * capacity, alignment);
    if (ptr == nullptr) {
        return result;
    }

    result.header.capacity = capacity;
    result.header.size     = 0;
    result.v               = ptr;
    return result;
}

U8Array u8_array_make(Arena* arena, u64 capacity) { return u8_array_make_aligned(arena, capacity, 16); }

void u8_array_kill(Arena* arena, U8Array* array)
{
    arena_dealloc(arena, array->v);
    array->header.capacity = 0;
    array->header.size     = 0;
}

void u8_array_add(U8Array* array, u8 element)
{
    assert(element && "element cannot be null");
    assert(array && "array cannot be null");

    ArrayHeader* header = &array->header;

    array->v[header->size++] = element;
}

bool u8_array_can_add(U8Array* array)
{
    assert(array && "array cannot be null");
    return array->header.size < array->header.capacity;
}

void u8_array_clear(U8Array* array)
{
    assert(array && "array cannot be null");
    array->header.size = 0;
}

void u8_array_insert(U8Array* array, u8 element, u64 index)
{
    assert(element && "element cannot be null");
    assert(array && "array cannot be null");

    uptr src  = (uptr)array->v + sizeof(u8) * index;
    uptr dest = (uptr)array->v + sizeof(u8) * index + sizeof(u8);
    u64  size = sizeof(u8) * (array->header.size - index);

    memmove((void*)dest, (void*)src, size);
    array->v[index] = element;
    array->header.size++;
}

bool u8_array_can_insert(U8Array* array)
{
    assert(array && "array cannot be null");
    return array->header.size < array->header.capacity;
}

void u8_array_remove(U8Array* array, u64 index)
{
    assert(array && "array cannot be null");

    void* src  = (void*)((uptr)array->v + (index + 1) * sizeof(u8));
    void* dest = (void*)((uptr)array->v + index * sizeof(u8));
    u64   size = (array->header.size - index - 1) * sizeof(u8);

    memmove(dest, src, size);
    array->header.size--;
}

void test_u8_array_make_and_kill()
{
    Arena   arena = {0};
    U8Array array = u8_array_make(&arena, 10);
    assert(array.v != NULL);
    assert(array.header.capacity == 10);
    assert(array.header.size == 0);

    u8_array_kill(&arena, &array);
    assert(array.v == NULL);
    assert(array.header.capacity == 0);
    assert(array.header.size == 0);
}

void test_u8_array_add_and_can_add()
{
    Arena   arena = {0};
    U8Array array = u8_array_make(&arena, 2);
    assert(u8_array_can_add(&array));
    u8_array_add(&array, 1);
    assert(array.header.size == 1);
    assert(array.v[0] == 1);
    assert(u8_array_can_add(&array));
    u8_array_add(&array, 2);
    assert(array.header.size == 2);
    assert(array.v[1] == 2);
    assert(!u8_array_can_add(&array));
    u8_array_kill(&arena, &array);
}

void test_u8_array_clear()
{
    Arena   arena = {0};
    U8Array array = u8_array_make(&arena, 5);
    u8_array_add(&array, 42);
    u8_array_add(&array, 43);
    assert(array.header.size == 2);
    u8_array_clear(&array);
    assert(array.header.size == 0);
    u8_array_kill(&arena, &array);
}

void test_u8_array_insert_and_can_insert()
{
    Arena   arena = {0};
    U8Array array = u8_array_make(&arena, 3);
    u8_array_add(&array, 10);
    u8_array_add(&array, 20);
    assert(u8_array_can_insert(&array));
    u8_array_insert(&array, 15, 1);
    assert(array.header.size == 3);
    assert(array.v[0] == 10);
    assert(array.v[1] == 15);
    assert(array.v[2] == 20);
    assert(!u8_array_can_insert(&array));
    u8_array_kill(&arena, &array);
}

void test_u8_array_remove()
{
    Arena   arena = {0};
    U8Array array = u8_array_make(&arena, 3);
    u8_array_add(&array, 5);
    u8_array_add(&array, 6);
    u8_array_add(&array, 7);
    u8_array_remove(&array, 1);
    assert(array.header.size == 2);
    assert(array.v[0] == 5);
    assert(array.v[1] == 7);
    u8_array_kill(&arena, &array);
}

int main()
{
    test_u8_array_make_and_kill();
    test_u8_array_add_and_can_add();
    test_u8_array_clear();
    test_u8_array_insert_and_can_insert();
    test_u8_array_remove();
    printf("All tests passed!\n");
    return 0;
}
