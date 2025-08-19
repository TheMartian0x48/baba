#ifndef BABA_MATH
#define BABA_MATH

#include "../types.h"

//***** Vector 2  *****
typedef struct {
    f32 x;
    f32 y;
} Vec2f;

typedef struct {
    f64 x;
    f64 y;
} Vec2d;

typedef struct {
    i32 x;
    i32 y;
} Vec2i;

typedef struct {
    i64 x;
    i64 y;
} Vec2l;

Vec2i vec2i_abs(const Vec2i v);
f32   vec2i_angle(const Vec2i v);
Vec2i vec2i_ceil(const Vec2i v);
Vec2i vec2i_floor(const Vec2i v);
Vec2i vec2i_clamp(const Vec2i v, i32 mi, i32 mx);
f32   vec2i_cross(const Vec2i v);
i32   vec2i_dot(const Vec2i v);
i32   vec2i_distance(const Vec2i v);
i32   vec2i_distance_square(const Vec2i v);
i32   vec2i_length(const Vec2i v);
i32   vec2i_length_square(const Vec2i v);
Vec2i vec2i_max(const Vec2i u, const Vec2i v);
Vec2i vec2i_min(const Vec2i u, const Vec2i v);
Vec2i vec2i_sign(const Vec2i v);
Vec2i vec2i_plus(const Vec2i u, const Vec2i v);
Vec2i vec2i_minus(const Vec2i u, const Vec2i v);
Vec2i vec2i_div(const Vec2i u, const Vec2i v);
Vec2i vec2i_mul(const Vec2i u, const Vec2i v);
Vec2i vec2i_scale(const Vec2i v, i32 scale);
Vec2i vec2i_shrink(const Vec2i v, i32 scale);

Vec2i vec2l_abs(const Vec2i v);
f32   vec2l_angle(const Vec2i v);
Vec2i vec2l_ceil(const Vec2i v);
Vec2i vec2l_floor(const Vec2i v);
Vec2i vec2l_clamp(const Vec2i v, i32 mi, i32 mx);
f64   vec2l_cross(const Vec2i v);
i64   vec2l_dot(const Vec2i v);
i64   vec2l_distance(const Vec2i v);
i64   vec2l_distance_square(const Vec2i v);
i64   vec2l_length(const Vec2i v);
i64   vec2l_length_square(const Vec2i v);
Vec2i vec2l_max(const Vec2i u, const Vec2i v);
Vec2i vec2l_min(const Vec2i u, const Vec2i v);
Vec2i vec2l_sign(const Vec2i v);
Vec2i vec2l_plus(const Vec2i u, const Vec2i v);
Vec2i vec2l_minus(const Vec2i u, const Vec2i v);
Vec2i vec2l_div(const Vec2i u, const Vec2i v);
Vec2i vec2l_mul(const Vec2i u, const Vec2i v);
Vec2i vec2l_scale(const Vec2i v, i32 scale);
Vec2i vec2l_shrink(const Vec2i v, i32 scale);

Vec2f vec2f_abs(const Vec2f v);
f32   vec2f_angle(const Vec2f v);
Vec2f vec2f_ceil(const Vec2f v);
Vec2f vec2f_floor(const Vec2f v);
Vec2f vec2f_clamp(const Vec2f v, i32 mi, i32 mx);
f32   vec2f_cross(const Vec2f v);
f32   vec2f_dot(const Vec2f v);
f32   vec2f_distance(const Vec2f v);
f32   vec2f_distance_square(const Vec2f v);
f32   vec2f_length(const Vec2f v);
f32   vec2f_length_square(const Vec2f v);
Vec2f vec2f_max(const Vec2f u, const Vec2f v);
Vec2f vec2f_min(const Vec2f u, const Vec2f v);
Vec2f vec2f_sign(const Vec2f v);
Vec2f vec2f_plus(const Vec2f u, const Vec2f v);
Vec2f vec2f_minus(const Vec2f u, const Vec2f v);
Vec2f vec2f_div(const Vec2f u, const Vec2f v);
Vec2f vec2f_mul(const Vec2f u, const Vec2f v);
Vec2f vec2f_scale(const Vec2f v, i32 scale);
Vec2f vec2f_shrink(const Vec2f v, i32 scale);

Vec2d vec2d_abs(const Vec2d v);
f32   vec2d_angle(const Vec2d v);
Vec2d vec2d_ceil(const Vec2d v);
Vec2d vec2d_floor(const Vec2d v);
Vec2d vec2d_clamp(const Vec2d v, i32 mi, i32 mx);
f32   vec2d_cross(const Vec2d v);
f32   vec2d_dot(const Vec2d v);
f32   vec2d_distance(const Vec2d v);
f32   vec2d_distance_square(const Vec2d v);
f32   vec2d_length(const Vec2d v);
f32   vec2d_length_square(const Vec2d v);
Vec2d vec2d_max(const Vec2d u, const Vec2d v);
Vec2d vec2d_min(const Vec2d u, const Vec2d v);
Vec2d vec2d_sign(const Vec2d v);
Vec2d vec2d_plus(const Vec2d u, const Vec2d v);
Vec2d vec2d_minus(const Vec2d u, const Vec2d v);
Vec2d vec2d_div(const Vec2d u, const Vec2d v);
Vec2d vec2d_mul(const Vec2d u, const Vec2d v);
Vec2d vec2d_scale(const Vec2d v, i32 scale);
Vec2d vec2d_shrink(const Vec2d v, i32 scale);

//***** Vector 3  *****

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f32;

typedef struct {
    i32 x;
    i32 y;
    i32 z;
} Vec3i32;

typedef Vec3f32 Vec3f;
typedef Vec3i32 Vec3i;

//***** Matrix  *****
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
void matrix_2i32_identity(Matrix2i32* matrix); // creates an identity matrix 2x2 of i32
void matrix_2i32_zero(Matrix2i32* matrix);     // creates a zero matrix 2x2 of i32

//***** Matrix 2x2 f32 *****
void matrix_2f32_identity(Matrix2f32* matrix); // creates an identity matrix 2x2 of f32
void matrix_2f32_zero(Matrix2f32* matrix);     // creates a zero matrix 2x2 of f32

//***** Matrix 3x3 i32 *****
void matrix_3i32_identity(Matrix3i32* matrix); // creates an identity matrix 3x3 of i32
void matrix_3i32_zero(Matrix3i32* matrix);     // creates a zero matrix 3x3 of i32

//***** Matrix 3x3 f32 *****
void matrix_3f32_identity(Matrix3i32* matrix); // creates an identity matrix 3x3 of f32
void matrix_3f32_zero(Matrix3f32* matrix);     // creates a zero matrix 3x3 of f32

#endif
