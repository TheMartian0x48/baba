#ifndef BABA_INPUT
#define BABA_INPUT

/*
    bool   clipboard_write(Str str);                // write  to clipboard
    char*  clipboard_read();                        // read from clipboard
    StrBuf clipboard_read_with_arena(Arena* arena); // read from clipboard but use arena for memory allocation
*/

#if defined(_WIN32)
#elif defined(__linux__)
#include "../platform/linux/clipboard.h"
#elif defined(__APPLE__)
#include "../platform/macos/clipboard.h"
#else
// Other OS headers
#endif

#endif
