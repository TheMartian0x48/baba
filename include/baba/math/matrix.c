#include "../memory/memory.h"
#include "math.h"
#include <assert.h>

//***** Matrix 2x2 i32 Implementation *****
inline Matrix2i32* matrix_2i32_make(Arena* arena) { return (Matrix2i32*)arena_alloc(arena, sizeof(i32) * 4, DEFAULT_ALIGNMENT); }

inline Matrix2i32* matrix_2i32_make_aligned(Arena* arena, u64 alignment) { return (Matrix2i32*)arena_alloc(arena, sizeof(i32) * 4, alignment); }

inline void matrix_2i32_kill(Arena* arena, Matrix2i32* matrix) { arena_dealloc(arena, matrix); }

inline void matrix_2i32_identity(Matrix2i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1;
    matrix->x01 = 0;
    matrix->x10 = 0;
    matrix->x11 = 1;
}

inline void matrix_2i32_zero(Matrix2i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0;
    matrix->x01 = 0;
    matrix->x10 = 0;
    matrix->x11 = 0;
}

inline void matrix_2i32_add(Matrix2i32* a, Matrix2i32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x10 += b->x10;
    a->x11 += b->x11;
}

inline void matrix_2i32_subtract(Matrix2i32* a, Matrix2i32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
}

inline void matrix_2i32_scale(Matrix2i32* a, i32 s)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x10 *= s;
    a->x11 *= s;
}

inline void matrix_2i32_multiply(Matrix2i32* a, Matrix2i32* b, Matrix2i32* result)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10;
    result->x11 = a->x10 * b->x00 + a->x11 * b->x10;
}

inline void matrix_2i32_copy(Matrix2i32* a, Matrix2i32* result)
{
    assert(a && "matrix a cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x10 = a->x10;
    result->x11 = a->x11;
}

//***** Matrix 2x2 f32 Implementation *****

inline Matrix2f32* matrix_2f32_make(Arena* arena) { return (Matrix2f32*)arena_alloc(arena, sizeof(f32) * 4, DEFAULT_ALIGNMENT); }

inline Matrix2f32* matrix_2f32_make_aligned(Arena* arena, u64 alignment) { return (Matrix2f32*)arena_alloc(arena, sizeof(f32) * 4, alignment); }

inline void matrix_2f32_kill(Arena* arena, Matrix2f32* matrix) { arena_dealloc(arena, matrix); }

inline void matrix_2f32_identity(Matrix2f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1.0f;
    matrix->x01 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 1.0f;
}

inline void matrix_2f32_zero(Matrix2f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0.0f;
    matrix->x01 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 0.0f;
}

inline void matrix_2f32_add(Matrix2f32* a, Matrix2f32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x10 += b->x10;
    a->x11 += b->x11;
}

inline void matrix_2f32_subtract(Matrix2f32* a, Matrix2f32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
}

inline void matrix_2f32_scale(Matrix2f32* a, f32 s)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x10 *= s;
    a->x11 *= s;
}

inline void matrix_2f32_multiply(Matrix2f32* a, Matrix2f32* b, Matrix2f32* result)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10;
    result->x11 = a->x10 * b->x00 + a->x11 * b->x10;
}

inline void matrix_2f32_copy(Matrix2f32* a, Matrix2f32* result)
{
    assert(a && "matrix a cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x10 = a->x10;
    result->x11 = a->x11;
}

//***** Matrix 3x3 i32 Implementation *****

inline Matrix3i32* matrix_3i32_make(Arena* arena) { return (Matrix3i32*)arena_alloc(arena, sizeof(i32) * 9, DEFAULT_ALIGNMENT); }

inline Matrix3i32* matrix_3i32_make_aligned(Arena* arena, u64 alignment) { return (Matrix3i32*)arena_alloc(arena, sizeof(i32) * 9, alignment); }

inline void matrix_3i32_kill(Arena* arena, Matrix3i32* matrix) { arena_dealloc(arena, matrix); }

inline void matrix_3i32_identity(Matrix3i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1;
    matrix->x01 = 0;
    matrix->x02 = 0;
    matrix->x10 = 0;
    matrix->x11 = 1;
    matrix->x12 = 0;
    matrix->x20 = 0;
    matrix->x21 = 0;
    matrix->x22 = 1;
}
inline void matrix_3i32_zero(Matrix3i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0;
    matrix->x01 = 0;
    matrix->x02 = 0;
    matrix->x10 = 0;
    matrix->x11 = 0;
    matrix->x12 = 0;
    matrix->x20 = 0;
    matrix->x21 = 0;
    matrix->x22 = 0;
}

inline void matrix_3i32_add(Matrix3i32* a, Matrix3i32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x02 += b->x02;
    a->x10 += b->x10;
    a->x11 += b->x11;
    a->x12 += b->x12;
    a->x20 += b->x20;
    a->x21 += b->x21;
    a->x22 += b->x22;
}

inline void matrix_3i32_subtract(Matrix3i32* a, Matrix3i32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x02 -= b->x02;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
    a->x12 -= b->x12;
    a->x20 -= b->x20;
    a->x21 -= b->x21;
    a->x22 -= b->x22;
}

inline void matrix_3i32_scale(Matrix3i32* a, i32 s)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x02 *= s;
    a->x10 *= s;
    a->x11 *= s;
    a->x12 *= s;
    a->x20 *= s;
    a->x21 *= s;
    a->x22 *= s;
}

