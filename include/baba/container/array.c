#include "container.h"

void* array_make_aligned(Arena* arena, ArrayHeader* header, void** array, u64 capacity, u64 item_size, u64 alignment)
{
    assert(arena && "arena cannot be null");
    assert(header && "header cannot be null");
    void* ptr = arena_alloc(arena, item_size * capacity, alignment);
    if (ptr == nullptr) {
        return nullptr;
    }
    header->capacity = capacity;
    header->size     = 0;
    return ptr;
}

void* array_make(Arena* arena, ArrayHeader* header, void** array, u64 capacity, u64 item_size)
{
    return array_make_aligned(arena, header, array, capacity, item_size, DEFAULT_ALIGNMENT);
}

void array_kill(Arena* arena, ArrayHeader* header, void** array)
{
    arena_dealloc(arena, *array);
    header->size     = 0;
    header->capacity = 0;
}

void* array_reserve(Arena* arena, ArrayHeader* header, void* arr, u64 item_size)
{
    return array_reserve_alignment(arena, header, arr, item_size, DEFAULT_ALIGNMENT);
}

void* array_reserve_alignment(Arena* arena, ArrayHeader* header, void* arr, u64 item_size, u64 alignment)
{
    const u64 old_capacity = item_size * header->capacity;
    const u64 new_capacity = item_size * 2 * header->capacity;
    void*     ptr          = arena_realloc(arena, arr, old_capacity, new_capacity, alignment);
    header->capacity *= 2;
    assert(ptr && "failed to grow array");
    return ptr;
}

bool array_can_add(const ArrayHeader* header)
{
    assert(header && "header cannot be null");
    return header->size < header->capacity;
}

void array_add(ArrayHeader* header, void** array, void* element, u64 item_size)
{
    assert(element && "element cannot be null");
    assert(header && "header cannot be null");
    assert(array && "array cannot be null");

    void* dest = (void*)((uptr)*array + item_size * header->size);
    mem_copy(dest, element, item_size);
    header->size++;
}

void array_clear(ArrayHeader* header, [[maybe_unused]] void** array)
{
    assert(header && "header cannot be null");
    header->size = 0;
}

bool array_can_insert(const ArrayHeader* header)
{
    assert(header && "header cannot be null");
    return header->size < header->capacity;
}

void array_insert(ArrayHeader* header, void** array, void* element, u64 item_size, u64 index)
{
    assert(element && "element cannot be null");
    assert(header && "header cannot be null");
    assert(array && "array cannot be null");
    uptr src  = (uptr)*array + item_size * index;
    uptr dest = (uptr)*array + item_size * index + item_size;
    u64  size = item_size * (header->size - index);
    mem_move((void*)dest, (void*)src, size);
    mem_copy((void*)src, element, item_size);
    header->size++;
}

void array_remove(ArrayHeader* header, void** array, u64 item_size, u64 index)
{
    assert(header && "header cannot be null");
    assert(array && "array cannot be null");
    assert(index < header->size && "index out of bound");
    if (header->size == header->capacity) {
        header->size--;
        return;
    }

    void* src  = (void*)((uptr)*array + (index + 1) * item_size);
    void* dest = (void*)((uptr)*array + index * item_size);
    u64   size = header->size - index - 1;
    mem_move(dest, src, size);
    header->size--;
}

//***** Macro Implementation for primitive types *****

#define PrimitiveArrayMakeAligned(STRUCT_NAME, TYPE_NAME)                                                                                            \
    assert(arena && "arena cannot be null");                                                                                                         \
    STRUCT_NAME result = {0};                                                                                                                        \
    void*       ptr    = arena_alloc(arena, sizeof(TYPE_NAME) * capacity, alignment);                                                                \
    if (ptr == nullptr) {                                                                                                                            \
        return result;                                                                                                                               \
    }                                                                                                                                                \
    result.header.capacity = capacity;                                                                                                               \
    result.header.size     = 0;                                                                                                                      \
    result.v               = ptr;                                                                                                                    \
    return result;

#define PrimitiveArrayKill                                                                                                                           \
    if (array == nullptr)                                                                                                                            \
        return;                                                                                                                                      \
    arena_dealloc(arena, array->v);                                                                                                                  \
    array->v               = nullptr;                                                                                                                \
    array->header.capacity = 0;                                                                                                                      \
    array->header.size     = 0;

#define PrimitiveArrayAdd(TYPE_NAME)                                                                                                                 \
    assert(element && "element cannot be null");                                                                                                     \
    assert(array && "array cannot be null");                                                                                                         \
    ArrayHeader* header      = &array->header;                                                                                                       \
    array->v[header->size++] = element;

