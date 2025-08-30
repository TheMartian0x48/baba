#include "math.h"

#include <tgmath.h>

f32 expf(const f32 x) { return exp(x); }
f64 expd(const f64 x) { return exp(x); }
f32 exp2f(const f32 x) { return exp2(x); }
f64 exp2d(const f64 x) { return exp2(x); }
f32 logf(const f32 x) { return log(x); }
f64 logd(const f64 x) { return log(x); }
f32 log10f(const f32 x) { return log10(x); }
f64 log10d(const f64 x) { return log10(x); }
f32 log2f(const f32 x) { return log2(x); }
f64 log2d(const f64 x) { return log2(x); }
f32 powf(const f32 base, const f32 exp) { return pow(base, exp); }
f64 powd(const f64 base, const f64 exp) { return pow(base, exp); }
f32 sqrtf(const f32 x) { return sqrt(x); }
f64 sqrtd(const f64 x) { return sqrt(x); }
f32 cbrtf(const f32 x) { return cbrt(x); }
f64 cbrtd(const f64 x) { return cbrt(x); }
f32 hypotf(const f32 x, const f32 y) { return hypot(x, y); }
f64 hypotd(const f64 x, const f64 y) { return hypot(x, y); }

f32 sinf(const f32 rad) { return sin(rad); }
f64 sind(const f64 rad) { return sin(rad); }
f32 cosf(const f32 rad) { return cos(rad); }
f64 cosd(const f64 rad) { return cos(rad); }
f32 tanf(const f32 rad) { return tan(rad); }
f32 tand(const f64 rad) { return tan(rad); }
f32 arc_sinf(const f32 rad) { return asin(rad); }
f64 arc_sind(const f64 rad) { return asin(rad); }
f32 arc_cosf(const f32 rad) { return acos(rad); }
f64 arc_cosd(const f64 rad) { return acos(rad); }
f32 arc_tanf(const f32 rad) { return atan(rad); }
f32 arc_tand(const f64 rad) { return atan(rad); }
