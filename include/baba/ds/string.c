#include "../memory/memory.h"
#include "ds.h"
#include <string.h>

//***** StrBuf Implementation *****

StrBuf str_buf_make(Arena* arena, u64 capacity) { return str_buf_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }

StrBuf str_buf_make_aligned(Arena* arena, u64 capacity, u64 alignment)
{
    StrBuf str_buf = {0};

    str_buf.header.alignment = alignment;
    str_buf.header.size      = 0;
    str_buf.header.capacity  = capacity;
    str_buf.header.arena     = arena;

    char* ptr = arena_alloc(arena, capacity, alignment);
    str_buf.v = ptr;
    return str_buf;
}

StrBuf str_buf_make_from_cstr(Arena* arena, const char* str)
{
    return str_buf_make_aligned_from_cstr(arena, str, DEFAULT_ALIGNMENT);
}

StrBuf str_buf_make_aligned_from_cstr(Arena* arena, const char* str, u64 alignment)
{
    u64    len     = strlen(str);
    StrBuf str_buf = {0};

    str_buf.header.alignment = alignment;
    str_buf.header.size      = len;
    str_buf.header.capacity  = len;
    str_buf.header.arena     = arena;

    char* ptr = arena_alloc(arena, len, alignment);
    str_buf.v = ptr;
    mem_copy(ptr, str, len);
    return str_buf;
}

void str_buf_kill(StrBuf* str_buf)
{
    if (str_buf) {
        str_buf->header.capacity  = 0;
        str_buf->header.alignment = 0;
        str_buf->header.size      = 0;
        str_buf->header.arena     = nullptr;
        str_buf->v                = nullptr;
    }
}

bool str_buf_append(StrBuf* str_buf, const char* str) {}

bool str_buf_append_formatted(StrBuf* str_buf, const char* str, ...);

bool str_buf_empty(const StrBuf* str_buf) { return str_buf->header.size == 0; }

u64 str_buf_len(const StrBuf* str_buf) { return str_buf->header.size; }

u64 str_buf_capacity(const StrBuf* str_buf) { return str_buf->header.capacity; }

Arena* str_buf_arena(const StrBuf* str_buf) { return str_buf->header.arena; }

char str_buf_at(const StrBuf* str_buf, u64 at) { return str_buf->v[at]; }

//
i64 str_buf_cmp(const StrBuf* left, const StrBuf* right)
{
    u64 len    = Min(left->header.size, right->header.size);
    u64 result = mem_cmp(left->v, right->v, len);
    return result == 0 ? Sign(left->header.size, right->header.size) : result;
}

i64 str_buf_cmp_n(const StrBuf* left, const StrBuf* right, u64 n)
{
    u64 len = Min(n, Min(left->header.size, right->header.size));
    return mem_cmp(left->v, right->v, len);
}

i64 str_buf_find_char(const StrBuf* str_buf, char ch)
{
    u64         len = str_buf->header.size;
    const char* buf = str_buf->v;
    for (u64 i = 0; i < len; i++) {
        if (ch == buf[i])
            return i;
    }
    return -1;
}

i64 str_buf_find_char_reverse(const StrBuf* str_buf, char ch)
{
    u64         len = str_buf->header.size;
    const char* buf = str_buf->v;
    for (i64 i = len - 1; i >= 0; i--) {
        if (ch == buf[i])
            return i;
    }
    return -1;
}

bool str_buf_contain_char(const StrBuf* str_buf, char ch) { return str_buf_find_char(str_buf, ch) > -1; }

Str str_buf_substr(StrBuf* str_buf, u64 index, u64 len)
{
    Str str    = {0};
    str.buffer = str_buf;
    if (index >= str_buf->header.size) {
        str.index = 0;
        str.len   = 0;
        return str;
    }
    len       = Min(len, str_buf->header.size - index);
    str.index = index;
    str.len   = len;
    return str;
}

Str str_buf_strip_prefix_char(StrBuf* str_buf, char ch)
{
    Str result = {0};

    char* start = str_buf->v;
    char* end   = str_buf->v + str_buf->header.size;

    while (start < end && *start == ch)
        start++;

    return result;
}

//***** Str Implementation *****

inline char* str_buffer(Str str) { return str.buffer->v + str.index; }

extern inline bool str_empty(Str str) { return str.len == 0; }

extern inline u64 str_len(Str str) { return str.len; }

extern inline char str_at(Str str, u64 at) { return str.buffer->v[str.index + at]; }

i64 str_cmp(Str left, Str right)
{
    u64 len = Min(left.len, right.len);

    const char* lhs = str_buffer(left);
    const char* rhs = str_buffer(right);

    i64 result = mem_cmp(lhs, rhs, len);
    return result ? result : Sign(left.len, right.len);
}

