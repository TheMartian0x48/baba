#include "../memory/memory.h"
#include "math.h"
#include <assert.h>

//***** Matrix 2x2 i32 Implementation *****
inline Matrix2i* matrix2i_make(const Arena* arena) { return (Matrix2i*)arena_alloc(arena, sizeof(i32) * 4, DEFAULT_ALIGNMENT); }

inline Matrix2i* matrix2i_make_aligned(const Arena* arena, u64 alignment) { return (Matrix2i*)arena_alloc(arena, sizeof(i32) * 4, alignment); }

inline void matrix2i_kill(const Arena* arena, Matrix2i* matrix) { arena_dealloc(arena, matrix); }

inline void matrix2i_identity(Matrix2i* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
    matrix->x00 = 1;
    matrix->x01 = 0;
    matrix->x10 = 0;
    matrix->x11 = 1;
}

inline void matrix2i_zero(Matrix2i* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
    matrix->x00 = 0;
    matrix->x01 = 0;
    matrix->x10 = 0;
    matrix->x11 = 0;
}

inline void matrix2i_add(Matrix2i* a, const Matrix2i* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x10 += b->x10;
    a->x11 += b->x11;
}

inline void matrix2i_subtract(Matrix2i* a, const Matrix2i* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
}

inline void matrix2i_scale(Matrix2i* a, i32 s)
{
    assert(a != nullptr && "matrix a cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x10 *= s;
    a->x11 *= s;
}

inline void matrix2i_multiply(const Matrix2i* a, const Matrix2i* b, Matrix2i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10;
    result->x11 = a->x10 * b->x00 + a->x11 * b->x10;
}

inline void matrix2i_copy(const Matrix2i* a, Matrix2i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x10 = a->x10;
    result->x11 = a->x11;
}

void matrix2i_print(const Matrix2i* a, FILE* stream)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(stream != nullptr && "stream cannot be null");
    fprintf(stream, "{\n{%d, %d},\n {%d, %d}\n}\n", a->x00, a->x01, a->x10, a->x11);
}

//***** Matrix 2x2 f32 Implementation *****

inline Matrix2f* matrix2f_make(const Arena* arena) { return (Matrix2f*)arena_alloc(arena, sizeof(f32) * 4, DEFAULT_ALIGNMENT); }

inline Matrix2f* matrix2f_make_aligned(const Arena* arena, u64 alignment) { return (Matrix2f*)arena_alloc(arena, sizeof(f32) * 4, alignment); }

inline void matrix2f_kill(const Arena* arena, Matrix2f* matrix) { arena_dealloc(arena, matrix); }

inline void matrix2f_identity(Matrix2f* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
    matrix->x00 = 1.0f;
    matrix->x01 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 1.0f;
}

inline void matrix2f_zero(Matrix2f* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
    matrix->x00 = 0.0f;
    matrix->x01 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 0.0f;
}

inline void matrix2f_add(Matrix2f* a, const Matrix2f* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    a->x00 += b->x00;
    a->x01 += b->x01;
    a->x10 += b->x10;
    a->x11 += b->x11;
}

inline void matrix2f_subtract(Matrix2f* a, const Matrix2f* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    a->x00 -= b->x00;
    a->x01 -= b->x01;
    a->x10 -= b->x10;
    a->x11 -= b->x11;
}

inline void matrix2f_scale(Matrix2f* a, f32 s)
{
    assert(a != nullptr && "matrix a cannot be null");
    a->x00 *= s;
    a->x01 *= s;
    a->x10 *= s;
    a->x11 *= s;
}

inline void matrix2f_multiply(const Matrix2f* a, const Matrix2f* b, Matrix2f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * b->x00 + a->x01 * b->x10;
    result->x01 = a->x00 * b->x01 + a->x01 * b->x11;
    result->x10 = a->x10 * b->x00 + a->x11 * b->x10;
    result->x11 = a->x10 * b->x00 + a->x11 * b->x10;
}

inline void matrix2f_copy(const Matrix2f* a, Matrix2f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00;
    result->x01 = a->x01;
    result->x10 = a->x10;
    result->x11 = a->x11;
}

void matrix2f_print(const Matrix2f* a, FILE* stream)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(stream != nullptr && "stream cannot be null");
    fprintf(stream, "{\n{%10.6f, %10.6f},\n {%10.6f, %10.6f}\n}\n", a->x00, a->x01, a->x10, a->x11);
}

