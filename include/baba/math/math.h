#ifndef BABA_MATH
#define BABA_MATH

#include "../memory/memory.h"
#include "../types.h"
#include <stdio.h>

//***** constants *****

extern const f32 PI;
extern const f32 E;
extern const f32 SQRT2;
extern const f32 SQRT3;
extern const f32 GOLDEN_RATIO;
extern const f32 RADIAN;
extern const f32 DEGREE;
extern const f32 EPSILON;

//***** Basic *****
f32 exp_f(const f32 x);
f64 exp_d(const f64 x);
f32 exp2_f(const f32 x);
f64 exp2_d(const f64 x);
f32 log_f(const f32 x);
f64 log_d(const f64 x);
f32 log10_f(const f32 x);
f64 log10_d(const f64 x);
f32 log2_f(const f32 x);
f64 log2_d(const f64 x);

#define exp_(x)   _Generic((x), f32: exp_f, f64: exp_d)((x))
#define exp2_(x)  _Generic((x), f32: exp2_f, f64: exp2_d)((x))
#define log_(x)   _Generic((x), f32: log_f, f64: log_d)((x))
#define log10_(x) _Generic((x), f32: log10_f, f64: log10_d)((x))
#define log2_(x)  _Generic((x), f32: log2_f, f64: log2_d)((x))

f32 pow_f(const f32 base, const f32 exp);
f64 pow_d(const f64 base, const f64 exp);
f32 sqrt_f(const f32 x);
f64 sqrt_d(const f64 x);
f32 cbrt_f(const f32 x);
f64 cbrt_d(const f64 x);
f32 hypot_f(const f32 x, const f32 y);
f64 hypot_d(const f64 x, const f64 y);

#define pow_(base, exp) _Generic((base), f32: pow_f, f64: pow_d)((base), (exp))
#define sqrt_(x)        _Generic((x), f32: sqrt_f, f64: sqrt_d)((x))
#define cbrt_(x)        _Generic((x), f32: cbrt_f, f64: cbrt_d)((x))
#define hypot_(x, y)    _Generic((x), f32: hypot_f, f64: hypot_d)((x), (y))

//***** Trigonometry *****
f32 angle_to_radian_f(const f32 angle);
f32 radian_to_angle_f(const f32 radian);
f64 angle_to_radian_d(const f64 angle);
f64 radian_to_angle_d(const f64 radian);
f32 sin_f(const f32 radian);
f64 sin_d(const f64 radian);
f32 cos_f(const f32 radian);
f64 cos_d(const f64 radian);
f32 tan_f(const f32 radian);
f32 tan_d(const f64 radian);
f32 arc_sin_f(const f32 radian);
f64 arc_sin_d(const f64 radian);
f32 arc_cos_f(const f32 radian);
f64 arc_cos_d(const f64 radian);
f32 arc_tan_f(const f32 radian);
f32 arc_tan_d(const f64 radian);

#define angle_to_radian_(angle)  _Generic((angle), f32: angle_to_radian_f, f64: angle_to_radian_d)((angle))
#define radian_to_angle_(radian) _Generic((radian), f32: radian_to_angle_f, f64: radian_to_angle_d)((radian))
#define sin_(radian)             _Generic((radian), f32: sin_f, f64: sin_d)((radian))
#define cos_(radian)             _Generic((radian), f32: cos_f, f64: cos_d)((radian))
#define tan_(radian)             _Generic((radian), f32: tan_f, f64: tan_d)((radian))
#define arc_sin_(radian)         _Generic((radian), f32: arc_sin_f, f64: arc_sin_d)((radian))
#define arc_cos_(radian)         _Generic((radian), f32: arc_cos_f, f64: arc_cos_d)((radian))
#define arc_tan_(radian)         _Generic((radian), f32: arc_tan_f, f64: arc_tan_d)((radian))

typedef enum {
    AXIS_X = 0,
    AXIS_Y,
    AXIS_Z
} Axis;

//***** Complex Number *****

typedef struct {
    i32 real;
    i32 imaginary;
} Complexi;

typedef struct {
    f32 real;
    f32 imaginary;
} Complexf;

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

