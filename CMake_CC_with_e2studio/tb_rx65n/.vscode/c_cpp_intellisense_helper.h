#ifndef C_CPP_INTELLISENSE_HELPER_H
#define C_CPP_INTELLISENSE_HELPER_H

#if defined(__INTELLISENSE__) || defined(_CLANGD)
#define __CDT_PARSER__ /* This might be a bad practice... */

/*
Tips to make IntelliSense or similar feature work with code written for Renesas CC-RX compiler
*/

/*
4.2.1 Macro Names
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0201y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0201y.html
*/
#define __CCRX__ 1
#define __RX 1
#define __LIT 1
// #define __BIG 1
 #define __FPU 1
// #define __RXV1 1
// #define __RXV2 1
#define __RXV3 1
#define __TFU 1
#define __DPFPU 1

#if defined(__STDC_VERSION__) || !defined(__cplusplus)
  /* Be aware that clangd and IntelliSense don't define __STDC_VERSION__ when -std=c90 is specified. */
  #if defined(__STDC_VERSION__)
    #undef __STDC_VERSION__
  #endif
  #if !defined(INTELISENSE_HELPER_C_STANDARD)
    /* In certain C90 cases, the above macro can't be defined by support module for Renesas CC compilers which works along with CMake. */
    #define __STDC_VERSION__ 199409L
  #elif (INTELISENSE_HELPER_C_STANDARD == 90)
    /* C90 */
    #define __STDC_VERSION__ 199409L
  #elif (INTELISENSE_HELPER_C_STANDARD == 99)
    /* C99 */
    #define __STDC_VERSION__ 199901L
  #endif
#endif
/*
lang=c*1 lang=c99
__STDC_VERSION__ 199409L(lang=c*1) 199901L(lang=c99)

Notes 1.
Includes cases where a file with the .c extension is compiled without specifying the -lang option.

4.1.7 Conforming Language Specifications
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html

C Language Specifications (When the lang=c Option is Selected)
ANSI/ISO 9899-1990 American National Standard for Programming Languages -C

C Language Specifications (When the lang=c99 Option is Selected)
ISO/IEC 9899:1999 INTERNATIONAL STANDARD Programming Languages - C
*/

#if defined(__cplusplus)
#undef __cplusplus
#define __cplusplus 1
#endif
/*
lang=cpp*2 lang=ecpp
__cplusplus 1

Notes 2.
Includes cases where a file with the .cpp, .cp, or .cc extension is compiled without specifying the -lang option.

4.1.7 Conforming Language Specifications
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html

C++ Language Specifications (When the lang=cpp Option is Selected)
Based on the language specifications compatible with Microsoft(R) Visual C/C++ 6.0
*/

/*
4.2.2 Keywords
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0202y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0202y.html
*/
#define __evenaccess

/*
4.2.3 #pragma Directive
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0203y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0203y.html
*/
#if defined(__INTELLISENSE__)
#pragma diag_suppress 661
#endif
#if defined(_CLANGD)
#pragma clang diagnostic ignored "-Wignored-pragmas"
#pragma clang diagnostic ignored "-Winvalid-token-paste" // #pragma stacksize (su|si)=NUM // why?
#endif

/*
4.2.6 Intrinsic Functions
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0206y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0206y.html
*/
#include <builtin.h>

/*
4.2.7 Section Address Operators
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0207y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0207y.html
*/
#define __sectop( secname )  ( ( void * ) 0U )
#define __secend( secname )  ( ( void * ) 0U )
#define __secsize( secname ) ( 0UL )

/*
For other differnce between CC-RX and MSVC/Clang
*/
#if defined(_WIN32)
#undef _WIN32
#endif
#if defined(_MSC_VER)
#undef _MSC_VER
#endif
#if defined(__INTELLISENSE__)
#endif
#if defined(_CLANGD)
#endif

#endif /* defined(__INTELLISENSE__) || defined(_CLANGD) */

#endif /* C_CPP_INTELLISENSE_HELPER_H */
