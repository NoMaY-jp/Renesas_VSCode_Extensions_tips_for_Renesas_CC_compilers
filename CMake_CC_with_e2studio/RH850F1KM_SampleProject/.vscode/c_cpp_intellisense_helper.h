#ifndef C_CPP_INTELLISENSE_HELPER_H
#define C_CPP_INTELLISENSE_HELPER_H

#ifdef __INTELLISENSE__
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
4.2.6.13 Half-precision floating-point type [Professional Edition only] [V1.05.00 or later]
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y1300.html#29532
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y1300.html#29532
*/
//#define __fp16 float /* Clang supports this. MSVC doesn't support this. */
 
/*
4.2.4 #pragma directive
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0205y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0205y.html
*/
//#pragma diag_suppress 661 /* This is the case for MSVC IntelliSence */

/*
4.2.6.7 Intrinsic functions
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y0700.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0206y0700.html
*/
#include <builtin.h>

#endif /* __INTELLISENSE__ */

#endif /* C_CPP_INTELLISENSE_HELPER_H */
