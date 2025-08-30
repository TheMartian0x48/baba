#include "math.h"

#include <tgmath.h>

f32 exp_f(const f32 x) { return exp(x); }
f64 exp_d(const f64 x) { return exp(x); }
f32 exp2_f(const f32 x) { return exp2(x); }
f64 exp2_d(const f64 x) { return exp2(x); }
f32 log_f(const f32 x) { return log(x); }
f64 log_d(const f64 x) { return log(x); }
f32 log10_f(const f32 x) { return log10(x); }
f64 log10_d(const f64 x) { return log10(x); }
f32 log2_f(const f32 x) { return log2(x); }
f64 log2_d(const f64 x) { return log2(x); }
f32 pow_f(const f32 base, const f32 exp) { return pow(base, exp); }
f64 pow_d(const f64 base, const f64 exp) { return pow(base, exp); }
f32 sqrt_f(const f32 x) { return sqrt(x); }
f64 sqrt_d(const f64 x) { return sqrt(x); }
f32 cbrt_f(const f32 x) { return cbrt(x); }
f64 cbrt_d(const f64 x) { return cbrt(x); }
f32 hypot_f(const f32 x, const f32 y) { return hypot(x, y); }
f64 hypot_d(const f64 x, const f64 y) { return hypot(x, y); }

f32 sin_f(const f32 rad) { return sin(rad); }
f64 sin_d(const f64 rad) { return sin(rad); }
f32 cos_f(const f32 rad) { return cos(rad); }
f64 cos_d(const f64 rad) { return cos(rad); }
f32 tan_f(const f32 rad) { return tan(rad); }
f32 tan_d(const f64 rad) { return tan(rad); }
f32 arc_sin_f(const f32 rad) { return asin(rad); }
f64 arc_sin_d(const f64 rad) { return asin(rad); }
f32 arc_cos_f(const f32 rad) { return acos(rad); }
f64 arc_cos_d(const f64 rad) { return acos(rad); }
f32 arc_tan_f(const f32 rad) { return atan(rad); }
f32 arc_tan_d(const f64 rad) { return atan(rad); }

f32 angle_to_radian_f(const f32 angle) { return angle * RADIAN; }
f32 radian_to_angle_f(const f32 radian) { return radian * DEGREE; }
f64 angle_to_radian_d(const f64 angle) { return angle * (f64)RADIAN; }
f64 radian_to_angle_d(const f64 radian) { return radian * (f64)DEGREE; }