// Vec2i vec2i_abs(const Vec2i v);
// f32   vec2i_angle(const Vec2i v);
// Vec2i vec2i_ceil(const Vec2i v);
// Vec2i vec2i_floor(const Vec2i v);
// Vec2i vec2i_clamp(const Vec2i v, i32 mi, i32 mx);
// f32   vec2i_cross(const Vec2i v);
// i32   vec2i_dot(const Vec2i v);
// i32   vec2i_distance(const Vec2i v);
// i32   vec2i_distance_square(const Vec2i v);
// i32   vec2i_length(const Vec2i v);
// i32   vec2i_length_square(const Vec2i v);
// Vec2i vec2i_max(const Vec2i u, const Vec2i v);
// Vec2i vec2i_min(const Vec2i u, const Vec2i v);
// Vec2i vec2i_sign(const Vec2i v);
// Vec2i vec2i_plus(const Vec2i u, const Vec2i v);
// Vec2i vec2i_minus(const Vec2i u, const Vec2i v);
// Vec2i vec2i_div(const Vec2i u, const Vec2i v);
// Vec2i vec2i_mul(const Vec2i u, const Vec2i v);
// Vec2i vec2i_scale(const Vec2i v, i32 scale);
// Vec2i vec2i_shrink(const Vec2i v, i32 scale);
//
// Vec2i vec2l_abs(const Vec2i v);
// f32   vec2l_angle(const Vec2i v);
// Vec2i vec2l_ceil(const Vec2i v);
// Vec2i vec2l_floor(const Vec2i v);
// Vec2i vec2l_clamp(const Vec2i v, i32 mi, i32 mx);
// f64   vec2l_cross(const Vec2i v);
// i64   vec2l_dot(const Vec2i v);
// i64   vec2l_distance(const Vec2i v);
// i64   vec2l_distance_square(const Vec2i v);
// i64   vec2l_length(const Vec2i v);
// i64   vec2l_length_square(const Vec2i v);
// Vec2i vec2l_max(const Vec2i u, const Vec2i v);
// Vec2i vec2l_min(const Vec2i u, const Vec2i v);
// Vec2i vec2l_sign(const Vec2i v);
// Vec2i vec2l_plus(const Vec2i u, const Vec2i v);
// Vec2i vec2l_minus(const Vec2i u, const Vec2i v);
// Vec2i vec2l_div(const Vec2i u, const Vec2i v);
// Vec2i vec2l_mul(const Vec2i u, const Vec2i v);
// Vec2i vec2l_scale(const Vec2i v, i32 scale);
// Vec2i vec2l_shrink(const Vec2i v, i32 scale);
//
// Vec2f vec2f_abs(const Vec2f v);
// f32   vec2f_angle(const Vec2f v);
// Vec2f vec2f_ceil(const Vec2f v);
// Vec2f vec2f_floor(const Vec2f v);
// Vec2f vec2f_clamp(const Vec2f v, i32 mi, i32 mx);
// f32   vec2f_cross(const Vec2f v);
// f32   vec2f_dot(const Vec2f v);
// f32   vec2f_distance(const Vec2f v);
// f32   vec2f_distance_square(const Vec2f v);
// f32   vec2f_length(const Vec2f v);
// f32   vec2f_length_square(const Vec2f v);
// Vec2f vec2f_max(const Vec2f u, const Vec2f v);
// Vec2f vec2f_min(const Vec2f u, const Vec2f v);
// Vec2f vec2f_sign(const Vec2f v);
// Vec2f vec2f_plus(const Vec2f u, const Vec2f v);
// Vec2f vec2f_minus(const Vec2f u, const Vec2f v);
// Vec2f vec2f_div(const Vec2f u, const Vec2f v);
// Vec2f vec2f_mul(const Vec2f u, const Vec2f v);
// Vec2f vec2f_scale(const Vec2f v, i32 scale);
// Vec2f vec2f_shrink(const Vec2f v, i32 scale);
//
// Vec2d vec2d_abs(const Vec2d v);
// f32   vec2d_angle(const Vec2d v);
// Vec2d vec2d_ceil(const Vec2d v);
// Vec2d vec2d_floor(const Vec2d v);
// Vec2d vec2d_clamp(const Vec2d v, i32 mi, i32 mx);
// f32   vec2d_cross(const Vec2d v);
// f32   vec2d_dot(const Vec2d v);
// f32   vec2d_distance(const Vec2d v);
// f32   vec2d_distance_square(const Vec2d v);
// f32   vec2d_length(const Vec2d v);
// f32   vec2d_length_square(const Vec2d v);
// Vec2d vec2d_max(const Vec2d u, const Vec2d v);
// Vec2d vec2d_min(const Vec2d u, const Vec2d v);
// Vec2d vec2d_sign(const Vec2d v);
// Vec2d vec2d_plus(const Vec2d u, const Vec2d v);
// Vec2d vec2d_minus(const Vec2d u, const Vec2d v);
// Vec2d vec2d_div(const Vec2d u, const Vec2d v);
// Vec2d vec2d_mul(const Vec2d u, const Vec2d v);
// Vec2d vec2d_scale(const Vec2d v, i32 scale);
// Vec2d vec2d_shrink(const Vec2d v, i32 scale);