inline void matrix_3i32_multiply(Matrix3i32* a, Matrix3i32* b, Matrix3i32* result)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10 + a->x02 * b->x20;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11 + a->x02 * b->x21;
    result->x02 = a->x00 * b->x02 + a->x01 * b->x12 + a->x02 * b->x22;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10 + a->x12 * b->x20;
    result->x11 = a->x10 * b->x01 + a->x11 * b->x11 + a->x12 * b->x21;
    result->x12 = a->x10 * b->x02 + a->x11 * b->x12 + a->x12 * b->x22;
    result->x20 = a->x20 * b->x00 + a->x21 * b->x10 + a->x22 * b->x20;
    result->x21 = a->x20 * b->x01 + a->x21 * b->x11 + a->x22 * b->x21;
    result->x22 = a->x20 * b->x02 + a->x21 * b->x12 + a->x22 * b->x22;
}

inline void matrix_3i32_copy(Matrix3i32* a, Matrix3i32* result)
{
    assert(a && "matrix a cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x02 = a->x02;
    result->x10 = a->x10;
    result->x11 = a->x11;
    result->x12 = a->x12;
    result->x20 = a->x20;
    result->x21 = a->x21;
    result->x22 = a->x22;
}

//***** Matrix 3x3 f32 Implementation *****

inline Matrix3f32* matrix_3f32_make(Arena* arena) { return (Matrix3f32*)arena_alloc(arena, sizeof(f32) * 9, DEFAULT_ALIGNMENT); }

inline Matrix3f32* matrix_3f32_make_aligned(Arena* arena, u64 alignment) { return (Matrix3f32*)arena_alloc(arena, sizeof(f32) * 9, alignment); }

inline void matrix_3f32_kill(Arena* arena, Matrix3f32* matrix) { arena_dealloc(arena, matrix); }

inline void matrix_3f32_identity(Matrix3f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1.0f;
    matrix->x01 = 0.0f;
    matrix->x02 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 1.0f;
    matrix->x12 = 0.0f;
    matrix->x20 = 0.0f;
    matrix->x21 = 0.0f;
    matrix->x22 = 1.0f;
}
inline void matrix_3f32_zero(Matrix3f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0.0f;
    matrix->x01 = 0.0f;
    matrix->x02 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 0.0f;
    matrix->x12 = 0.0f;
    matrix->x20 = 0.0f;
    matrix->x21 = 0.0f;
    matrix->x22 = 0.0f;
}

inline void matrix_3f32_add(Matrix3f32* a, Matrix3f32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x02 += b->x02;
    a->x10 += b->x10;
    a->x11 += b->x11;
    a->x12 += b->x12;
    a->x20 += b->x20;
    a->x21 += b->x21;
    a->x22 += b->x22;
}

inline void matrix_3f32_subtract(Matrix3f32* a, Matrix3f32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x02 -= b->x02;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
    a->x12 -= b->x12;
    a->x20 -= b->x20;
    a->x21 -= b->x21;
    a->x22 -= b->x22;
}

inline void matrix_3f32_scale(Matrix3f32* a, f32 s)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x02 *= s;
    a->x10 *= s;
    a->x11 *= s;
    a->x12 *= s;
    a->x20 *= s;
    a->x21 *= s;
    a->x22 *= s;
}