#define PrimitiveArrayCanAdd                                                                                                                         \
    assert(array && "array cannot be null");                                                                                                         \
    return array->header.size < array->header.capacity;

#define PrimitiveArrayClear                                                                                                                          \
    assert(array && "array cannot be null");                                                                                                         \
    array->header.size = 0;

#define PrimitiveArrayInsert(TYPE_NAME)                                                                                                              \
    assert(element && "element cannot be null");                                                                                                     \
    assert(array && "array cannot be null");                                                                                                         \
    uptr src  = (uptr)array->v + sizeof(TYPE_NAME) * index;                                                                                          \
    uptr dest = (uptr)array->v + sizeof(TYPE_NAME) * index + sizeof(u8);                                                                             \
    u64  size = sizeof(TYPE_NAME) * (array->header.size - index);                                                                                    \
    mem_move((void*)dest, (void*)src, size);                                                                                                         \
    array->v[index] = element;                                                                                                                       \
    array->header.size++;

#define PrimitiveArrayCanInsert                                                                                                                      \
    assert(array && "array cannot be null");                                                                                                         \
    return array->header.size < array->header.capacity;

#define PrimitiveArrayRemove(TYPE_NAME)                                                                                                              \
    assert(array && "array cannot be null");                                                                                                         \
    void* src  = (void*)((uptr)array->v + (index + 1) * sizeof(TYPE_NAME));                                                                          \
    void* dest = (void*)((uptr)array->v + index * sizeof(TYPE_NAME));                                                                                \
    u64   size = (array->header.size - index - 1) * sizeof(TYPE_NAME);                                                                               \
    mem_move(dest, src, size);                                                                                                                       \
    array->header.size--;

//***** U8Array Implementation *****