// macros for vec2

// #define vec2_abs_(v)           _Generic((v), Vec2i: vec2i_abs, Vec2l: vec2l_abs, Vec2f: vec2f_abs, Vec2d: vec2d_abs)((v))
// #define vec2_angle_(v)         _Generic((v), Vec2i: vec2i_angle, Vec2l: vec2l_angle, Vec2f: vec2f_angle, Vec2d: vec2d_angle)((v))
// #define vec2_ceil_(v)          _Generic((v), Vec2i: vec2i_ceil, Vec2l: vec2l_ceil, Vec2f: vec2f_ceil, Vec2d: vec2d_ceil)((v))
// #define vec2_floor_(v)         _Generic((v), Vec2i: vec2i_floor, Vec2l: vec2l_floor, Vec2f: vec2f_floor, Vec2d: vec2d_floor)((v))
// #define vec2_clamp_(v, mi, mx) _Generic((v), Vec2i: vec2i_clamp, Vec2l: vec2l_clamp, Vec2f: vec2f_clamp, Vec2d: vec2d_clamp)((v), (mi), (mx))
// #define vec2_cross_(v)         _Generic((v), Vec2i: vec2i_cross, Vec2l: vec2l_cross, Vec2f: vec2f_cross, Vec2d: vec2d_cross)((v))
// #define vec2_dot_(v)           _Generic((v), Vec2i: vec2i_dot, Vec2l: vec2l_dot, Vec2f: vec2f_dot, Vec2d: vec2d_dot)((v))
// #define vec2_distance_(v)      _Generic((v), Vec2i: vec2i_distance, Vec2l: vec2l_distance, Vec2f: vec2f_distance, Vec2d: vec2d_distance)((v))
// #define vec2_distance_square_(v)                                                                                                                     \
//     _Generic((v), Vec2i: vec2i_distance_square, Vec2l: vec2l_distance_square, Vec2f: vec2f_distance_square, Vec2d: vec2d_distance_square)((v))
// #define vec2_length_(v) _Generic((v), Vec2i: vec2i_length, Vec2l: vec2l_length, Vec2f: vec2f_length, Vec2d: vec2d_length)((v))
// #define vec2_length_square_(v)                                                                                                                       \
//     _Generic((v), Vec2i: vec2i_length_square, Vec2l: vec2l_length_square, Vec2f: vec2f_length_square, Vec2d: vec2d_length_square)((v))
// #define vec2_max_(u, v)    _Generic((u), Vec2i: vec2i_max, Vec2l: vec2l_max, Vec2f: vec2f_max, Vec2d: vec2d_max)((u), (v))
// #define vec2_min_(u, v)    _Generic((u), Vec2i: vec2i_min, Vec2l: vec2l_min, Vec2f: vec2f_min, Vec2d: vec2d_min)((u), (v))
// #define vec2_sign_(v)      _Generic((v), Vec2i: vec2i_sign, Vec2l: vec2l_sign, Vec2f: vec2f_sign, Vec2d: vec2d_sign)((v))
// #define vec2_plus_(u, v)   _Generic((u), Vec2i: vec2i_plus, Vec2l: vec2l_plus, Vec2f: vec2f_plus, Vec2d: vec2d_plus)((u), (v))
// #define vec2_minus_(u, v)  _Generic((u), Vec2i: vec2i_minus, Vec2l: vec2l_minus, Vec2f: vec2f_minus, Vec2d: vec2d_minus)((u), (v))
// #define vec2_div_(u, v)    _Generic((u), Vec2i: vec2i_div, Vec2l: vec2l_div, Vec2f: vec2f_div, Vec2d: vec2d_div)((u), (v))
// #define vec2_mul_(u, v)    _Generic((u), Vec2i: vec2i_mul, Vec2l: vec2l_mul, Vec2f: vec2f_mul, Vec2d: vec2d_mul)((u), (v))
// #define vec2_scale_(v, s)  _Generic((v), Vec2i: vec2i_scale, Vec2l: vec2l_scale, Vec2f: vec2f_scale, Vec2d: vec2d_scale)((v), (s))
// #define vec2_shrink_(v, s) _Generic((v), Vec2i: vec2i_shrink, Vec2l: vec2l_shrink, Vec2f: vec2f_shrink, Vec2d: vec2d_shrink)((v), (s))