//***** Matrix 3x3 i32 Implementation *****

inline Matrix3i* matrix3i_make(const Arena* arena) { return (Matrix3i*)arena_alloc(arena, sizeof(i32) * 9, DEFAULT_ALIGNMENT); }

inline Matrix3i* matrix3i_make_aligned(const Arena* arena, u64 alignment) { return (Matrix3i*)arena_alloc(arena, sizeof(i32) * 9, alignment); }

inline void matrix3i_kill(const Arena* arena, Matrix3i* matrix) { arena_dealloc(arena, matrix); }

inline void matrix3i_identity(Matrix3i* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
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

inline void matrix3i_zero(Matrix3i* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
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

inline void matrix3i_add(Matrix3i* a, const Matrix3i* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix3i_subtract(Matrix3i* a, const Matrix3i* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix3i_scale(Matrix3i* a, i32 s)
{
    assert(a != nullptr && "matrix a cannot be null");
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

inline void matrix3i_multiply(const Matrix3i* a, const Matrix3i* b, Matrix3i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

inline void matrix3i_copy(const Matrix3i* a, Matrix3i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

void matrix3i_print(const Matrix3i* a, FILE* stream)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(stream != nullptr && "stream cannot be null");
    fprintf(stream, "{\n{%d, %d, %d},\n {%d, %d, %d},\n {%d, %d, %d}\n}\n", a->x00, a->x01, a->x02, a->x10, a->x11, a->x12, a->x20, a->x21, a->x22);
}

//***** Matrix 3x3 f32 Implementation *****

inline Matrix3f* matrix3f_make(const Arena* arena) { return (Matrix3f*)arena_alloc(arena, sizeof(f32) * 9, DEFAULT_ALIGNMENT); }

inline Matrix3f* matrix3f_make_aligned(const Arena* arena, u64 alignment) { return (Matrix3f*)arena_alloc(arena, sizeof(f32) * 9, alignment); }

inline void matrix3f_kill(const Arena* arena, Matrix3f* matrix) { arena_dealloc(arena, matrix); }

inline void matrix3f_identity(Matrix3f* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
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
inline void matrix3f_zero(Matrix3f* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
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

inline void matrix3f_add(Matrix3f* a, const Matrix3f* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix3f_subtract(Matrix3f* a, const Matrix3f* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix3f_scale(Matrix3f* a, f32 s)
{
    assert(a != nullptr && "matrix a cannot be null");
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

inline void matrix3f_multiply(const Matrix3f* a, const Matrix3f* b, Matrix3f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

inline void matrix3f_copy(const Matrix3f* a, Matrix3f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

void matrix3f_print(const Matrix3f* a, FILE* stream)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(stream != nullptr && "stream cannot be null");
    fprintf(stream, "{\n{%10.6f, %10.6f, %10.6f},\n {%10.6f, %10.6f, %10.6f},\n {%10.6f, %10.6f, %10.6f}\n}\n", a->x00, a->x01, a->x02, a->x10,
        a->x11, a->x12, a->x20, a->x21, a->x22);
}

//***** Matrix 4x4 i32 Implementation *****

inline Matrix4i* matrix4i_make(const Arena* arena) { return (Matrix4i*)arena_alloc(arena, sizeof(i32) * 16, DEFAULT_ALIGNMENT); }

inline Matrix4i* matrix4i_make_aligned(const Arena* arena, u64 alignment) { return (Matrix4i*)arena_alloc(arena, sizeof(i32) * 16, alignment); }

inline void matrix4i_kill(const Arena* arena, Matrix4i* matrix) { arena_dealloc(arena, matrix); }

inline void matrix4i_identity(Matrix4i* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
    matrix->x00 = 1;
    matrix->x01 = 0;
    matrix->x02 = 0;
    matrix->x03 = 0;
    matrix->x10 = 0;
    matrix->x11 = 1;
    matrix->x12 = 0;
    matrix->x13 = 0;
    matrix->x20 = 0;
    matrix->x21 = 0;
    matrix->x22 = 1;
    matrix->x23 = 0;
    matrix->x30 = 0;
    matrix->x31 = 0;
    matrix->x32 = 0;
    matrix->x33 = 1;
}

inline void matrix4i_zero(Matrix4i* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
    matrix->x00 = 0;
    matrix->x01 = 0;
    matrix->x02 = 0;
    matrix->x03 = 0;
    matrix->x10 = 0;
    matrix->x11 = 0;
    matrix->x12 = 0;
    matrix->x13 = 0;
    matrix->x20 = 0;
    matrix->x21 = 0;
    matrix->x22 = 0;
    matrix->x23 = 0;
    matrix->x30 = 0;
    matrix->x31 = 0;
    matrix->x32 = 0;
    matrix->x33 = 0;
}

inline void matrix4i_add(Matrix4i* a, const Matrix4i* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix4i_subtract(Matrix4i* a, const Matrix4i* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix4i_scale(Matrix4i* a, i32 s)
{
    assert(a != nullptr && "matrix a cannot be null");
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

inline void matrix4i_multiply(const Matrix4i* a, const Matrix4i* b, Matrix4i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

inline void matrix4i_copy(const Matrix4i* a, Matrix4i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

void matrix4i_print(const Matrix4i* a, FILE* stream)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(stream != nullptr && "stream cannot be null");
    fprintf(stream, "{\n{%d, %d, %d, %d},\n {%d, %d, %d, %d},\n {%d, %d, %d, %d},\n {%d, %d, %d, %d}\n}\n", a->x00, a->x01, a->x02, a->x03, a->x10,
        a->x11, a->x12, a->x13, a->x20, a->x21, a->x22, a->x23, a->x30, a->x31, a->x32, a->x33);
}

//***** Matrix 4x4 f32 Implementation *****

inline Matrix4f* matrix4f_make(const Arena* arena) { return (Matrix4f*)arena_alloc(arena, sizeof(f32) * 16, DEFAULT_ALIGNMENT); }

inline Matrix4f* matrix4f_make_aligned(const Arena* arena, u64 alignment) { return (Matrix4f*)arena_alloc(arena, sizeof(f32) * 16, alignment); }

inline void matrix4f_kill(const Arena* arena, Matrix4f* matrix) { arena_dealloc(arena, matrix); }

inline void matrix4f_identity(Matrix4f* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
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

inline void matrix4f_zero(Matrix4f* matrix)
{
    assert(matrix != nullptr && "matrix cannot be null");
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

inline void matrix4f_add(Matrix4f* a, const Matrix4f* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix4f_subtract(Matrix4f* a, const Matrix4f* b)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
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

inline void matrix4f_scale(Matrix4f* a, f32 s)
{
    assert(a != nullptr && "matrix a cannot be null");
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

inline void matrix4f_multiply(const Matrix4f* a, const Matrix4f* b, Matrix4f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

inline void matrix4f_copy(const Matrix4f* a, Matrix4f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
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

void matrix4f_print(const Matrix4f* a, FILE* stream)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(stream != nullptr && "stream cannot be null");
    fprintf(stream,
        "{\n{%10.6f, %10.6f, %10.6f, %10.6f},\n {%10.6f, %10.6f, %10.6f, %10.6f},\n {%10.6f, %10.6f, %10.6f, %10.6f},\n {%10.6f, %10.6f, %10.6f, "
        "%10.6f}\n}\n",
        a->x00, a->x01, a->x02, a->x03, a->x10, a->x11, a->x12, a->x13, a->x20, a->x21, a->x22, a->x23, a->x30, a->x31, a->x32, a->x33);
}

void matrix4f_perspective(Matrix4f* m, f32 fov, f32 aspect, f32 near, f32 far)
{
    mem_set(m->v, 0, 16);
    f32 f  = 1.0f / tan_(fov / 2);
    m->x00 = f / aspect;
    m->x11 = f;
    m->x22 = (far + near) / (near - far);
    m->x23 = 2 * far * near / (near - far);
    m->x32 = -1;
}

void matrix4f_orthographic(Matrix4f* m, f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far)
{
    mem_set(m->mat, 0, 16);
    m->x00 = 2.0f / (right - left);
    m->x11 = 2.0f / (top - bottom);
    m->x22 = -2.0f / (far - near);
    m->x33 = 1.0f;

    m->x03 = -(right + left) / (right - left);
    m->x13 = -(top + bottom) / (top - bottom);
    m->x23 = -(far + near) / (far - near);
}

void matrix4f_translate(Matrix4f* m, f32 x, f32 y, f32 z)
{
    m->x03 = x;
    m->x13 = y;
    m->x23 = z;
}
