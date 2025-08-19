#ifndef BABA_MATH
#define BABA_MATH

#include "../types.h"

typedef struct {
    f32 x00, x01;
    f32 x10, x11;
} Matrix2f32;

typedef struct {
    i32 x00, x01;
    i32 x10, x11;
} Matrix2i32;

typedef struct {
    f32 x00, x01, x02;
    f32 x10, x11, x12;
    f32 x20, x21, x22;
} Matrix3f32;

typedef struct {
    i32 x00, x01, x02;
    i32 x10, x11, x12;
    i32 x20, x21, x22;
} Matrix3i32;

//***** Matrix 2x2 i32 *****
void matrix_2x2_i32_identity(Matrix2i32* matrix); // creates an identity matrix 2x2 of i32
void matrix_2x2_i32_zero(Matrix2i32* matrix);     // creates a zero matrix 2x2 of i32

//***** Matrix 2x2 f32 *****
void matrix_2x2_f32_identity(Matrix2f32* matrix); // creates an identity matrix 2x2 of f32
void matrix_2x2_f32_zero(Matrix2f32* matrix);     // creates a zero matrix 2x2 of f32

//***** Matrix 3x3 i32 *****
void matrix_3x3_i32_identity(Matrix3i32* matrix); // creates an identity matrix 3x3 of i32
void matrix_3x3_i32_zero(Matrix3i32* matrix);     // creates a zero matrix 3x3 of i32

//***** Matrix 3x3 f32 *****
void matrix_3x3_f32_identity(Matrix3i32* matrix); // creates an identity matrix 3x3 of f32
void matrix_3x3_f32_zero(Matrix3f32* matrix);     // creates a zero matrix 3x3 of f32

#endif