//***** Vector 3  *****

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    f64 x;
    f64 y;
    f64 z;
} Vec3d;

typedef struct {
    i32 x;
    i32 y;
    i32 z;
} Vec3i;

typedef struct {
    i64 x;
    i64 y;
    i64 z;
} Vec3l;

//***** Matrix  *****
// Example for calling using macros:
// Matrix2i* m2i = matrix_make_(arena, (Matrix2i*)0);

typedef union {
    struct {
        i32 x00, x01;
        i32 x10, x11;
    };
    i32 v[4];
    i32 mat[2][2];
} Matrix2i;

typedef union {
    struct {
        f32 x00, x01;
        f32 x10, x11;
    };
    f32 v[4];
    f32 mat[2][2];
} Matrix2f;

typedef union {
    struct {
        i32 x00, x01, x02;
        i32 x10, x11, x12;
        i32 x20, x21, x22;
    };
    i32 v[9];
    i32 mat[3][3];
} Matrix3i;

typedef union {
    struct {
        f32 x00, x01, x02;
        f32 x10, x11, x12;
        f32 x20, x21, x22;
    };
    f32 v[9];
    f32 mat[3][3];
} Matrix3f;

typedef union {
    struct {
        i32 x00, x01, x02, x03;
        i32 x10, x11, x12, x13;
        i32 x20, x21, x22, x23;
        i32 x30, x31, x32, x33;
    };
    i32 v[16];
    i32 mat[4][4];
} Matrix4i;

typedef union {
    struct {
        f32 x00, x01, x02, x03;
        f32 x10, x11, x12, x13;
        f32 x20, x21, x22, x23;
        f32 x30, x31, x32, x33;
    };
    f32 v[16];
    f32 mat[4][4];
} Matrix4f;

//***** Matrix 2x2 i32 *****
Matrix2i* matrix2i_make(const Arena* arena);                                         // creates an identity matrix 2x2 of i32
Matrix2i* matrix2i_make_aligned(const Arena* arena, u64 alignment);                  // creates an identity matrix 2x2 of i32
void      matrix2i_kill(const Arena* arena, Matrix2i* matrix);                       // creates an identity matrix 2x2 of i32
void      matrix2i_identity(Matrix2i* matrix);                                       // creates an identity matrix 2x2 of i32
void      matrix2i_zero(Matrix2i* matrix);                                           // creates a zero matrix 2x2 of i32
void      matrix2i_add(const Matrix2i* a, const Matrix2i* b, Matrix2i* result);      // add matrix b to matrix a
void      matrix2i_subtract(const Matrix2i* a, const Matrix2i* b, Matrix2i* result); // subtract matrix b from matrix a
void      matrix2i_scale(const Matrix2i* a, i32 s, Matrix2i* result);                // scale matrix a by scaler s
void      matrix2i_multiply(const Matrix2i* a, const Matrix2i* b, Matrix2i* result); // result = a * b
void      matrix2i_copy(const Matrix2i* a, Matrix2i* result);                        // copy matrix a
void      matrix2i_transpose(Matrix2i* a);                                           // transposition of matrix a
void      matrix2i_print(const Matrix2i* a, FILE* stream);                           // print matrix a

