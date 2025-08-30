#include "../memory/memory.h"
#include "math.h"
#include <assert.h>

//***** Matrix 2x2 i32 Implementation *****
inline Matrix2i* matrix2i_make(const Arena* arena) { return (Matrix2i*)arena_alloc(arena, sizeof(i32) * 4, DEFAULT_ALIGNMENT); }

inline Matrix2i* matrix2i_make_aligned(const Arena* arena, u64 alignment) { return (Matrix2i*)arena_alloc(arena, sizeof(i32) * 4, alignment); }

inline void matrix2i_kill(const Arena* arena, Matrix2i* matrix) { arena_dealloc(arena, matrix); }

inline void matrix2i_identity(Matrix2i* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 1;
    result->x01 = 0;
    result->x10 = 0;
    result->x11 = 1;
}

inline void matrix2i_zero(Matrix2i* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 0;
    result->x01 = 0;
    result->x10 = 0;
    result->x11 = 0;
}

inline void matrix2i_add(const Matrix2i* a, const Matrix2i* b, Matrix2i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 + b->x00;
    result->x01 = a->x01 + b->x01;
    result->x10 = a->x10 + b->x10;
    result->x11 = a->x11 + b->x11;
}

inline void matrix2i_subtract(const Matrix2i* a, const Matrix2i* b, Matrix2i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 - b->x00;
    result->x01 = a->x01 - b->x01;
    result->x10 = a->x10 - b->x10;
    result->x11 = a->x11 - b->x11;
}

