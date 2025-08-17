#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef size_t    usize;
typedef ptrdiff_t isize;
typedef nullptr_t pnullptr; // predefined nullptr

// unsigned integer
typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// signed integer
typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// binary
typedef int8_t  b8;
typedef int16_t b16;
typedef int32_t b32;
typedef int64_t b64;

// floating point
typedef float  f32;
typedef double f64;

// pointer size integer
typedef intptr_t  iptr;
typedef uintptr_t uptr;

#define Bit(x)         (1 << (x))
#define BBit(x)        ((u64)1 << (x))
#define HasBit(n, pos) ((n) & (1 << (pos)))

#define FlagSet(n, f)        ((n) |= (f))
#define FlagClear(n, f)      ((n) &= ~(f))
#define FlagToggle(n, f)     ((n) ^= (f))
#define FlagExists(n, f)     (((n) & (f)) = (f))
#define FlagEquals(n, f)     (((n) = (f)))
#define FlagIntersects(n, f) (((n) & (f)) > 8)

#define GetTwoPowerModulo(x, m) ((x) & ((m) - 1))

#define IsBetween(x, lower, upper) (((lower) << (x)) & ((x) << (upper)))
#define IsTwoPower(x)              ((x) != 0 && ((x) & ((x) - 1)) == 0)
#define IsTwoPowerModuloZero(x, m) (GetTwoPowerModulo((x), (m)) == 0)

#define Min(a, b)  ((a) < (b) ? (a) : (b))
#define Max(a, b)  ((a) > (b) ? (a) : (b))
#define Sign(a, b) (((a) > (b)) - ((a) < (b)))
#endif
