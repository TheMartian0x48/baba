#ifndef BABA_CONTAINER
#define BABA_CONTAINER

#include "../memory/memory.h"
#include "../types.h"

/**
 * constraints for array
 *      1. struct need to include _ArrayHeader_ header
 *      2. data value must be v ( variable )
 */

typedef struct {
    u64 size;
    u64 capacity;
} ArrayHeader;

typedef struct {
    ArrayHeader header;
    char*       v;
} StrBuf;

typedef struct {
    char* buffer;
    u64   len;
} Str;

typedef struct {
    ArrayHeader header;
    u8*         v;
} U8Array;

typedef struct {
    ArrayHeader header;
    u16*        v;
} U16Array;

typedef struct {
    ArrayHeader header;
    u32*        v;
} U32Array;

typedef struct {
    ArrayHeader header;
    u64*        v;
} U64Array;

typedef struct {
    ArrayHeader header;
    i8*         v;
} I8Array;

typedef struct {
    ArrayHeader header;
    i16*        v;
} I16Array;

typedef struct {
    ArrayHeader header;
    i32*        v;
} I32Array;

typedef struct {
    ArrayHeader header;
    i64*        v;
} I64Array;

typedef struct {
    ArrayHeader header;
    b8*         v;
} B8Array;

typedef struct {
    ArrayHeader header;
    b16*        v;
} B16Array;

typedef struct {
    ArrayHeader header;
    b32*        v;
} B32Array;

typedef struct {
    ArrayHeader header;
    b64*        v;
} B64Array;

typedef struct {
    ArrayHeader header;
    f32*        v;
} F32Array;

typedef struct {
    ArrayHeader header;
    f64*        v;
} F64Array;

//********Generic Array

#define ArrayHeaderCast(a)    ((ArrayHeader*)&(a))
#define ArrayItemSize(a)      (sizeof(*(a).v))
#define ArrayPointerCast(arr) (*((void**)&(arr).v))
#define ArrayDataPointer(arr) ((void**)&(arr).v)

#define ArraySize(a)      (((ArrayHeader*)&(a))->size)
#define ArrayCapacity(a)  (((ArrayHeader*)&(a))->capacity)
#define ArrayAlignment(a) (((ArrayHeader*)&(a))->alignment)
#define ArrayArena(a)     (((ArrayHeader*)&(a))->arena)

#define ArrayMakeAligned(arena, array, capacity, alignment)                                                                                          \
    (ArrayPointerCast((array)) =                                                                                                                     \
            array_make_aligned((arena), ArrayHeaderCast((array)), ArrayDataPointer((array)), (capacity), ArrayItemSize((array)), (alignment)))

#define ArrayMake(arena, array, capacity)                                                                                                            \
    (ArrayPointerCast((array)) = array_make((arena), ArrayHeaderCast((array)), ArrayDataPointer((array)), (capacity), ArrayItemSize((array))))

#define ArrayKill(arena, array) ((arena), array_kill(ArrayHeaderCast((array)), ArrayDataPointer((array))))

#define ArrayAdd(array, element) (array_add(ArrayHeaderCast((array)), ArrayDataPointer((array)), (element), ArrayItemSize((array))))

#define ArrayCanAdd(array) (array_can_add(ArrayHeaderCast((array))))

#define ArrayClear(array) (array_clear(ArrayHeaderCast((array)), ArrayDataPointer((array))))

#define ArrayInsert(array, element, index) (array_insert(ArrayHeaderCast((array)), ArrayDataPointer((array)), element, ArrayItemSize((arr)), index))

#define ArrayCanInsert(array) (array_can_insert(ArrayHeaderCast((array))))

#define ArrayRemove(array, index) (array_remove(ArrayHeaderCast((array)), ArrayDataPointer(array), ArrayItemSize((array)), index))

//******** Primitive Array ********