inline void matrix2i_scale(const Matrix2i* a, i32 s, Matrix2i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * s;
    result->x01 = a->x01 * s;
    result->x10 = a->x10 * s;
    result->x11 = a->x11 * s;
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

inline void matrix2f_identity(Matrix2f* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 1.0f;
    result->x01 = 0.0f;
    result->x10 = 0.0f;
    result->x11 = 1.0f;
}

inline void matrix2f_zero(Matrix2f* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 0.0f;
    result->x01 = 0.0f;
    result->x10 = 0.0f;
    result->x11 = 0.0f;
}

inline void matrix2f_add(const Matrix2f* a, const Matrix2f* b, Matrix2f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 + b->x00;
    result->x01 = a->x01 + b->x01;
    result->x10 = a->x10 + b->x10;
    result->x11 = a->x11 + b->x11;
}

inline void matrix2f_subtract(const Matrix2f* a, const Matrix2f* b, Matrix2f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 - b->x00;
    result->x01 = a->x01 - b->x01;
    result->x10 = a->x10 - b->x10;
    result->x11 = a->x11 - b->x11;
}

inline void matrix2f_scale(const Matrix2f* a, f32 s, Matrix2f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * s;
    result->x01 = a->x01 * s;
    result->x10 = a->x10 * s;
    result->x11 = a->x11 * s;
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

inline void matrix3i_identity(Matrix3i* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 1;
    result->x01 = 0;
    result->x02 = 0;
    result->x10 = 0;
    result->x11 = 1;
    result->x12 = 0;
    result->x20 = 0;
    result->x21 = 0;
    result->x22 = 1;
}

inline void matrix3i_zero(Matrix3i* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 0;
    result->x01 = 0;
    result->x02 = 0;
    result->x10 = 0;
    result->x11 = 0;
    result->x12 = 0;
    result->x20 = 0;
    result->x21 = 0;
    result->x22 = 0;
}

inline void matrix3i_add(const Matrix3i* a, const Matrix3i* b, Matrix3i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 + b->x00;
    result->x01 = a->x01 + b->x01;
    result->x02 = a->x02 + b->x02;
    result->x10 = a->x10 + b->x10;
    result->x11 = a->x11 + b->x11;
    result->x12 = a->x12 + b->x12;
    result->x20 = a->x20 + b->x20;
    result->x21 = a->x21 + b->x21;
    result->x22 = a->x22 + b->x22;
}

inline void matrix3i_subtract(const Matrix3i* a, const Matrix3i* b, Matrix3i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 - b->x00;
    result->x01 = a->x01 - b->x01;
    result->x02 = a->x02 - b->x02;
    result->x10 = a->x10 - b->x10;
    result->x11 = a->x11 - b->x11;
    result->x12 = a->x12 - b->x12;
    result->x20 = a->x20 - b->x20;
    result->x21 = a->x21 - b->x21;
    result->x22 = a->x22 - b->x22;
}

inline void matrix3i_scale(const Matrix3i* a, i32 s, Matrix3i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * s;
    result->x01 = a->x01 * s;
    result->x02 = a->x02 * s;
    result->x10 = a->x10 * s;
    result->x11 = a->x11 * s;
    result->x12 = a->x12 * s;
    result->x20 = a->x20 * s;
    result->x21 = a->x21 * s;
    result->x22 = a->x22 * s;
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

inline void matrix3f_identity(Matrix3f* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 1.0f;
    result->x01 = 0.0f;
    result->x02 = 0.0f;
    result->x10 = 0.0f;
    result->x11 = 1.0f;
    result->x12 = 0.0f;
    result->x20 = 0.0f;
    result->x21 = 0.0f;
    result->x22 = 1.0f;
}

inline void matrix3f_zero(Matrix3f* result)
{
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = 0.0f;
    result->x01 = 0.0f;
    result->x02 = 0.0f;
    result->x10 = 0.0f;
    result->x11 = 0.0f;
    result->x12 = 0.0f;
    result->x20 = 0.0f;
    result->x21 = 0.0f;
    result->x22 = 0.0f;
}

inline void matrix3f_add(const Matrix3f* a, const Matrix3f* b, Matrix3f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 + b->x00;
    result->x01 = a->x01 + b->x01;
    result->x02 = a->x02 + b->x02;
    result->x10 = a->x10 + b->x10;
    result->x11 = a->x11 + b->x11;
    result->x12 = a->x12 + b->x12;
    result->x20 = a->x20 + b->x20;
    result->x21 = a->x21 + b->x21;
    result->x22 = a->x22 + b->x22;
}

inline void matrix3f_subtract(const Matrix3f* a, const Matrix3f* b, Matrix3f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 - b->x00;
    result->x01 = a->x01 - b->x01;
    result->x02 = a->x02 - b->x02;
    result->x10 = a->x10 - b->x10;
    result->x11 = a->x11 - b->x11;
    result->x12 = a->x12 - b->x12;
    result->x20 = a->x20 - b->x20;
    result->x21 = a->x21 - b->x21;
    result->x22 = a->x22 - b->x22;
}

inline void matrix3f_scale(const Matrix3f* a, f32 s, Matrix3f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    result->x00 = a->x00 * s;
    result->x01 = a->x01 * s;
    result->x02 = a->x02 * s;
    result->x10 = a->x10 * s;
    result->x11 = a->x11 * s;
    result->x12 = a->x12 * s;
    result->x20 = a->x20 * s;
    result->x21 = a->x21 * s;
    result->x22 = a->x22 * s;
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

inline void matrix4i_identity(Matrix4i* result)
{
    assert(result != nullptr && "result cannot be null");
    result->x00 = 1;
    result->x01 = 0;
    result->x02 = 0;
    result->x03 = 0;
    result->x10 = 0;
    result->x11 = 1;
    result->x12 = 0;
    result->x13 = 0;
    result->x20 = 0;
    result->x21 = 0;
    result->x22 = 1;
    result->x23 = 0;
    result->x30 = 0;
    result->x31 = 0;
    result->x32 = 0;
    result->x33 = 1;
}

inline void matrix4i_zero(Matrix4i* result)
{
    assert(result != nullptr && "result cannot be null");
    result->x00 = 0;
    result->x01 = 0;
    result->x02 = 0;
    result->x03 = 0;
    result->x10 = 0;
    result->x11 = 0;
    result->x12 = 0;
    result->x13 = 0;
    result->x20 = 0;
    result->x21 = 0;
    result->x22 = 0;
    result->x23 = 0;
    result->x30 = 0;
    result->x31 = 0;
    result->x32 = 0;
    result->x33 = 0;
}

inline void matrix4i_add(const Matrix4i* a, const Matrix4i* b, Matrix4i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 + b->x00;
    result->x01 = a->x01 + b->x01;
    result->x02 = a->x02 + b->x02;
    result->x03 = a->x03 + b->x03;
    result->x10 = a->x10 + b->x10;
    result->x11 = a->x11 + b->x11;
    result->x12 = a->x12 + b->x12;
    result->x13 = a->x13 + b->x13;
    result->x20 = a->x20 + b->x20;
    result->x21 = a->x21 + b->x21;
    result->x22 = a->x22 + b->x22;
    result->x23 = a->x23 + b->x23;
    result->x30 = a->x30 + b->x30;
    result->x31 = a->x31 + b->x31;
    result->x32 = a->x32 + b->x32;
    result->x33 = a->x33 + b->x33;
}

inline void matrix4i_subtract(const Matrix4i* a, const Matrix4i* b, Matrix4i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 - b->x00;
    result->x01 = a->x01 - b->x01;
    result->x02 = a->x02 - b->x02;
    result->x03 = a->x03 - b->x03;
    result->x10 = a->x10 - b->x10;
    result->x11 = a->x11 - b->x11;
    result->x12 = a->x12 - b->x12;
    result->x13 = a->x13 - b->x13;
    result->x20 = a->x20 - b->x20;
    result->x21 = a->x21 - b->x21;
    result->x22 = a->x22 - b->x22;
    result->x23 = a->x23 - b->x23;
    result->x30 = a->x30 - b->x30;
    result->x31 = a->x31 - b->x31;
    result->x32 = a->x32 - b->x32;
    result->x33 = a->x33 - b->x33;
}

inline void matrix4i_scale(const Matrix4i* a, i32 s, Matrix4i* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * s;
    result->x01 = a->x01 * s;
    result->x02 = a->x02 * s;
    result->x03 = a->x03 * s;
    result->x10 = a->x10 * s;
    result->x11 = a->x11 * s;
    result->x12 = a->x12 * s;
    result->x13 = a->x13 * s;
    result->x20 = a->x20 * s;
    result->x21 = a->x21 * s;
    result->x22 = a->x22 * s;
    result->x23 = a->x23 * s;
    result->x30 = a->x30 * s;
    result->x31 = a->x31 * s;
    result->x32 = a->x32 * s;
    result->x33 = a->x33 * s;
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

inline void matrix4f_identity(Matrix4f* result)
{
    assert(matrix != nullptr && "matrix cannot be null");
    result->x00 = 1.0f;
    result->x01 = 0.0f;
    result->x02 = 0.0f;
    result->x03 = 0.0f;
    result->x10 = 0.0f;
    result->x11 = 1.0f;
    result->x12 = 0.0f;
    result->x13 = 0.0f;
    result->x20 = 0.0f;
    result->x21 = 0.0f;
    result->x22 = 1.0f;
    result->x23 = 0.0f;
    result->x30 = 0.0f;
    result->x31 = 0.0f;
    result->x32 = 0.0f;
    result->x33 = 1.0f;
}

inline void matrix4f_zero(Matrix4f* result)
{
    assert(matrix != nullptr && "matrix cannot be null");
    result->x00 = 0.0f;
    result->x01 = 0.0f;
    result->x02 = 0.0f;
    result->x03 = 0.0f;
    result->x10 = 0.0f;
    result->x11 = 0.0f;
    result->x12 = 0.0f;
    result->x13 = 0.0f;
    result->x20 = 0.0f;
    result->x21 = 0.0f;
    result->x22 = 0.0f;
    result->x23 = 0.0f;
    result->x30 = 0.0f;
    result->x31 = 0.0f;
    result->x32 = 0.0f;
    result->x33 = 0.0f;
}

inline void matrix4f_add(const Matrix4f* a, const Matrix4f* b, Matrix4f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 + b->x00;
    result->x01 = a->x01 + b->x01;
    result->x02 = a->x02 + b->x02;
    result->x03 = a->x03 + b->x03;
    result->x10 = a->x10 + b->x10;
    result->x11 = a->x11 + b->x11;
    result->x12 = a->x12 + b->x12;
    result->x13 = a->x13 + b->x13;
    result->x20 = a->x20 + b->x20;
    result->x21 = a->x21 + b->x21;
    result->x22 = a->x22 + b->x22;
    result->x23 = a->x23 + b->x23;
    result->x30 = a->x30 + b->x30;
    result->x31 = a->x31 + b->x31;
    result->x32 = a->x32 + b->x32;
    result->x33 = a->x33 + b->x33;
}

inline void matrix4f_subtract(const Matrix4f* a, const Matrix4f* b, Matrix4f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 - b->x00;
    result->x01 = a->x01 - b->x01;
    result->x02 = a->x02 - b->x02;
    result->x03 = a->x03 - b->x03;
    result->x10 = a->x10 - b->x10;
    result->x11 = a->x11 - b->x11;
    result->x12 = a->x12 - b->x12;
    result->x13 = a->x13 - b->x13;
    result->x20 = a->x20 - b->x20;
    result->x21 = a->x21 - b->x21;
    result->x22 = a->x22 - b->x22;
    result->x23 = a->x23 - b->x23;
    result->x30 = a->x30 - b->x30;
    result->x31 = a->x31 - b->x31;
    result->x32 = a->x32 - b->x32;
    result->x33 = a->x33 - b->x33;
}

inline void matrix4f_scale(const Matrix4f* a, f32 s, Matrix4f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    result->x00 = a->x00 * s;
    result->x01 = a->x01 * s;
    result->x02 = a->x02 * s;
    result->x03 = a->x03 * s;
    result->x10 = a->x10 * s;
    result->x11 = a->x11 * s;
    result->x12 = a->x12 * s;
    result->x13 = a->x13 * s;
    result->x20 = a->x20 * s;
    result->x21 = a->x21 * s;
    result->x22 = a->x22 * s;
    result->x23 = a->x23 * s;
    result->x30 = a->x30 * s;
    result->x31 = a->x31 * s;
    result->x32 = a->x32 * s;
    result->x33 = a->x33 * s;
}

inline void matrix4f_multiply(const Matrix4f* a, const Matrix4f* b, Matrix4f* result)
{
    assert(a != nullptr && "matrix a cannot be null");
    assert(b != nullptr && "matrix b cannot be null");
    assert(result != nullptr && "matrix result cannot be null");
    Matrix4i tmat;
    tmat.x00 = a->x00 * b->x00 + a->x01 * b->x10 + a->x02 * b->x20 + a->x03 * b->x30;
    tmat.x01 = a->x00 * b->x01 + a->x01 * b->x11 + a->x02 * b->x21 + a->x03 * b->x31;
    tmat.x02 = a->x00 * b->x02 + a->x01 * b->x12 + a->x02 * b->x22 + a->x03 * b->x32;
    tmat.x03 = a->x00 * b->x03 + a->x01 * b->x13 + a->x02 * b->x23 + a->x03 * b->x33;
    tmat.x10 = a->x10 * b->x00 + a->x11 * b->x10 + a->x12 * b->x20 + a->x13 * b->x30;
    tmat.x11 = a->x10 * b->x01 + a->x11 * b->x11 + a->x12 * b->x21 + a->x13 * b->x31;
    tmat.x12 = a->x10 * b->x02 + a->x11 * b->x12 + a->x12 * b->x22 + a->x13 * b->x32;
    tmat.x13 = a->x10 * b->x03 + a->x11 * b->x13 + a->x12 * b->x23 + a->x13 * b->x33;
    tmat.x20 = a->x20 * b->x00 + a->x21 * b->x10 + a->x22 * b->x20 + a->x23 * b->x30;
    tmat.x21 = a->x20 * b->x01 + a->x21 * b->x11 + a->x22 * b->x21 + a->x23 * b->x31;
    tmat.x22 = a->x20 * b->x02 + a->x21 * b->x12 + a->x22 * b->x22 + a->x23 * b->x32;
    tmat.x23 = a->x20 * b->x03 + a->x21 * b->x13 + a->x22 * b->x23 + a->x23 * b->x33;
    tmat.x30 = a->x30 * b->x00 + a->x31 * b->x10 + a->x32 * b->x20 + a->x33 * b->x30;
    tmat.x31 = a->x30 * b->x01 + a->x31 * b->x11 + a->x32 * b->x21 + a->x33 * b->x31;
    tmat.x32 = a->x30 * b->x02 + a->x31 * b->x12 + a->x32 * b->x22 + a->x33 * b->x32;
    tmat.x33 = a->x30 * b->x03 + a->x31 * b->x13 + a->x32 * b->x23 + a->x33 * b->x33;
    mem_copy(result, &tmat, sizeof(Matrix4f));
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

void matrix4f_perspective(f32 fov, f32 aspect, f32 near, f32 far, Matrix4f* result)
{
    mem_set(result->v, 0, 16);

    const f32 f = 1.0f / tan_(fov / 2);

    result->x00 = f / aspect;
    result->x11 = f;
    result->x22 = (far + near) / (near - far);
    result->x23 = 2 * far * near / (near - far);
    result->x32 = -1;
}

void matrix4f_orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, Matrix4f* result)
{
    mem_set(result->mat, 0, 16);

    result->x00 = 2.0f / (right - left);
    result->x11 = 2.0f / (top - bottom);
    result->x22 = -2.0f / (far - near);
    result->x33 = 1.0f;

    result->x03 = -(right + left) / (right - left);
    result->x13 = -(top + bottom) / (top - bottom);
    result->x23 = -(far + near) / (far - near);
}

void matrix4f_translate(const Matrix4f* m, f32 x, f32 y, f32 z, Matrix4f* result)
{
    Matrix4f tmat = {0};
    matrix4f_identity(&tmat);
    tmat.x03 = x;
    tmat.x13 = y;
    tmat.x23 = z;
    matrix4f_multiply(m, &tmat, result);
}

void matrix4f_rotate(const Matrix4f* m, f32 radian, Axis axis, Matrix4f* result)
{
    Matrix4f rmat      = {0};
    f32      cos_value = cosf(radian);
    f32      sin_value = sinf(radian);
    switch (axis) {
    case AXIS_X:
        rmat.x00 = 1.0f;
        rmat.x11 = cos_value;
        rmat.x12 = -sin_value;
        rmat.x21 = sin_value;
        rmat.x22 = cos_value;
        break;
    case AXIS_Y:
        rmat.x00 = cos_value;
        rmat.x02 = sin_value;
        rmat.x11 = 1.0f;
        rmat.x20 = -sin_value;
        rmat.x22 = cos_value;
        break;
    case AXIS_Z:
        rmat.x00 = cos_value;
        rmat.x01 = -sin_value;
        rmat.x10 = sin_value;
        rmat.x11 = cos_value;
        rmat.x22 = 1.0f;
        break;
    default:
        assert(false && "invalid axis");
        break;
    }
    matrix4f_multiply(m, &rmat, result);
}
