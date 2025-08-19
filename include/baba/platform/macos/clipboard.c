
// #include "clipboard.h"
// #include <CoreFoundation/CoreFoundation.h>
// #include <objc/runtime.h>
//
// bool clipboard_write(Str str)
// {
//     SEL   generalPasteboardSelector = sel_registerName("generalPasteboard");
//     void* NSPasteboardClass         = objc_getClass("NSPasteboard");
//     void* pasteboard                = objc_msgSend(NSPasteboardClass, generalPasteboardSelector);
//
//     SEL clearContentsSelector = sel_registerName("clearContents");
//     objc_msgSend(pasteboard, clearContentsSelector);
//
//     void* NSStringClass                = objc_getClass("NSString");
//     SEL   stringWithUTF8StringSelector = sel_registerName("stringWithUTF8String:");
//     void* nsText                       = objc_msgSend(NSStringClass, stringWithUTF8StringSelector, text);
//
//     // Create an NSArray with the NSString
//     void* NSArrayClass            = objc_getClass("NSArray");
//     SEL   arrayWithObjectSelector = sel_registerName("arrayWithObject:");
//     void* array                   = objc_msgSend(NSArrayClass, arrayWithObjectSelector, nsText);
//
//     // Write the NSArray to the pasteboard
//     SEL writeObjectsSelector = sel_registerName("writeObjects:");
//     objc_msgSend(pasteboard, writeObjectsSelector, array);
// }
//
// char* clipboard_read() {}
//
// StrBuf clipboard_read_with_arena(Arena* arena) {}