#define PArraySize(a)      (((ArrayHeader*)&(a))->size)
#define PArrayCapacity(a)  (((ArrayHeader*)&(a))->capacity)
#define PArrayAlignment(a) (((ArrayHeader*)&(a))->alignment)
#define PArrayArena(a)     (((ArrayHeader*)&(a))->arena)

#define PArrayKill(array)                                                                                                                            \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_kill,                                                                                                                      \
        U16Array: u16_array_kill,                                                                                                                    \
        U32Array: u32_array_kill,                                                                                                                    \
        U64Array: u64_array_kill,                                                                                                                    \
        I8Array: i8_array_kill,                                                                                                                      \
        I16Array: i16_array_kill,                                                                                                                    \
        I32Array: i32_array_kill,                                                                                                                    \
        I64Array: i64_array_kill,                                                                                                                    \
        B8Array: b8_array_kill,                                                                                                                      \
        B16Array: b16_array_kill,                                                                                                                    \
        B32Array: b32_array_kill,                                                                                                                    \
        B64Array: b64_array_kill,                                                                                                                    \
        F32Array: f32_array_kill,                                                                                                                    \
        F64Array: f64_array_kill)(&(array))

#define PArrayAdd(array, element)                                                                                                                    \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_add,                                                                                                                       \
        U16Array: u16_array_add,                                                                                                                     \
        U32Array: u32_array_add,                                                                                                                     \
        U64Array: u64_array_add,                                                                                                                     \
        I8Array: i8_array_add,                                                                                                                       \
        I16Array: i16_array_add,                                                                                                                     \
        I32Array: i32_array_add,                                                                                                                     \
        I64Array: i64_array_add,                                                                                                                     \
        B8Array: b8_array_add,                                                                                                                       \
        B16Array: b16_array_add,                                                                                                                     \
        B32Array: b32_array_add,                                                                                                                     \
        B64Array: b64_array_add,                                                                                                                     \
        F32Array: f32_array_add,                                                                                                                     \
        F64Array: f64_array_add)(&(array), (element))

#define PArrayCanAdd(array)                                                                                                                          \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_can_add,                                                                                                                   \
        U16Array: u16_array_can_add,                                                                                                                 \
        U32Array: u32_array_can_add,                                                                                                                 \
        U64Array: u64_array_can_add,                                                                                                                 \
        I8Array: i8_array_can_add,                                                                                                                   \
        I16Array: i16_array_can_add,                                                                                                                 \
        I32Array: i32_array_can_add,                                                                                                                 \
        I64Array: i64_array_can_add,                                                                                                                 \
        B8Array: b8_array_can_add,                                                                                                                   \
        B16Array: b16_array_can_add,                                                                                                                 \
        B32Array: b32_array_can_add,                                                                                                                 \
        B64Array: b64_array_can_add,                                                                                                                 \
        F32Array: f32_array_can_add,                                                                                                                 \
        F64Array: f64_array_can_add)(&(array))

#define PArrayClear(array)                                                                                                                           \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_clear,                                                                                                                     \
        U16Array: u16_array_clear,                                                                                                                   \
        U32Array: u32_array_clear,                                                                                                                   \
        U64Array: u64_array_clear,                                                                                                                   \
        I8Array: i8_array_clear,                                                                                                                     \
        I16Array: i16_array_clear,                                                                                                                   \
        I32Array: i32_array_clear,                                                                                                                   \
        I64Array: i64_array_clear,                                                                                                                   \
        B8Array: b8_array_clear,                                                                                                                     \
        B16Array: b16_array_clear,                                                                                                                   \
        B32Array: b32_array_clear,                                                                                                                   \
        B64Array: b64_array_clear,                                                                                                                   \
        F32Array: f32_array_clear,                                                                                                                   \
        F64Array: f64_array_clear)(&(array))

