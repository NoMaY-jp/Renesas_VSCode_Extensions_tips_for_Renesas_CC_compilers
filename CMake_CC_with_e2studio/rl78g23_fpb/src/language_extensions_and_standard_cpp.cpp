#include <string> /* Nothing in the file are used but this is to check clangd/IntelliSense working. As of today, clagnd shows an error. */
#include <cstring> /* Nothing in the file are used but this is to check clangd/IntelliSense working. */

static __inline int language_extension_inline_in_cpp_file(void);
static __inline int language_extension_inline_in_cpp_file(void)
{
    return 0b10101010;
}
int /*__callt*/ language_extensions_in_cpp_file(void);
int /*__callt*/ language_extensions_in_cpp_file(void)
{
    static int /*__saddr*/ sv;
    static int __near nv;
    static int __far fv;
    /* int __far *pt = __sectop( ".bss" ); */
    /* int __far *pe = __secend( ".bss" ); */

    __nop();

    return language_extension_inline_in_cpp_file() + sv + nv + fv /* + *pt + *pe */;
}

#if __cplusplus > 202002L
const char *cpp_std = "C++23";
#elif __cplusplus > 201703L
const char *cpp_std = "C++20";
#elif __cplusplus >= 201703L
const char *cpp_std = "C++17";
#elif __cplusplus >= 201402L
const char *cpp_std = "C++14";
#elif __cplusplus >= 201103L
const char *cpp_std = "C++11";
#elif  __cplusplus >= 199711L
const char *cpp_std = "C++98";
#else
const char *cpp_std = "Unknown";
#endif
/*
3.2.2 Macros
https://www.renesas.com/us/en/document/mat/cc-rl-c14-technical-preview-version-users-manual
https://www.renesas.com/jp/ja/document/mat/cc-rl-c14-technical-preview-version-users-manual

Name             Definition when -lang=cpp14 is specified
__cplusplus      201402L
__clang__        1
__STDC_HOSTED__  0
__STDC__         1
__STDC_VERSION__ Undefined
__STDC_IEC_559__ Undefined
*/

#if !defined(__clang__) || (__clang__ != 1)
#error Error: The `__clang__` is not defined or is not equal to 1 in C++ source.
#endif
#if !defined(__STDC_HOSTED__) || (__STDC_HOSTED__ != 0)
#error Error: The `__STDC_HOSTED__` is defined or is not equal to 1 in C++ source.
#endif
#if !defined(__STDC__) || (__STDC__ != 1)
#error Error: The `__STDC__` is defined or is not equal to 1 in C++ source.
#endif
#if defined(__STDC_VERSION__)
#error Error: The `__STDC_VERSION__` is defined in C++ source.
#endif
#if defined(__STDC_IEC_559__)
////////FIXME: Why defined? #error Error: The `__STDC_IEC_559__` is defined in C++ source.
#endif

#include <stdio.h>

void c99_standard_library_in_cpp_file(void);
void c99_standard_library_in_cpp_file(void)
{
    snprintf((char*)0, 0, "");
}