inline void matrix_3f32_multiply(Matrix3f32* a, Matrix3f32* b, Matrix3f32* result)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10 + a->x02 * b->x20;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11 + a->x02 * b->x21;
    result->x02 = a->x00 * b->x02 + a->x01 * b->x12 + a->x02 * b->x22;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10 + a->x12 * b->x20;
    result->x11 = a->x10 * b->x01 + a->x11 * b->x11 + a->x12 * b->x21;
    result->x12 = a->x10 * b->x02 + a->x11 * b->x12 + a->x12 * b->x22;
    result->x20 = a->x20 * b->x00 + a->x21 * b->x10 + a->x22 * b->x20;
    result->x21 = a->x20 * b->x01 + a->x21 * b->x11 + a->x22 * b->x21;
    result->x22 = a->x20 * b->x02 + a->x21 * b->x12 + a->x22 * b->x22;
}

inline void matrix_3f32_copy(Matrix3f32* a, Matrix3f32* result)
{
    assert(a && "matrix a cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x02 = a->x02;
    result->x10 = a->x10;
    result->x11 = a->x11;
    result->x12 = a->x12;
    result->x20 = a->x20;
    result->x21 = a->x21;
    result->x22 = a->x22;
}

//***** Matrix 4x4 i32 Implementation *****

inline Matrix4i32* matrix_4i32_make(Arena* arena) { return (Matrix4i32*)arena_alloc(arena, sizeof(i32) * 16, DEFAULT_ALIGNMENT); }

inline Matrix4i32* matrix_4i32_make_aligned(Arena* arena, u64 alignment) { return (Matrix4i32*)arena_alloc(arena, sizeof(i32) * 16, alignment); }

inline void matrix_4i32_kill(Arena* arena, Matrix4i32* matrix) { arena_dealloc(arena, matrix); }

inline void matrix_4i32_identity(Matrix4i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1.0;
    matrix->x01 = 0.0;
    matrix->x02 = 0.0;
    matrix->x03 = 0.0;
    matrix->x10 = 0.0;
    matrix->x11 = 1.0;
    matrix->x12 = 0.0;
    matrix->x13 = 0.0;
    matrix->x20 = 0.0;
    matrix->x21 = 0.0;
    matrix->x22 = 1.0;
    matrix->x23 = 0.0;
    matrix->x30 = 0.0;
    matrix->x31 = 0.0;
    matrix->x32 = 0.0;
    matrix->x33 = 1.0;
}

inline void matrix_4i32_zero(Matrix4i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0.0;
    matrix->x01 = 0.0;
    matrix->x02 = 0.0;
    matrix->x03 = 0.0;
    matrix->x10 = 0.0;
    matrix->x11 = 0.0;
    matrix->x12 = 0.0;
    matrix->x13 = 0.0;
    matrix->x20 = 0.0;
    matrix->x21 = 0.0;
    matrix->x22 = 0.0;
    matrix->x23 = 0.0;
    matrix->x30 = 0.0;
    matrix->x31 = 0.0;
    matrix->x32 = 0.0;
    matrix->x33 = 0.0;
}

inline void matrix_4i32_add(Matrix4i32* a, Matrix4i32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x02 += b->x02;
    a->x03 += b->x03;
    a->x10 += b->x10;
    a->x11 += b->x11;
    a->x12 += b->x12;
    a->x13 += b->x13;
    a->x20 += b->x20;
    a->x21 += b->x21;
    a->x22 += b->x22;
    a->x23 += b->x23;
    a->x30 += b->x30;
    a->x31 += b->x31;
    a->x32 += b->x32;
    a->x33 += b->x33;
}

inline void matrix_4i32_subtract(Matrix4i32* a, Matrix4i32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x02 -= b->x02;
    a->x03 -= b->x03;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
    a->x12 -= b->x12;
    a->x13 -= b->x13;
    a->x20 -= b->x20;
    a->x21 -= b->x21;
    a->x22 -= b->x22;
    a->x23 -= b->x23;
    a->x30 -= b->x30;
    a->x31 -= b->x31;
    a->x32 -= b->x32;
    a->x33 -= b->x33;
}

inline void matrix_4i32_scale(Matrix4i32* a, i32 s)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x02 *= s;
    a->x03 *= s;
    a->x10 *= s;
    a->x11 *= s;
    a->x12 *= s;
    a->x13 *= s;
    a->x20 *= s;
    a->x21 *= s;
    a->x22 *= s;
    a->x23 *= s;
    a->x30 *= s;
    a->x31 *= s;
    a->x32 *= s;
    a->x33 *= s;
}