i64 str_cmp_n(Str left, Str right, u64 n)
{
    u64 len = Min(Min(left.len, right.len), n);

    const char* lhs = str_buffer(left);
    const char* rhs = str_buffer(right);

    u64 result = mem_cmp(lhs, rhs, len);

    return result ? result : Sign(left.len, right.len);
}

i64 str_find_char_version(Str str, char ch)
{
    u64   len    = str.len;
    char* buffer = str_buffer(str);
    char* start  = buffer;
    char* end    = buffer + len;

    while (start < end && *start != ch) {
        start++;
    }

    return start < end ? (start - buffer) : -1;
}

i64 str_find_char_reverse(Str str, char ch)
{
    u64   len    = str.len;
    char* buffer = str_buffer(str);
    char* start  = buffer;
    char* end    = buffer + len - 1;

    while (start <= end && *end == ch) {
        end--;
    }

    return start <= end ? (end - start) : -1;
}

extern inline bool str_contain_char(Str str, char ch) { return str_find_char(str, ch) != -1; }

bool str_start_with(Str str, Str pattern)
{
    u64 len  = str.len;
    u64 plen = pattern.len;

    if (plen > len) {
        return false;
    }

    char* buffer  = str_buffer(str);
    char* pbuffer = str_buffer(pattern);

    return mem_cmp(buffer, pbuffer, plen) == 0;
}

bool str_end_with(Str str, Str pattern)
{
    u64 len  = str.len;
    u64 plen = pattern.len;

    if (plen > len) {
        return false;
    }

    char* buffer  = str_buffer(str) + (len - plen);
    char* pbuffer = str_buffer(pattern);

    return mem_cmp(buffer, pbuffer, plen) == 0;
}

Str str_substr(Str str, u64 index, u64 len)
{
    Str result    = {0};
    result.buffer = str.buffer;

    if (index >= str.len) {
        result.len   = 0;
        result.index = str.index;
        return result;
    }

    result.len   = Min(len, str.len - index);
    result.index = str.index + index;

    return result;
}

Str str_copy(Str str)
{
    Str result    = {0};
    result.buffer = str.buffer;
    result.index  = str.index;
    result.len    = str.len;

    return result;
}

Str str_strip_prefix(Str str, Str prefix)
{
    const u64 len  = str.len;
    const u64 plen = prefix.len;
    if (plen > len) {
        return str;
    }

    char* buffer  = str_buffer(str);
    char* pbuffer = str_buffer(prefix);

    const char* end = buffer + len;

    while (buffer < end && *buffer == *pbuffer) {
        buffer++;
        pbuffer++;
    }

    if (buffer < end) {
        return str;
    }

    Str result    = {0};
    result.buffer = str.buffer;
    result.len    = len - plen;
    result.index  = str.index + plen;
    return result;
}

Str str_strip_prefix_char(Str str, char ch)
{
    u64 len = str.len;

    char* buffer = str_buffer(str);
    char* start  = buffer;
    char* end    = buffer + str.len;

    while (start < end && *start == ch) {
        start++;
    }

    Str result    = {0};
    result.buffer = str.buffer;
    result.index  = start - buffer;
    result.len    = end - start;
    return result;
}

Str str_strip_suffix(Str str, Str suffix)
{
    const u64 len  = str.len;
    const u64 slen = suffix.len;
    if (slen > len) {
        return str;
    }

    char* buffer  = str_buffer(str);
    char* end     = buffer + len - 1;
    char* sbuffer = str_buffer(suffix);
    char* send    = sbuffer + slen - 1;

    while (send >= sbuffer && *end == *send) {
        end--;
        send--;
    }

    if (send >= sbuffer) {
        return str;
    }

    Str result    = {0};
    result.buffer = str.buffer;
    result.len    = len - slen;
    result.index  = str.index;
    return result;
}

Str str_strip_suffix_char(Str str, char ch)
{
    u64 len = str.len;

    char* buffer = str_buffer(str);
    char* start  = buffer;
    char* end    = buffer + str.len - 1;

    while (start < end && *end == ch) {
        end--;
    }

    Str result    = {0};
    result.buffer = str.buffer;
    result.index  = str.index;
    result.len    = Max(end - start, 0);
    return result;
}

extern inline Str str_strip(Str str, Str pattern)
{
    Str result = str_strip_prefix(str, pattern);
    return str_strip_suffix(result, pattern);
}

Str str_strip_char(Str str, char ch)
{
    u64 len = str.len;

    char* buffer = str_buffer(str);
    char* start  = buffer;
    char* end    = buffer + str.len - 1;

    while (start <= end && *start == ch) {
        start++;
    }

    while (start <= end && *end == ch) {
        end--;
    }

    Str result    = {0};
    result.buffer = str.buffer;
    result.index  = start - buffer;
    result.len    = Max(end - start + 1, 0);

    return result;
}
