#include <_h_c_lib.h> /* Nothing in the file are used but this is to check clangd/IntelliSense working. */

static __inline int language_extension_inline_in_c_file(void);
static __inline int language_extension_inline_in_c_file(void)
{
    return 0b10101010;
}
int __callt language_extensions_in_c_file(void);
int __callt language_extensions_in_c_file(void)
{
    static int __saddr sv;
    static int __near nv;
    static int __far fv;
    int __far *pt = __sectop( ".bss" );
    int __far *pe = __secend( ".bss" );

    __nop();

    return language_extension_inline_in_c_file() + sv + nv + fv + *pt + *pe;
}

#if __STDC_VERSION__ > 201710L
const char *c_std = "C23";
#elif __STDC_VERSION__ >= 201710L
const char *c_std = "C17";
#elif __STDC_VERSION__ >= 201000L
const char *c_std = "C11";
#elif __STDC_VERSION__ >= 199901L
const char *c_std = "C99";
#elif __STDC_VERSION__ >= 199409L
const char *c_std = "C90";
#else
const char *c_std = "Unknown";
#if !defined(__STDC_VERSION__)
const char *c_ccrl = "C90";
#endif
#endif
/*
4.2.2 Macro
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0202y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0202y.html

__STDC_VERSION__
Decimal constant 199409L (defined when the -lang=c and -strict_std options are specified).Note1
Decimal constant 199901L (defined when the -lang=c99 option is specified).

Note 1.
For the processing to be performed when the -strict_std option is specified, see "-strict_std [V1.06 or later] / -ansi [V1.05 or earlier]".
*/

/*
3.2.2 Macros
https://www.renesas.com/us/en/document/mat/cc-rl-c14-technical-preview-version-users-manual
https://www.renesas.com/jp/ja/document/mat/cc-rl-c14-technical-preview-version-users-manual

Name             Definition when -lang=c or -lang=c99 is specified
__cplusplus      Undefined
__clang__        Undefined
__STDC_HOSTED__  0 (when -lang=c99 is specified), Undefined (otherwise)
__STDC__         1 (when -strict_std is specified), Undefined (otherwise)
__STDC_VERSION__ 199409L (when both -lang=c and -strict_std are specified)
                 199901L (when -lang=c99 is specified)
                 Undefined (otherwise)
__STDC_IEC_559__ 1 (when -lang=c99 is specified), Undefined (otherwise)
*/

#if defined(__cplusplus)
#error Error: The `__cplusplus` is defined in C source.
#endif
#if defined(__clang__)
#error Error: The `__clang__` is defined in C source.
#endif
#if (__STDC_VERSION__ >= 199901L)
#if !defined(__STDC_HOSTED__) || (__STDC_HOSTED__ != 0)
#error Error: The `__STDC_HOSTED__` is not equal to 0 in C99 source.
#endif
//FIXME: How to check?
//#if !defined(__STDC__) || (__STDC__ != 1)
//#error Error: The `__STDC__` is 
//#endif
#if !defined(__STDC_VERSION__)
#error Error: The `__STDC_VERSION__` is not defined in C source.
#endif
#if !defined(__STDC_IEC_559__) || (__STDC_IEC_559__ != 1)
#error Error: The `__STDC_IEC_559__` is not equal to 1 in C99 source.
#endif
#else /*  __STDC_VERSION__ >= 199901L */
#if defined(__STDC_HOSTED__)
#error Error: The `__STDC_HOSTED__` is defined in C90 source.
#endif
//FIXME: How to check?
//#if !defined(__STDC__) || (__STDC__ != 1)
//#error Error: The `__STDC__` is 
//#endif
//FIXME: How to check?
//#if !defined(__STDC_VERSION__)
//#error Error: The `__STDC_VERSION__` is 
//#endif
#if defined(__STDC_IEC_559__)
#error Error: The `__STDC_IEC_559__` is defined in C90 source.
#endif
#endif /*  __STDC_VERSION__ >= 199901L */