#define PArrayInsert(array, element, index)                                                                                                          \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_insert,                                                                                                                    \
        U16Array: u16_array_insert,                                                                                                                  \
        U32Array: u32_array_insert,                                                                                                                  \
        U64Array: u64_array_insert,                                                                                                                  \
        I8Array: i8_array_insert,                                                                                                                    \
        I16Array: i16_array_insert,                                                                                                                  \
        I32Array: i32_array_insert,                                                                                                                  \
        I64Array: i64_array_insert,                                                                                                                  \
        B8Array: b8_array_insert,                                                                                                                    \
        B16Array: b16_array_insert,                                                                                                                  \
        B32Array: b32_array_insert,                                                                                                                  \
        B64Array: b64_array_insert,                                                                                                                  \
        F32Array: f32_array_insert,                                                                                                                  \
        F64Array: f64_array_insert)(&(array), (element), (index))

#define PArrayCanInsert(array)                                                                                                                       \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_can_insert,                                                                                                                \
        U16Array: u16_array_can_insert,                                                                                                              \
        U32Array: u32_array_can_insert,                                                                                                              \
        U64Array: u64_array_can_insert,                                                                                                              \
        I8Array: i8_array_can_insert,                                                                                                                \
        I16Array: i16_array_can_insert,                                                                                                              \
        I32Array: i32_array_can_insert,                                                                                                              \
        I64Array: i64_array_can_insert,                                                                                                              \
        B8Array: b8_array_can_insert,                                                                                                                \
        B16Array: b16_array_can_insert,                                                                                                              \
        B32Array: b32_array_can_insert,                                                                                                              \
        B64Array: b64_array_can_insert,                                                                                                              \
        F32Array: f32_array_can_insert,                                                                                                              \
        F64Array: f64_array_can_insert)(&(array))

#define PArrayRemove(array, index)                                                                                                                   \
    _Generic((array),                                                                                                                                \
        U8Array: u8_array_remove,                                                                                                                    \
        U16Array: u16_array_remove,                                                                                                                  \
        U32Array: u32_array_remove,                                                                                                                  \
        U64Array: u64_array_remove,                                                                                                                  \
        I8Array: i8_array_remove,                                                                                                                    \
        I16Array: i16_array_remove,                                                                                                                  \
        I32Array: i32_array_remove,                                                                                                                  \
        I64Array: i64_array_remove,                                                                                                                  \
        B8Array: b8_array_remove,                                                                                                                    \
        B16Array: b16_array_remove,                                                                                                                  \
        B32Array: b32_array_remove,                                                                                                                  \
        B64Array: b64_array_remove,                                                                                                                  \
        F32Array: f32_array_remove,                                                                                                                  \
        F64Array: f64_array_remove)(&(array), (index))

void* array_make_aligned(Arena* arena, ArrayHeader* header, void** array, u64 capacity, u64 item_size, u64 alignment);
void* array_make(Arena* arena, ArrayHeader* header, void** array, u64 capacity, u64 item_size);
void* array_reserve(Arena* arena, ArrayHeader* header, void* arr, u64 item_size);
void* array_reserve_alignment(Arena* arena, ArrayHeader* header, void* arr, u64 item_size, u64 alignment);
void  array_kill(Arena* arena, ArrayHeader* header, void** array);
void  array_add(ArrayHeader* header, void** array, void* element, u64 item_size);
bool  array_can_add(const ArrayHeader* header);
void  array_clear(ArrayHeader* header, void** array);
void  array_insert(ArrayHeader* header, void** array, void* element, u64 item_size, u64 index);
bool  array_can_insert(const ArrayHeader* header);
void  array_remove(ArrayHeader* header, void** array, u64 item_size, u64 index);

//***** U8Array *****
U8Array u8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
U8Array u8_array_make(Arena* arena, u64 capacity);
void    u8_array_kill(Arena* arena, U8Array* array);
void    u8_array_add(U8Array* array, u8 element);
bool    u8_array_can_add(const U8Array* array);
void    u8_array_clear(U8Array* array);
void    u8_array_insert(U8Array* array, u8 element, u64 index);
bool    u8_array_can_insert(const U8Array* array);
void    u8_array_remove(U8Array* array, u64 index);