U8Array u8_array_make_aligned(Arena* arena, const u64 capacity, const u64 alignment) { PrimitiveArrayMakeAligned(U8Array, u8); }
U8Array u8_array_make(Arena* arena, const u64 capacity) { return u8_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void    u8_array_kill(Arena* arena, U8Array* array) { PrimitiveArrayKill; }
void    u8_array_add(U8Array* array, const u8 element) { PrimitiveArrayAdd(u8); }
bool    u8_array_can_add(const U8Array* array) { PrimitiveArrayCanAdd }
void    u8_array_clear(U8Array* array) { PrimitiveArrayClear; }
void    u8_array_insert(U8Array* array, const u8 element, const u64 index) { PrimitiveArrayInsert(u8); }
bool    u8_array_can_insert(const U8Array* array) { PrimitiveArrayCanInsert }
void    u8_array_remove(U8Array* array, const u64 index) { PrimitiveArrayRemove(u8); }

/* U8Array u8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) */
/* { */
/*     assert(arena && "arena cannot be null"); */
/*     U8Array result = {0}; */
/**/
/*     void* ptr = arena_alloc(arena, sizeof(u8) * capacity, alignment); */
/*     if (ptr == nullptr) { */
/*         return result; */
/*     } */
/**/
/*     result.header.capacity = capacity; */
/*     result.header.size     = 0; */
/*     result.v               = ptr; */
/*     return result; */
/* } */
/**/
/* U8Array u8_array_make(Arena* arena, u64 capacity) { return u8_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); } */
/**/
/* void u8_array_kill(Arena* arena, U8Array* array) */
/* { */
/*     arena_dealloc(arena, array->v); */
/*     array->v               = nullptr; */
/*     array->header.capacity = 0; */
/*     array->header.size     = 0; */
/* } */
/**/
/* void u8_array_add(U8Array* array, u8 element) */
/* { */
/*     assert(element && "element cannot be null"); */
/*     assert(array && "array cannot be null"); */
/**/
/*     ArrayHeader* header = &array->header; */
/**/
/*     array->v[header->size++] = element; */
/* } */
/**/
/* bool u8_array_can_add(U8Array* array) */
/* { */
/*     assert(array && "array cannot be null"); */
/*     return array->header.size < array->header.capacity; */
/* } */
/**/
/* void u8_array_clear(U8Array* array) */
/* { */
/*     assert(array && "array cannot be null"); */
/*     array->header.size = 0; */
/* } */
/**/
/* void u8_array_insert(U8Array* array, u8 element, u64 index) */
/* { */
/*     assert(element && "element cannot be null"); */
/*     assert(array && "array cannot be null"); */
/**/
/*     uptr src  = (uptr)array->v + sizeof(u8) * index; */
/*     uptr dest = (uptr)array->v + sizeof(u8) * index + sizeof(u8); */
/*     u64  size = sizeof(u8) * (array->header.size - index); */
/**/
/*     mem_move((void*)dest, (void*)src, size); */
/*     array->v[index] = element; */
/*     array->header.size++; */
/* } */
/**/
/* bool u8_array_can_insert(U8Array* array) */
/* { */
/*     assert(array && "array cannot be null"); */
/*     return array->header.size < array->header.capacity; */
/* } */
/**/
/* void u8_array_remove(U8Array* array, u64 index) */
/* { */
/*     assert(array && "array cannot be null"); */
/**/
/*     void* src  = (void*)((uptr)array->v + (index + 1) * sizeof(u8)); */
/*     void* dest = (void*)((uptr)array->v + index * sizeof(u8)); */
/*     u64   size = (array->header.size - index - 1) * sizeof(u8); */
/**/
/*     mem_move(dest, src, size); */
/*     array->header.size--; */
/* } */

//***** U16Array Implementation *****

U16Array u16_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(U16Array, u16); }
U16Array u16_array_make(Arena* arena, u64 capacity) { return u16_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     u16_array_kill(Arena* arena, U16Array* array) { PrimitiveArrayKill; }
void     u16_array_add(U16Array* array, u16 element) { PrimitiveArrayAdd(u16); }
void     u16_array_clear(U16Array* array) { PrimitiveArrayClear; }
void     u16_array_insert(U16Array* array, u16 element, u64 index) { PrimitiveArrayInsert(u16); }
void     u16_array_remove(U16Array* array, u64 index) { PrimitiveArrayRemove(u16); }

//***** U32Array Implementation *****

U32Array u32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(U32Array, u32); }
U32Array u32_array_make(Arena* arena, u64 capacity) { return u32_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     u32_array_kill(Arena* arena, U32Array* array) { PrimitiveArrayKill; }
void     u32_array_add(U32Array* array, u32 element) { PrimitiveArrayAdd(u32); }
void     u32_array_clear(U32Array* array) { PrimitiveArrayClear; }
void     u32_array_insert(U32Array* array, u32 element, u64 index) { PrimitiveArrayInsert(u32); }
void     u32_array_remove(U32Array* array, u64 index) { PrimitiveArrayRemove(u32); }

//***** U64Array Implementation *****

U64Array u64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(U64Array, u64); }
U64Array u64_array_make(Arena* arena, u64 capacity) { return u64_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     u64_array_kill(Arena* arena, U64Array* array) { PrimitiveArrayKill; }
void     u64_array_add(U64Array* array, u64 element) { PrimitiveArrayAdd(u64); }
void     u64_array_clear(U64Array* array) { PrimitiveArrayClear; }
void     u64_array_insert(U64Array* array, u64 element, u64 index) { PrimitiveArrayInsert(u64); }
void     u64_array_remove(U64Array* array, u64 index) { PrimitiveArrayRemove(u64); }

//***** I8Array Implementation *****

I8Array i8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(I8Array, i8); }
I8Array i8_array_make(Arena* arena, u64 capacity) { return i8_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void    i8_array_kill(Arena* arena, I8Array* array) { PrimitiveArrayKill; }
void    i8_array_add(I8Array* array, i8 element) { PrimitiveArrayAdd(i8); }
void    i8_array_clear(I8Array* array) { PrimitiveArrayClear; }
void    i8_array_insert(I8Array* array, i8 element, u64 index) { PrimitiveArrayInsert(i8); }
void    i8_array_remove(I8Array* array, u64 index) { PrimitiveArrayRemove(i8); }

//***** I16Array Implementation *****

I16Array i16_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(I16Array, i16); }
I16Array i16_array_make(Arena* arena, u64 capacity) { return i16_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     i16_array_kill(Arena* arena, I16Array* array) { PrimitiveArrayKill; }
void     i16_array_add(I16Array* array, i16 element) { PrimitiveArrayAdd(i16); }
void     i16_array_clear(I16Array* array) { PrimitiveArrayClear; }
void     i16_array_insert(I16Array* array, i16 element, u64 index) { PrimitiveArrayInsert(i16); }
void     i16_array_remove(I16Array* array, u64 index) { PrimitiveArrayRemove(i16); }

//***** I32Array Implementation *****

I32Array i32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(I32Array, i32); }
I32Array i32_array_make(Arena* arena, u64 capacity) { return i32_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     i32_array_kill(Arena* arena, I32Array* array) { PrimitiveArrayKill; }
void     i32_array_add(I32Array* array, i32 element) { PrimitiveArrayAdd(i32); }
void     i32_array_clear(I32Array* array) { PrimitiveArrayClear; }
void     i32_array_insert(I32Array* array, i32 element, u64 index) { PrimitiveArrayInsert(i32); }
void     i32_array_remove(I32Array* array, u64 index) { PrimitiveArrayRemove(i32); }

//***** I64Array Implementation *****

I64Array i64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(I64Array, i64); }
I64Array i64_array_make(Arena* arena, u64 capacity) { return i64_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     i64_array_kill(Arena* arena, I64Array* array) { PrimitiveArrayKill; }
void     i64_array_add(I64Array* array, i64 element) { PrimitiveArrayAdd(i64); }
void     i64_array_clear(I64Array* array) { PrimitiveArrayClear; }
void     i64_array_insert(I64Array* array, i64 element, u64 index) { PrimitiveArrayInsert(i64); }
void     i64_array_remove(I64Array* array, u64 index) { PrimitiveArrayRemove(i64); }

//***** B8Array Implementation *****

B8Array b8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(B8Array, b8); }
B8Array b8_array_make(Arena* arena, u64 capacity) { return b8_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void    b8_array_kill(Arena* arena, B8Array* array) { PrimitiveArrayKill; }
void    b8_array_add(B8Array* array, b8 element) { PrimitiveArrayAdd(b8); }
void    b8_array_clear(B8Array* array) { PrimitiveArrayClear; }
void    b8_array_insert(B8Array* array, b8 element, u64 index) { PrimitiveArrayInsert(b8); }
void    b8_array_remove(B8Array* array, u64 index) { PrimitiveArrayRemove(b8); }

//***** B16Array Implementation *****

B16Array b16_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(B16Array, b16); }
B16Array b16_array_make(Arena* arena, u64 capacity) { return b16_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     b16_array_kill(Arena* arena, B16Array* array) { PrimitiveArrayKill; }
void     b16_array_add(B16Array* array, b16 element) { PrimitiveArrayAdd(b16); }
void     b16_array_clear(B16Array* array) { PrimitiveArrayClear; }
void     b16_array_insert(B16Array* array, b16 element, u64 index) { PrimitiveArrayInsert(b16); }
void     b16_array_remove(B16Array* array, u64 index) { PrimitiveArrayRemove(b16); }

//***** B32Array Implementation *****

B32Array b32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(B32Array, b32); }
B32Array b32_array_make(Arena* arena, u64 capacity) { return b32_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     b32_array_kill(Arena* arena, B32Array* array) { PrimitiveArrayKill; }
void     b32_array_add(B32Array* array, b32 element) { PrimitiveArrayAdd(b32); }
void     b32_array_clear(B32Array* array) { PrimitiveArrayClear; }
void     b32_array_insert(B32Array* array, b32 element, u64 index) { PrimitiveArrayInsert(b32); }
void     b32_array_remove(B32Array* array, u64 index) { PrimitiveArrayRemove(b32); }

//***** B64Array Implementation *****

B64Array b64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(B64Array, b64); }
B64Array b64_array_make(Arena* arena, u64 capacity) { return b64_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     b64_array_kill(Arena* arena, B64Array* array) { PrimitiveArrayKill; }
void     b64_array_add(B64Array* array, b64 element) { PrimitiveArrayAdd(b64); }
void     b64_array_clear(B64Array* array) { PrimitiveArrayClear; }
void     b64_array_insert(B64Array* array, b64 element, u64 index) { PrimitiveArrayInsert(b64); }
void     b64_array_remove(B64Array* array, u64 index) { PrimitiveArrayRemove(b64); }

//***** F32Array Implementation *****

F32Array f32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(F32Array, f32); }
F32Array f32_array_make(Arena* arena, u64 capacity) { return f32_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     f32_array_kill(Arena* arena, F32Array* array) { PrimitiveArrayKill; }
void     f32_array_add(F32Array* array, f32 element) { PrimitiveArrayAdd(f32); }
void     f32_array_clear(F32Array* array) { PrimitiveArrayClear; }
void     f32_array_insert(F32Array* array, f32 element, u64 index) { PrimitiveArrayInsert(f32); }
void     f32_array_remove(F32Array* array, u64 index) { PrimitiveArrayRemove(f32); }

//***** F64Array Implementation *****

F64Array f64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment) { PrimitiveArrayMakeAligned(F64Array, f64); }
F64Array f64_array_make(Arena* arena, u64 capacity) { return f64_array_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }
void     f64_array_kill(Arena* arena, F64Array* array) { PrimitiveArrayKill; }
void     f64_array_add(F64Array* array, f64 element) { PrimitiveArrayAdd(f64); }
void     f64_array_clear(F64Array* array) { PrimitiveArrayClear; }
void     f64_array_insert(F64Array* array, f64 element, u64 index) { PrimitiveArrayInsert(f64); }
void     f64_array_remove(F64Array* array, u64 index) { PrimitiveArrayRemove(f64); }
