#ifndef C_CPP_INTELLISENSE_HELPER_H
#define C_CPP_INTELLISENSE_HELPER_H

#if defined(__INTELLISENSE__) || defined(_CLANGD)
#define __CDT_PARSER__ /* This might be a bad practice... */

/*
Tips to make IntelliSense work with code written for Renesas CC-RH compiler
*/

/*
4.2.2 Macro
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0202y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0202y.html
*/
#define __CCRH__ 1
#define __RH850__ 1
#define __v850e3v5__ 1

/*
4.2.5 #pragma directive
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0205y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0205y.html
*/
#if defined(__INTELLISENSE__)
#pragma diag_suppress 661
#endif
#if defined(_CLANGD)
#pragma clang diagnostic ignored "-Wignored-pragmas"
#endif

/*
4.2.6.7 Intrinsic functions
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y0700.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y0700.html
*/
#include <builtin.h>

/*
4.2.6.13 Half-precision floating-point type [Professional Edition only] [V1.05.00 or later]
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y1300.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y1300.html
*/
#if defined(__INTELLISENSE__)
#define __fp16 float /* Clang supports __fp16. MSVC doesn't support __fp16. */
#endif

/*
For other differnce between CC-RH and MSVC/Clang
*/
#if defined(__INTELLISENSE__)
#endif
#if defined(_CLANGD)
#endif

#endif /* defined(__INTELLISENSE__) || defined(_CLANGD) */

#endif /* C_CPP_INTELLISENSE_HELPER_H */