inline void matrix_4i32_multiply(Matrix4i32* a, Matrix4i32* b, Matrix4i32* result)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10 + a->x02 * b->x20 + a->x03 * b->x30;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11 + a->x02 * b->x21 + a->x03 * b->x31;
    result->x02 = a->x00 * b->x02 + a->x01 * b->x12 + a->x02 * b->x22 + a->x03 * b->x32;
    result->x03 = a->x00 * b->x03 + a->x01 * b->x13 + a->x02 * b->x23 + a->x03 * b->x33;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10 + a->x12 * b->x20 + a->x13 * b->x30;
    result->x11 = a->x10 * b->x01 + a->x11 * b->x11 + a->x12 * b->x21 + a->x13 * b->x31;
    result->x12 = a->x10 * b->x02 + a->x11 * b->x12 + a->x12 * b->x22 + a->x13 * b->x32;
    result->x13 = a->x10 * b->x03 + a->x11 * b->x13 + a->x12 * b->x23 + a->x13 * b->x33;
    result->x20 = a->x20 * b->x00 + a->x21 * b->x10 + a->x22 * b->x20 + a->x23 * b->x30;
    result->x21 = a->x20 * b->x01 + a->x21 * b->x11 + a->x22 * b->x21 + a->x23 * b->x31;
    result->x22 = a->x20 * b->x02 + a->x21 * b->x12 + a->x22 * b->x22 + a->x23 * b->x32;
    result->x23 = a->x20 * b->x03 + a->x21 * b->x13 + a->x22 * b->x23 + a->x23 * b->x33;
    result->x30 = a->x30 * b->x00 + a->x31 * b->x10 + a->x32 * b->x20 + a->x33 * b->x30;
    result->x31 = a->x30 * b->x01 + a->x31 * b->x11 + a->x32 * b->x21 + a->x33 * b->x31;
    result->x32 = a->x30 * b->x02 + a->x31 * b->x12 + a->x32 * b->x22 + a->x33 * b->x32;
    result->x33 = a->x30 * b->x03 + a->x31 * b->x13 + a->x32 * b->x23 + a->x33 * b->x33;
}

inline void matrix_4i32_copy(Matrix4i32* a, Matrix4i32* result)
{
    assert(a && "matrix a cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x02 = a->x02;
    result->x03 = a->x03;
    result->x10 = a->x10;
    result->x11 = a->x11;
    result->x12 = a->x12;
    result->x13 = a->x13;
    result->x20 = a->x20;
    result->x21 = a->x21;
    result->x22 = a->x22;
    result->x23 = a->x23;
    result->x30 = a->x30;
    result->x31 = a->x31;
    result->x32 = a->x32;
    result->x33 = a->x33;
}

//***** Matrix 4x4 f32 Implementation *****

inline Matrix4f32* matrix_4f32_make(Arena* arena) { return (Matrix4f32*)arena_alloc(arena, sizeof(f32) * 16, DEFAULT_ALIGNMENT); }

inline Matrix4f32* matrix_4f32_make_aligned(Arena* arena, u64 alignment) { return (Matrix4f32*)arena_alloc(arena, sizeof(f32) * 16, alignment); }

inline void matrix_4f32_kill(Arena* arena, Matrix4f32* matrix) { arena_dealloc(arena, matrix); }

inline void matrix_4f32_identity(Matrix4f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1.0f;
    matrix->x01 = 0.0f;
    matrix->x02 = 0.0f;
    matrix->x03 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 1.0f;
    matrix->x12 = 0.0f;
    matrix->x13 = 0.0f;
    matrix->x20 = 0.0f;
    matrix->x21 = 0.0f;
    matrix->x22 = 1.0f;
    matrix->x23 = 0.0f;
    matrix->x30 = 0.0f;
    matrix->x31 = 0.0f;
    matrix->x32 = 0.0f;
    matrix->x33 = 1.0f;
}

inline void matrix_4f32_zero(Matrix4f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0.0f;
    matrix->x01 = 0.0f;
    matrix->x02 = 0.0f;
    matrix->x03 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 0.0f;
    matrix->x12 = 0.0f;
    matrix->x13 = 0.0f;
    matrix->x20 = 0.0f;
    matrix->x21 = 0.0f;
    matrix->x22 = 0.0f;
    matrix->x23 = 0.0f;
    matrix->x30 = 0.0f;
    matrix->x31 = 0.0f;
    matrix->x32 = 0.0f;
    matrix->x33 = 0.0f;
}

inline void matrix_4f32_add(Matrix4f32* a, Matrix4f32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x02 += b->x02;
    a->x03 += b->x03;
    a->x10 += b->x10;
    a->x11 += b->x11;
    a->x12 += b->x12;
    a->x13 += b->x13;
    a->x20 += b->x20;
    a->x21 += b->x21;
    a->x22 += b->x22;
    a->x23 += b->x23;
    a->x30 += b->x30;
    a->x31 += b->x31;
    a->x32 += b->x32;
    a->x33 += b->x33;
}

inline void matrix_4f32_subtract(Matrix4f32* a, Matrix4f32* b)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x02 -= b->x02;
    a->x03 -= b->x03;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
    a->x12 -= b->x12;
    a->x13 -= b->x13;
    a->x20 -= b->x20;
    a->x21 -= b->x21;
    a->x22 -= b->x22;
    a->x23 -= b->x23;
    a->x30 -= b->x30;
    a->x31 -= b->x31;
    a->x32 -= b->x32;
    a->x33 -= b->x33;
}

