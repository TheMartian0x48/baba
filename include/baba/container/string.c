#include "../memory/memory.h"
#include "container.h"

#include <stdio.h>
#include <string.h>

//***** StrBuf Implementation *****

StrBuf str_buf_make(Arena* arena, u64 capacity) { return str_buf_make_aligned(arena, capacity, DEFAULT_ALIGNMENT); }

StrBuf str_buf_make_aligned(Arena* arena, u64 capacity, u64 alignment)
{
    StrBuf str_buf = {0};

    str_buf.header.size     = 0;
    str_buf.header.capacity = capacity;

    char* ptr = arena_alloc(arena, capacity, alignment);
    str_buf.v = ptr;
    return str_buf;
}

StrBuf str_buf_make_from_cstr(Arena* arena, const char* str) { return str_buf_make_aligned_from_cstr(arena, str, DEFAULT_ALIGNMENT); }

StrBuf str_buf_make_aligned_from_cstr(Arena* arena, const char* str, u64 alignment)
{
    u64    len     = strlen(str);
    StrBuf str_buf = {0};

    if (len == 0) {
        return str_buf;
    }

    str_buf.header.size     = len - 1;
    str_buf.header.capacity = len - 1;

    char* ptr = arena_alloc(arena, len - 1, alignment);
    str_buf.v = ptr;
    mem_copy(ptr, str, len - 1);
    return str_buf;
}

void str_buf_kill(Arena* arena, StrBuf* str_buf)
{
    if (str_buf) {
        str_buf->header.capacity = 0;
        str_buf->header.size     = 0;
        arena_dealloc(arena, str_buf);
    }
}

bool str_buf_append(StrBuf* str_buf, const char* str)
{
    // TODO: implement this function
    return false;
}

bool str_buf_append_formatted(Arena* arena, StrBuf* str_buf, const char* str, ...)
{
    // TODO: implement this function
    return false;
}

bool str_buf_empty(const StrBuf* str_buf) { return str_buf->header.size == 0; }

u64 str_buf_len(const StrBuf* str_buf) { return str_buf->header.size; }

u64 str_buf_capacity(const StrBuf* str_buf) { return str_buf->header.capacity; }

i64 str_buf_cmp(const StrBuf* left, Str right)
{
    u64 len    = Min(left->header.size, right.len);
    u64 result = mem_cmp(left->v, right.buffer, len);
    return result == 0 ? Sign(left->header.size, right.len) : result;
}

i64 str_buf_cmp_n(const StrBuf* left, Str right, u64 n)
{
    u64 len = Min(n, Min(left->header.size, right.len));
    return mem_cmp(left->v, right.buffer, len);
}

i64 str_buf_find_char(const StrBuf* str_buf, char ch)
{
    char* start = str_buf->v;
    if (start == nullptr) {
        return -1;
    }
    char* end = start + str_buf->header.size;
    while (start < end && *start != ch) {
        start++;
    }

    return start == end ? start - str_buf->v : -1;
}

i64 str_buf_find_char_reverse(const StrBuf* str_buf, char ch)
{
    char* start = str_buf->v;
    char* end   = start + str_buf->header.size - 1;

    while (start <= end && *end != ch)
        end--;

    return start == end ? end - start : -1;
}

bool str_buf_contain_char(const StrBuf* str_buf, char ch) { return str_buf_find_char(str_buf, ch) > -1; }

Str str_buf_substr(const StrBuf* str_buf, u64 index, u64 len)
{
    Str str = {0};
    if (index >= str_buf->header.size) {
        return str;
    }
    len        = Min(len, str_buf->header.size - index);
    str.len    = len;
    str.buffer = str_buf->v + index;
    return str;
}

Str str_buf_strip_prefix_char(const StrBuf* str_buf, char ch)
{
    Str result = {0};

    char* start = str_buf->v;
    char* end   = str_buf->v + str_buf->header.size;

    while (start < end && *start == ch)
        start++;

    result.buffer = start;
    result.len    = end - start;
    return result;
}

bool str_buf_contain_str(const StrBuf* str_buf, Str pattern)
{
    fprintf(stderr, "[%s : %d] str_buf_contain_str is not implemented", __FILE__, __LINE__);
    exit(-1);
}

bool str_buf_start_with(const StrBuf* str_buf, Str pattern)
{
    fprintf(stderr, "[%s : %d] str_buf_start_with is not implemented", __FILE__, __LINE__);
    exit(-1);
}
bool str_buf_end_with(const StrBuf* str_buf, Str pattern)
{
    fprintf(stderr, "[%s : %d] str_buf_end_with is not implemented", __FILE__, __LINE__);
    exit(-1);
}
Str str_buf_strip_prefix(const StrBuf* str_buf, Str prefix)
{
    fprintf(stderr, "[%s : %d] str_buf_strip_prefix is not implemented", __FILE__, __LINE__);
    exit(-1);
}
Str str_buf_strip_suffix(const StrBuf* str_buf, Str suffix)
{
    fprintf(stderr, "[%s : %d] str_buf_strip_suffix is not implemented", __FILE__, __LINE__);
    exit(-1);
}
StrBuf str_buf_copy(Arena* arena, const StrBuf* str_buf)
{
    fprintf(stderr, "[%s : %d] str_buf_copy is not implemented", __FILE__, __LINE__);
    exit(-1);
}