//***** Matrix 2x2 f32 *****
Matrix2f* matrix2f_make(const Arena* arena);                                         // creates an identity matrix 2x2 of i32
Matrix2f* matrix2f_make_aligned(const Arena* arena, u64 alignment);                  // creates an identity matrix 2x2 of i32
void      matrix2f_kill(const Arena* arena, Matrix2f* matrix);                       // creates an identity matrix 2x2 of i32
void      matrix2f_identity(Matrix2f* result);                                       // creates an identity matrix 2x2 of f32
void      matrix2f_zero(Matrix2f* result);                                           // creates a zero matrix 2x2 of f32
void      matrix2f_add(const Matrix2f* a, const Matrix2f* b, Matrix2f* result);      // add matrix b to matrix a
void      matrix2f_subtract(const Matrix2f* a, const Matrix2f* b, Matrix2f* result); // subtract matrix b from matrix a
void      matrix2f_scale(const Matrix2f* a, f32 s, Matrix2f* result);                // scale matrix a by scaler s
void      matrix2f_multiply(const Matrix2f* a, const Matrix2f* b, Matrix2f* result); // result = a * b
void      matrix2f_copy(const Matrix2f* a, Matrix2f* result);                        // copy matrix a
void      matrix2f_print(const Matrix2f* a, FILE* stream);                           // print matrix a

//***** Matrix 3x3 i32 *****
Matrix3i* matrix3i_make(const Arena* arena);                                         // creates an identity matrix 2x2 of i32
Matrix3i* matrix3i_make_aligned(const Arena* arena, u64 alignment);                  // creates an identity matrix 2x2 of i32
void      matrix3i_kill(const Arena* arena, Matrix3i* matrix);                       // creates an identity matrix 2x2 of i32
void      matrix3i_identity(Matrix3i* result);                                       // creates an identity matrix 3x3 of i32
void      matrix3i_zero(Matrix3i* result);                                           // creates a zero matrix 3x3 of i32
void      matrix3i_add(const Matrix3i* a, const Matrix3i* b, Matrix3i* result);      // add matrix b to matrix a
void      matrix3i_subtract(const Matrix3i* a, const Matrix3i* b, Matrix3i* result); // subtract matrix b from matrix a
void      matrix3i_scale(const Matrix3i* a, i32 s, Matrix3i* result);                // scale matrix a by scaler s
void      matrix3i_multiply(const Matrix3i* a, const Matrix3i* b, Matrix3i* result); // result = a * b
void      matrix3i_copy(const Matrix3i* a, Matrix3i* result);                        // copy matrix a
void      matrix3i_print(const Matrix3i* a, FILE* stream);                           // print matrix a

//***** Matrix 3x3 f32 *****
Matrix3f* matrix3f_make(const Arena* arena);                                         // creates an identity matrix 2x2 of i32
Matrix3f* matrix3f_make_aligned(const Arena* arena, u64 alignment);                  // creates an identity matrix 2x2 of i32
void      matrix3f_kill(const Arena* arena, Matrix3f* matrix);                       // creates an identity matrix 2x2 of i32
void      matrix3f_identity(Matrix3f* result);                                       // creates an identity matrix 3x3 of f32
void      matrix3f_zero(Matrix3f* result);                                           // creates a zero matrix 3x3 of f32
void      matrix3f_add(const Matrix3f* a, const Matrix3f* b, Matrix3f* result);      // add matrix b to matrix a
void      matrix3f_subtract(const Matrix3f* a, const Matrix3f* b, Matrix3f* result); // subtract matrix b from matrix a
void      matrix3f_scale(const Matrix3f* a, f32 s, Matrix3f* result);                // scale matrix a by scaler s
void      matrix3f_multiply(const Matrix3f* a, const Matrix3f* b, Matrix3f* result); // result = a * b
void      matrix3f_copy(const Matrix3f* a, Matrix3f* result);                        // copy matrix a
void      matrix3f_print(const Matrix3f* a, FILE* stream);                           // print matrix a

//***** Matrix 4x4 i32 *****
Matrix4i* matrix4i_make(const Arena* arena);                                         // creates an identity matrix 2x2 of i32
Matrix4i* matrix4i_make_aligned(const Arena* arena, u64 alignment);                  // creates an identity matrix 2x2 of i32
void      matrix4i_kill(const Arena* arena, Matrix4i* matrix);                       // creates an identity matrix 2x2 of i32
void      matrix4i_identity(Matrix4i* result);                                       // creates an identity matrix 4x4 of i32
void      matrix4i_zero(Matrix4i* result);                                           // creates a zero matrix 4x4 of i32
void      matrix4i_add(const Matrix4i* a, const Matrix4i* b, Matrix4i* result);      // add matrix b to matrix a
void      matrix4i_subtract(const Matrix4i* a, const Matrix4i* b, Matrix4i* result); // subtract matrix b from matrix a
void      matrix4i_scale(const Matrix4i* a, i32 s, Matrix4i* result);                // scale matrix a by scaler s
void      matrix4i_multiply(const Matrix4i* a, const Matrix4i* b, Matrix4i* result); // result = a * b
void      matrix4i_copy(const Matrix4i* a, Matrix4i* result);                        // copy matrix a
void      matrix4i_print(const Matrix4i* a, FILE* stream);                           // print matrix a