//***** U16Array *****
U16Array u16_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
U16Array u16_array_make(Arena* arena, u64 capacity);
void     u16_array_kill(Arena* arena, U16Array* array);
void     u16_array_add(U16Array* array, u16 element);
void     u16_array_can_add(U16Array* array);
void     u16_array_clear(U16Array* array);
void     u16_array_insert(U16Array* array, u16 element, u64 index);
void     u16_array_can_insert(U16Array* array);
void     u16_array_remove(U16Array* array, u64 index);

//***** U32Array *****
U32Array u32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
U32Array u32_array_make(Arena* arena, u64 capacity);
void     u32_array_kill(Arena* arena, U32Array* array);
void     u32_array_add(U32Array* array, u32 element);
void     u32_array_can_add(U32Array* array);
void     u32_array_clear(U32Array* array);
void     u32_array_insert(U32Array* array, u32 element, u64 index);
void     u32_array_can_insert(U32Array* array);
void     u32_array_remove(U32Array* array, u64 index);

//***** U64Array *****
U64Array u64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
U64Array u64_array_make(Arena* arena, u64 capacity);
void     u64_array_kill(Arena* arena, U64Array* array);
void     u64_array_add(U64Array* array, u64 element);
void     u64_array_can_add(U64Array* array);
void     u64_array_clear(U64Array* array);
void     u64_array_insert(U64Array* array, u64 element, u64 index);
void     u64_array_can_insert(U64Array* array);
void     u64_array_remove(U64Array* array, u64 index);

//***** I8Array *****
I8Array i8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
I8Array i8_array_make(Arena* arena, u64 capacity);
void    i8_array_kill(Arena* arena, I8Array* array);
void    i8_array_add(I8Array* array, i8 element);
void    i8_array_can_add(I8Array* array);
void    i8_array_clear(I8Array* array);
void    i8_array_insert(I8Array* array, i8 element, u64 index);
void    i8_array_can_insert(I8Array* array);
void    i8_array_remove(I8Array* array, u64 index);

//***** I16Array *****
I16Array i16_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
I16Array i16_array_make(Arena* arena, u64 capacity);
void     i16_array_kill(Arena* arena, I16Array* array);
void     i16_array_add(I16Array* array, i16 element);
void     i16_array_can_add(I16Array* array);
void     i16_array_clear(I16Array* array);
void     i16_array_insert(I16Array* array, i16 element, u64 index);
void     i16_array_can_insert(I16Array* array);
void     i16_array_remove(I16Array* array, u64 index);

//***** I32Array *****
I32Array i32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
I32Array i32_array_make(Arena* arena, u64 capacity);
void     i32_array_kill(Arena* arena, I32Array* array);
void     i32_array_add(I32Array* array, i32 element);
void     i32_array_can_add(I32Array* array);
void     i32_array_clear(I32Array* array);
void     i32_array_insert(I32Array* array, i32 element, u64 index);
void     i32_array_can_insert(I32Array* array);
void     i32_array_remove(I32Array* array, u64 index);

//***** I64Array *****
I64Array i64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
I64Array i64_array_make(Arena* arena, u64 capacity);
void     i64_array_kill(Arena* arena, I64Array* array);
void     i64_array_add(I64Array* array, i64 element);
void     i64_array_can_add(I64Array* array);
void     i64_array_clear(I64Array* array);
void     i64_array_insert(I64Array* array, i64 element, u64 index);
void     i64_array_can_insert(I64Array* array);
void     i64_array_remove(I64Array* array, u64 index);

