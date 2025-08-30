#ifndef TYPES_H
#define TYPES_H

#include <math.h>
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

typedef enum {
    TYPE_U8,
    TYPE_U16,
    TYPE_U32,
    TYPE_U64,

    TYPE_I8,
    TYPE_I16,
    TYPE_I32,
    TYPE_I64,

    TYPE_F32,
    TYPE_F64,

    TYPE_B8,
    TYPE_B16,
    TYPE_B32,
    TYPE_B64,

    TYPE_UPTR,
    TYPE_IPTR,

    TYPE_USIZE,
    TYPE_ISIZE,

    TYPE_PNULPTR,
} PrimitiveType;

#define _UnsupportedTypeException(x, ...) _Static_assert(0, "Unsupported type at " __FILE__ ":" _STR(__LINE__) " — " __VA_ARGS__)

#define _STR(x) _VAL(x)
#define _VAL(x) #x

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
#define Abs(x)     ((x) >= 0 ? (x) : -(x))

u8  _identity_u8(u8 x) { return x; }
u16 _identity_u16(u16 x) { return x; }
u32 _identity_u32(u32 x) { return x; }
u64 _identity_u64(u64 x) { return x; }
i8  _identity_i8(i8 x) { return x; }
i16 _identity_i16(i16 x) { return x; }
i32 _identity_i32(i32 x) { return x; }
i64 _identity_i64(i64 x) { return x; }
f32 _identity_f32(f32 x) { return x; }
f64 _identity_f64(f64 x) { return x; }
b8  _identity_b8(b8 x) { return x; }
b16 _identity_b16(b16 x) { return x; }
b32 _identity_b32(b32 x) { return x; }
b64 _identity_b64(b64 x) { return x; }

#define Ceil(x)                                                                                                                                      \
    _Generic((x),                                                                                                                                    \
        f32: ceilf,                                                                                                                                  \
        f64: ceil,                                                                                                                                   \
        u8: _identity_u8,                                                                                                                            \
        u16: _identity_u16,                                                                                                                          \
        u32: _identity_u32,                                                                                                                          \
        u64: _identity_u64,                                                                                                                          \
        i8: _identity_i8,                                                                                                                            \
        i16: _identity_i16,                                                                                                                          \
        i32: _identity_i32,                                                                                                                          \
        i64: _identity_i64)((x))

#define Floor(x)                                                                                                                                     \
    _Generic((x),                                                                                                                                    \
        f32: floorf,                                                                                                                                 \
        f64: floor,                                                                                                                                  \
        u8: _identity_u8,                                                                                                                            \
        u16: _identity_u16,                                                                                                                          \
        u32: _identity_u32,                                                                                                                          \
        u64: _identity_u64,                                                                                                                          \
        i8: _identity_i8,                                                                                                                            \
        i16: _identity_i16,                                                                                                                          \
        i32: _identity_i32,                                                                                                                          \
        i64: _identity_i64)((x))

#endif