//***** Matrix 4x4 f32 *****
Matrix4f* matrix4f_make(const Arena* arena);                                         // creates an identity matrix 2x2 of i32
Matrix4f* matrix4f_make_aligned(const Arena* arena, u64 alignment);                  // creates an identity matrix 2x2 of i32
void      matrix4f_kill(const Arena* arena, Matrix4f* matrix);                       // creates an identity matrix 2x2 of i32
void      matrix4f_identity(Matrix4f* result);                                       // creates an identity matrix 4x4 of f32
void      matrix4f_zero(Matrix4f* result);                                           // creates a zero matrix 4x4 of f32
void      matrix4f_add(const Matrix4f* a, const Matrix4f* b, Matrix4f* result);      // add matrix b to matrix a
void      matrix4f_subtract(const Matrix4f* a, const Matrix4f* b, Matrix4f* result); // subtract matrix b from matrix a
void      matrix4f_scale(const Matrix4f* a, f32 s, Matrix4f* result);                // scale matrix a by scaler s
void      matrix4f_multiply(const Matrix4f* a, const Matrix4f* b, Matrix4f* result); // result = a * b
void      matrix4f_copy(const Matrix4f* a, Matrix4f* result);                        // copy matrix a
void      matrix4f_print(const Matrix4f* a, FILE* stream);                           // print matrix a

void matrix4f_perspective(f32 fov, f32 aspect, f32 near, f32 far, Matrix4f* result);
void matrix4f_orthographic(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, Matrix4f* result);
void matrix4f_translate(const Matrix4f* m, f32 x, f32 y, f32 z, Matrix4f* result);
void matrix4f_rotate(const Matrix4f* m, f32 radian, Axis axis, Matrix4f* result);

//***** Matrix macros *****
#define matrix_make_(arena, type)                                                                                                                    \
    _Generic((type),                                                                                                                                 \
        Matrix2i *: matrix2i_make,                                                                                                                   \
        Matrix2f *: matrix2f_make,                                                                                                                   \
        Matrix3i *: matrix3i_make,                                                                                                                   \
        Matrix3f *: matrix3f_make,                                                                                                                   \
        Matrix4i *: matrix4i_make,                                                                                                                   \
        Matrix4f *: matrix4f_make)((arena))

#define matrix_make_aligned_(arena, type, alignment)                                                                                                 \
    _Generic((type),                                                                                                                                 \
        Matrix2i *: matrix2i_make_aligned,                                                                                                           \
        Matrix2f *: matrix2f_make_aligned,                                                                                                           \
        Matrix3i *: matrix3i_make_aligned,                                                                                                           \
        Matrix3f *: matrix3f_make_aligned,                                                                                                           \
        Matrix4i *: matrix4i_make_aligned,                                                                                                           \
        Matrix4f *: matrix4f_make_aligned)((arena), (alignment))

#define matrix_kill_(arena, matrix)                                                                                                                  \
    _Generic((matrix),                                                                                                                               \
        Matrix2i *: matrix2i_kill,                                                                                                                   \
        Matrix2f *: matrix2f_kill,                                                                                                                   \
        Matrix3i *: matrix3i_kill,                                                                                                                   \
        Matrix3f *: matrix3f_kill,                                                                                                                   \
        Matrix4i *: matrix4i_kill,                                                                                                                   \
        Matrix4f *: matrix4f_kill)((arena), (matrix))

#define matrix_identity_(matrix)                                                                                                                     \
    _Generic((matrix),                                                                                                                               \
        Matrix2i *: matrix2i_identity,                                                                                                               \
        Matrix2f *: matrix2f_identity,                                                                                                               \
        Matrix3i *: matrix3i_identity,                                                                                                               \
        Matrix3f *: matrix3f_identity,                                                                                                               \
        Matrix4i *: matrix4i_identity,                                                                                                               \
        Matrix4f *: matrix4f_identity)((matrix))