//***** B8Array *****
B8Array b8_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
B8Array b8_array_make(Arena* arena, u64 capacity);
void    b8_array_kill(Arena* arena, B8Array* array);
void    b8_array_add(B8Array* array, b8 element);
void    b8_array_can_add(B8Array* array);
void    b8_array_clear(B8Array* array);
void    b8_array_insert(B8Array* array, b8 element, u64 index);
void    b8_array_can_insert(B8Array* array);
void    b8_array_remove(B8Array* array, u64 index);

//***** B16Array *****
B16Array b16_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
B16Array b16_array_make(Arena* arena, u64 capacity);
void     b16_array_kill(Arena* arena, B16Array* array);
void     b16_array_add(B16Array* array, b16 element);
void     b16_array_can_add(B16Array* array);
void     b16_array_clear(B16Array* array);
void     b16_array_insert(B16Array* array, b16 element, u64 index);
void     b16_array_can_insert(B16Array* array);
void     b16_array_remove(B16Array* array, u64 index);

//***** B32Array *****
B32Array b32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
B32Array b32_array_make(Arena* arena, u64 capacity);
void     b32_array_kill(Arena* arena, B32Array* array);
void     b32_array_add(B32Array* array, b32 element);
void     b32_array_can_add(B32Array* array);
void     b32_array_clear(B32Array* array);
void     b32_array_insert(B32Array* array, b32 element, u64 index);
void     b32_array_can_insert(B32Array* array);
void     b32_array_remove(B32Array* array, u64 index);

//***** B64Array *****
B64Array b64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
B64Array b64_array_make(Arena* arena, u64 capacity);
void     b64_array_kill(Arena* arena, B64Array* array);
void     b64_array_add(B64Array* array, b64 element);
void     b64_array_can_add(B64Array* array);
void     b64_array_clear(B64Array* array);
void     b64_array_insert(B64Array* array, b64 element, u64 index);
void     b64_array_can_insert(B64Array* array);
void     b64_array_remove(B64Array* array, u64 index);

//***** F32Array *****
F32Array f32_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
F32Array f32_array_make(Arena* arena, u64 capacity);
void     f32_array_kill(Arena* arena, F32Array* array);
void     f32_array_add(F32Array* array, f32 element);
void     f32_array_can_add(F32Array* array);
void     f32_array_clear(F32Array* array);
void     f32_array_insert(F32Array* array, f32 element, u64 index);
void     f32_array_can_insert(F32Array* array);
void     f32_array_remove(F32Array* array, u64 index);

//***** F64Array *****
F64Array f64_array_make_aligned(Arena* arena, u64 capacity, u64 alignment);
F64Array f64_array_make(Arena* arena, u64 capacity);
void     f64_array_kill(Arena* arena, F64Array* array);
void     f64_array_add(F64Array* array, f64 element);
void     f64_array_can_add(F64Array* array);
void     f64_array_clear(F64Array* array);
void     f64_array_insert(F64Array* array, f64 element, u64 index);
void     f64_array_can_insert(F64Array* array);
void     f64_array_remove(F64Array* array, u64 index);

//***** StrBuf *****