Str str_buf_strip_suffix_char(const StrBuf* str_buf, char ch)
{
    fprintf(stderr, "[%s : %d] str_buf_strip_suffix_char is not implemented", __FILE__, __LINE__);
    exit(-1);
}
Str str_buf_strip(const StrBuf* str_buf, Str pattern)
{
    fprintf(stderr, "[%s : %d] str_buf_strip is not implemented", __FILE__, __LINE__);
    exit(-1);
}
Str str_buf_strip_char(const StrBuf* str_buf, char ch)
{
    fprintf(stderr, "[%s : %d] str_buf_strip_char is not implemented", __FILE__, __LINE__);
    exit(-1);
}

void str_buf_lowercase(StrBuf* str_buf)
{
    fprintf(stderr, "[%s : %d] str_buf_lowercase is not implemented", __FILE__, __LINE__);
    exit(-1);
}
void str_buf_uppercase(StrBuf* str_buf)
{
    fprintf(stderr, "[%s : %d] str_buf_uppercase is not implemented", __FILE__, __LINE__);
    exit(-1);
}
//***** Str Implementation *****

extern inline bool str_empty(Str str) { return str.len == 0; }

extern inline u64 str_len(Str str) { return str.len; }

extern inline char str_at(Str str, u64 at) { return str.buffer[at]; }

i64 str_cmp(Str left, Str right)
{
    u64 len = Min(left.len, right.len);

    const char* lhs = left.buffer;
    const char* rhs = right.buffer;

    i64 result = mem_cmp(lhs, rhs, len);
    return result ? result : Sign(left.len, right.len);
}

i64 str_cmp_n(Str left, Str right, u64 n)
{
    u64 len = Min(Min(left.len, right.len), n);

    const char* lhs = left.buffer;
    const char* rhs = right.buffer;

    u64 result = mem_cmp(lhs, rhs, len);

    return result ? result : Sign(left.len, right.len);
}

i64 str_find_char(Str str, char ch)
{
    u64   len    = str.len;
    char* buffer = str.buffer;
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
    char* buffer = str.buffer;
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

    char* buffer  = str.buffer;
    char* pbuffer = pattern.buffer;

    return mem_cmp(buffer, pbuffer, plen) == 0;
}

bool str_end_with(Str str, Str pattern)
{
    u64 len  = str.len;
    u64 plen = pattern.len;

    if (plen > len) {
        return false;
    }

    char* buffer  = str.buffer + (len - plen);
    char* pbuffer = pattern.buffer;

    return mem_cmp(buffer, pbuffer, plen) == 0;
}

Str str_substr(Str str, u64 index, u64 len)
{
    Str result = {0};

    if (index >= str.len) {
        return result;
    }

    result.len    = Min(len, str.len - index);
    result.buffer = str.buffer + index;

    return result;
}

Str str_copy(Str str)
{
    Str result    = {0};
    result.buffer = str.buffer;
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

    char* buffer  = str.buffer;
    char* pbuffer = prefix.buffer;

    const char* end = buffer + len;

    while (buffer < end && *buffer == *pbuffer) {
        buffer++;
        pbuffer++;
    }

    if (buffer < end) {
        return str;
    }

    Str result    = {0};
    result.buffer = str.buffer + plen;
    result.len    = len - plen;
    return result;
}

Str str_strip_prefix_char(Str str, char ch)
{
    char* buffer = str.buffer;
    char* start  = buffer;
    char* end    = buffer + str.len;

    while (start < end && *start == ch) {
        start++;
    }

    Str result    = {0};
    result.buffer = str.buffer + (start - buffer);
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

    char* buffer  = str.buffer;
    char* end     = buffer + len - 1;
    char* sbuffer = suffix.buffer;
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
    return result;
}

Str str_strip_suffix_char(Str str, char ch)
{
    char* buffer = str.buffer;
    char* start  = buffer;
    char* end    = buffer + str.len - 1;

    while (start < end && *end == ch) {
        end--;
    }

    Str result    = {0};
    result.buffer = str.buffer;
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
    char* buffer = str.buffer;
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
    result.len    = Max(end - start + 1, 0);

    return result;
}

char* str_to_cstr(const Str str)
{
    if (str.len == 0) {
        return nullptr;
    }
    char* ptr = malloc(str.len + 1);
    if (ptr == nullptr) {
        return nullptr;
    }
    const char* buffer = str.buffer;
    mem_copy(ptr, buffer, str.len);
    ptr[str.len] = '\0';
    return ptr;
}

bool str_contain_str(Str str, Str pattern)
{
    fprintf(stderr, "[%s : %d] str_contain_str is not implemented", __FILE__, __LINE__);
    exit(-1);
}

StrBuf str_copy_deep(Arena* arena, Str str)
{
    fprintf(stderr, "[%s : %d] str_copy_deep is not implemented", __FILE__, __LINE__);
    exit(-1);
}