#define matrix_zero_(matrix)                                                                                                                         \
    _Generic((matrix),                                                                                                                               \
        Matrix2i *: matrix2i_zero,                                                                                                                   \
        Matrix2f *: matrix2f_zero,                                                                                                                   \
        Matrix3i *: matrix3i_zero,                                                                                                                   \
        Matrix3f *: matrix3f_zero,                                                                                                                   \
        Matrix4i *: matrix4i_zero,                                                                                                                   \
        Matrix4f *: matrix4f_zero)((matrix))

#define matrix_add_(a, b, result)                                                                                                                    \
    _Generic((a),                                                                                                                                    \
        Matrix2i *: matrix2i_add,                                                                                                                    \
        Matrix2f *: matrix2f_add,                                                                                                                    \
        Matrix3i *: matrix3i_add,                                                                                                                    \
        Matrix3f *: matrix3f_add,                                                                                                                    \
        Matrix4i *: matrix4i_add,                                                                                                                    \
        Matrix4f *: matrix4f_add)((a), (b), (result))

#define matrix_subtract_(a, b, result)                                                                                                               \
    _Generic((a),                                                                                                                                    \
        Matrix2i *: matrix2i_subtract,                                                                                                               \
        Matrix2f *: matrix2f_subtract,                                                                                                               \
        Matrix3i *: matrix3i_subtract,                                                                                                               \
        Matrix3f *: matrix3f_subtract,                                                                                                               \
        Matrix4i *: matrix4i_subtract,                                                                                                               \
        Matrix4f *: matrix4f_subtract)((a), (b), (result))

#define matrix_scale_(a, s, result)                                                                                                                  \
    _Generic((a),                                                                                                                                    \
        Matrix2i *: matrix2i_scale,                                                                                                                  \
        Matrix2f *: matrix2f_scale,                                                                                                                  \
        Matrix3i *: matrix3i_scale,                                                                                                                  \
        Matrix3f *: matrix3f_scale,                                                                                                                  \
        Matrix4i *: matrix4i_scale,                                                                                                                  \
        Matrix4f *: matrix4f_scale)((a), (s), (result))

#define matrix_multiply_(a, b, result)                                                                                                               \
    _Generic((a),                                                                                                                                    \
        Matrix2i *: matrix2i_multiply,                                                                                                               \
        Matrix2f *: matrix2f_multiply,                                                                                                               \
        Matrix3i *: matrix3i_multiply,                                                                                                               \
        Matrix3f *: matrix3f_multiply,                                                                                                               \
        Matrix4i *: matrix4i_multiply,                                                                                                               \
        Matrix4f *: matrix4f_multiply)((a), (b), (result))

#define matrix_copy_(a, result)                                                                                                                      \
    _Generic((a),                                                                                                                                    \
        Matrix2i *: matrix2i_copy,                                                                                                                   \
        Matrix2f *: matrix2f_copy,                                                                                                                   \
        Matrix3i *: matrix3i_copy,                                                                                                                   \
        Matrix3f *: matrix3f_copy,                                                                                                                   \
        Matrix4i *: matrix4i_copy,                                                                                                                   \
        Matrix4f *: matrix4f_copy)((a), (result))

#define matrix_print_(a, stream)                                                                                                                     \
    _Generic((a),                                                                                                                                    \
        Matrix2i *: matrix2i_print,                                                                                                                  \
        Matrix2f *: matrix2f_print,                                                                                                                  \
        Matrix3i *: matrix3i_print,                                                                                                                  \
        Matrix3f *: matrix3f_print,                                                                                                                  \
        Matrix4i *: matrix4i_print,                                                                                                                  \
        Matrix4f *: matrix4f_print)((a), (stream))

#define matrix_perspective_(fov, aspect, near, far, result) matrix4f_perspective((fov), (aspect), (near), (far), (result))

#define matrix_orthographic_(left, right, bottom, top, near, far, result)                                                                            \
    matrix4f_orthographic((left), (right), (bottom), (top), (near), (far), (result))

#define matrix_translate_(m, x, y, z, result) matrix4f_translate((m), (x), (y), (z), (result))

#define matrix_rotate_(m, radian, axis, result) matrix4f_rotate((m), (radian), (axis), (result))

#endif