inline void matrix_4f32_scale(Matrix4f32* a, f32 s)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x02 *= s;
    a->x03 *= s;
    a->x10 *= s;
    a->x11 *= s;
    a->x12 *= s;
    a->x13 *= s;
    a->x20 *= s;
    a->x21 *= s;
    a->x22 *= s;
    a->x23 *= s;
    a->x30 *= s;
    a->x31 *= s;
    a->x32 *= s;
    a->x33 *= s;
}

inline void matrix_4f32_multiply(Matrix4f32* a, Matrix4f32* b, Matrix4f32* result)
{
    assert(a && "matrix a cannot be null");
    assert(b && "matrix b cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10 + a->x02 * b->x20 + a->x03 * b->x30;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11 + a->x02 * b->x21 + a->x03 * b->x31;
    result->x02 = a->x00 * b->x02 + a->x01 * b->x12 + a->x02 * b->x22 + a->x03 * b->x32;
    result->x03 = a->x00 * b->x03 + a->x01 * b->x13 + a->x02 * b->x23 + a->x03 * b->x33;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10 + a->x12 * b->x20 + a->x13 * b->x30;
    result->x11 = a->x10 * b->x01 + a->x11 * b->x11 + a->x12 * b->x21 + a->x13 * b->x31;
    result->x12 = a->x10 * b->x02 + a->x11 * b->x12 + a->x12 * b->x22 + a->x13 * b->x32;
    result->x13 = a->x10 * b->x03 + a->x11 * b->x13 + a->x12 * b->x23 + a->x13 * b->x33;
    result->x20 = a->x20 * b->x00 + a->x21 * b->x10 + a->x22 * b->x20 + a->x23 * b->x30;
    result->x21 = a->x20 * b->x01 + a->x21 * b->x11 + a->x22 * b->x21 + a->x23 * b->x31;
    result->x22 = a->x20 * b->x02 + a->x21 * b->x12 + a->x22 * b->x22 + a->x23 * b->x32;
    result->x23 = a->x20 * b->x03 + a->x21 * b->x13 + a->x22 * b->x23 + a->x23 * b->x33;
    result->x30 = a->x30 * b->x00 + a->x31 * b->x10 + a->x32 * b->x20 + a->x33 * b->x30;
    result->x31 = a->x30 * b->x01 + a->x31 * b->x11 + a->x32 * b->x21 + a->x33 * b->x31;
    result->x32 = a->x30 * b->x02 + a->x31 * b->x12 + a->x32 * b->x22 + a->x33 * b->x32;
    result->x33 = a->x30 * b->x03 + a->x31 * b->x13 + a->x32 * b->x23 + a->x33 * b->x33;
}

inline void matrix_4f32_copy(Matrix4f32* a, Matrix4f32* result)
{
    assert(a && "matrix a cannot be null");
    assert(result && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x02 = a->x02;
    result->x03 = a->x03;
    result->x10 = a->x10;
    result->x11 = a->x11;
    result->x12 = a->x12;
    result->x13 = a->x13;
    result->x20 = a->x20;
    result->x21 = a->x21;
    result->x22 = a->x22;
    result->x23 = a->x23;
    result->x30 = a->x30;
    result->x31 = a->x31;
    result->x32 = a->x32;
    result->x33 = a->x33;
}
