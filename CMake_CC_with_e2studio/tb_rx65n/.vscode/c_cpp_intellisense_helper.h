#ifndef C_CPP_INTELLISENSE_HELPER_H
#define C_CPP_INTELLISENSE_HELPER_H

#if defined(__INTELLISENSE__) || defined(_CLANGD)
#define __CDT_PARSER__ /* This might be a bad practice... */

/*
Tips to make IntelliSense work with code written for Renesas CC-RX compiler
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
#if defined(__INTELLISENSE__)
#endif
#if defined(_CLANGD)
#endif

#endif /* defined(__INTELLISENSE__) || defined(_CLANGD) */

#endif /* C_CPP_INTELLISENSE_HELPER_H */
