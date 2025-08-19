#include "math.h"
#include <assert.h>

//***** Matrix 2x2 i32 Implementation *****
void matrix_2i32_identity(Matrix2i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1;
    matrix->x01 = 0;
    matrix->x10 = 0;
    matrix->x11 = 1;
}

void matrix_2i32_zero(Matrix2i32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0;
    matrix->x01 = 0;
    matrix->x10 = 0;
    matrix->x11 = 0;
}

//***** Matrix 2x2 f32 Implementation *****

void matrix_2f32_identity(Matrix2f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 1.0f;
    matrix->x01 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 1.0f;
}

void matrix_2f32_zero(Matrix2f32* matrix)
{
    assert(matrix && "matrix cannot be null");
    matrix->x00 = 0.0f;
    matrix->x01 = 0.0f;
    matrix->x10 = 0.0f;
    matrix->x11 = 0.0f;
}

//***** Matrix 3x3 i32 Implementation *****
void matrix_3i32_identity(Matrix3i32* matrix)
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
void matrix_3i32_zero(Matrix3i32* matrix)
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

//***** Matrix 3x3 f32 Implementation *****
void matrix_3f32_identity(Matrix3i32* matrix)
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
void matrix_3f32_zero(Matrix3f32* matrix)
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
