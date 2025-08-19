#ifndef BABA_PLATFORM_LINUX_CLIPBOARD
#define BABA_PLATFORM_LINUX_CLIPBOARD

#include "../../containers/container.h"

bool   clipboard_write(Str str);                // write  to clipboard
char*  clipboard_read();                        // read from clipboard
StrBuf clipboard_read_with_arena(Arena* arena); // read from clipboard but use arena for memory allocation

#endif