StrBuf str_buf_make(Arena* arena, u64 capacity);                                      // make a string buffer with given capacity
StrBuf str_buf_make_aligned(Arena* arena, u64 capacity, u64 alignment);               // make a string buffer with given capacity and alignment
StrBuf str_buf_make_from_cstr(Arena* arena, const char* str);                         // make a string buffer from c string
StrBuf str_buf_make_aligned_from_cstr(Arena* arena, const char* str, u64 alignment);  // make a string buffer from c string with given alignment
void   str_buf_kill(Arena* arena, StrBuf* str_buf);                                   // kill string buffer
bool   str_buf_append(StrBuf* str_buf, const char* str);                              // append c string to str_buf
bool   str_buf_append_formatted(Arena* arena, StrBuf* str_buf, const char* str, ...); // append formatted string to str_buf
bool   str_buf_empty(const StrBuf* str_buf);                                          // check if string is empty
u64    str_buf_len(const StrBuf* str_buf);                                            // string length
u64    str_buf_capacity(const StrBuf* str_buf);                                       // string capacity
i64    str_buf_cmp(const StrBuf* left, Str right);                                    // compare left and right string
i64    str_buf_cmp_n(const StrBuf* left, Str right, u64 n);                           // compare left and right string upto n chars
i64    str_buf_find_char(const StrBuf* str_buf, char ch);                             // return position of first char , otherwise -1
i64    str_buf_find_char_reverse(const StrBuf* str_buf, char ch);                     // return position of last char, otherwise -1
bool   str_buf_contain_char(const StrBuf* str_buf, char ch);                          // contains ch in str
bool   str_buf_contain_str(const StrBuf* str_buf, Str pattern);                       // contains pattern in str
bool   str_buf_start_with(const StrBuf* str_buf, Str pattern);                        // str_buf start with pattern
bool   str_buf_end_with(const StrBuf* str_buf, Str pattern);                          // str_buf end with pattern
Str    str_buf_substr(const StrBuf* str_buf, u64 index, u64 len);                     // return substring of length len starting at index
Str    str_buf_strip_prefix(const StrBuf* str_buf, Str prefix);                       // remove prefix from str
Str    str_buf_strip_prefix_char(const StrBuf* str_buf, char ch);                     // removes ch prefix from str
Str    str_buf_strip_suffix(const StrBuf* str_buf, Str suffix);                       // remove suffix from str
Str    str_buf_strip_suffix_char(const StrBuf* str_buf, char ch);                     // removes ch suffix from str
Str    str_buf_strip(const StrBuf* str_buf, Str pattern);                             // remove prefix and suffix pattern from str
Str    str_buf_strip_char(const StrBuf* str_buf, char ch);                            // remove prefix and suffix char from str
StrBuf str_buf_copy(Arena* arena, const StrBuf* str_buf);                             // make a copy of str but in given arena
void   str_buf_lowercase(StrBuf* str_buf);                                            // change to lowercase but in parent arena
void   str_buf_uppercase(StrBuf* str_buf);                                            // change to uppercase but in given arena

//***** Str *****
/* String view (All function are immutable unless user modifies buffer) */

inline bool str_empty(Str str);                      // check if string is empty
inline u64  str_len(Str str);                        // string length
inline char str_at(Str str, u64 at);                 // string length
char*       str_to_cstr(Str str);                    // convert str to c string, caller must free the memory
i64         str_cmp(Str left, Str right);            // compare left and right string
i64         str_cmp_n(Str left, Str right, u64 n);   // compare upto min(n, left length, right length) chars
i64         str_find_char(Str str, char ch);         // return position of first char , otherwise -1
i64         str_find_char_reverse(Str str, char ch); // return position of last char, otherwise -1
inline bool str_contain_char(Str str, char ch);      // contains ch in str
bool        str_contain_str(Str str, Str pattern);   // contains pattern in str
bool        str_start_with(Str str, Str pattern);    // str start with pattern ?
bool        str_end_with(Str str, Str pattern);      // str end with pattern ?
Str         str_substr(Str str, u64 index, u64 len); // return substring of length len starting at index
Str         str_copy(Str str);                       // clone str
StrBuf      str_copy_deep(Arena* arena, Str str);    // make a copy of underlying str but in given arena
Str         str_strip_prefix(Str str, Str prefix);   // remove prefix from str
Str         str_strip_suffix(Str str, Str suffix);   // remove suffix from str
inline Str  str_strip(Str str, Str pattern);         // remove prefix and suffix pattern from str
Str         str_strip_prefix_char(Str str, char ch); // removes ch prefix from str
Str         str_strip_suffix_char(Str str, char ch); // removes ch suffix from str
Str         str_strip_char(Str str, char ch);        // remove prefix and suffix char from str

#endif
