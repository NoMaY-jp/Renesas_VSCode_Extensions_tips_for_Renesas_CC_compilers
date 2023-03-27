#ifndef C_CPP_INTELLISENSE_HELPER_H
#define C_CPP_INTELLISENSE_HELPER_H

#if defined(__INTELLISENSE__) || defined(_CLANGD)
#define __CDT_PARSER__ /* This might be a bad practice... */

#if !defined( __GNUC__) && !defined( __llvm__ )

/*
Tips to make IntelliSense or similar feature work with code written for Renesas CC-RL compiler
*/

/*
4.2.2 Macro
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0202y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0202y.html
*/
#define __CCRL__ 1
#define __RL78__ 1
//#define __RL78_S1__ 1
//#define __RL78_S2__ 1
#define __RL78_S3__ 1

#if defined(__STDC_VERSION__) || !defined(__cplusplus)
  /* Be aware that clangd doesn't define __STDC_VERSION__ when -std=c90 is specified. */
  #if defined(__STDC_VERSION__)
    #undef __STDC_VERSION__
  #endif
  #if !defined(INTELISENSE_HELPER_C_STANDARD)
    /* In certain C90 cases, the above macro can't be defined by support module for Renesas CC compilers which works along with CMake. */
    #if defined(INTELISENSE_HELPER_C_EXTENSIONS) && (INTELISENSE_HELPER_C_EXTENSIONS == 0)
      #define __STDC_VERSION__ 199409L
    #endif
  #elif (INTELISENSE_HELPER_C_STANDARD == 90)
    /* C90 */
    #if defined(INTELISENSE_HELPER_C_EXTENSIONS) && (INTELISENSE_HELPER_C_EXTENSIONS == 0)
      #define __STDC_VERSION__ 199409L
    #endif
  #elif (INTELISENSE_HELPER_C_STANDARD == 99)
    /* C99 */
    #define __STDC_VERSION__ 199901L
  #endif
#endif
/*
__STDC_VERSION__
Decimal constant 199409L (defined when the -lang=c and -strict_std options are specified).Note1
Decimal constant 199901L (defined when the -lang=c99 option is specified).

Note 1.
For the processing to be performed when the -strict_std option is specified, see "-strict_std [V1.06 or later] / -ansi [V1.05 or earlier]".
*/

/*
4.2.1 Reserved words
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0201y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0201y.html
*/
#define __saddr
#define __callt
#define __near
#define __far
#define __sectop( secname )  ( ( void * ) 0U )
#define __secend( secname )  ( ( void * ) 0U )
 
/*
4.2.4 #pragma directive
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0204y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0204y.html
*/
#if defined(__INTELLISENSE__)
#pragma diag_suppress 661
#endif
#if defined(_CLANGD)
#pragma clang diagnostic ignored "-Wignored-pragmas"
#endif

/*
4.2.7 Intrinsic functions
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0207y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRL.chm/Output/ccrl04c0207y.html
*/
#include <builtin.h>

/*
For other differnce between CC-RL and MSVC/Clang
*/
#if defined(__INTELLISENSE__)
#endif
#if defined(_CLANGD)
#endif

#else /* !defined( __GNUC__) && !defined( __llvm__ ) */

/*
GCC for Renesas RL78 and LLVM for Renesas RL78
*/

#define __near
#if defined( __llvm__ ) || ( defined( __GNUC__ ) && !defined( __cplusplus ) )
#define __far
#endif
#if defined( __llvm__ ) && defined( __CCRL__ )
#define __saddr
#define __callt
#define __sectop( secname )  ( ( void * ) 0U )
#define __secend( secname )  ( ( void * ) 0U )
#endif

#if defined( __llvm__ ) && defined( __CCRL__ )
unsigned int __mulu(unsigned char x, unsigned char y);
unsigned long __mului(unsigned int x, unsigned int y);
signed long __mulsi(signed int x, signed int y);
unsigned int __divui(unsigned int x, unsigned char y);
unsigned long __divul(unsigned long x, unsigned int y);
unsigned char __remui(unsigned int x, unsigned char y);
void __builtin_rl78_mov1 (char *x, char b1, char y, char b2);
void __builtin_rl78_and1 (char *x, char b1, char y, char b2);
void __builtin_rl78_or1 (char *x, char b1, char y, char b2);
void __builtin_rl78_xor1 (char *x, char b1, char y, char b2);
void __builtin_rl78_set1 (char *x, char b);
void __builtin_rl78_clr1 (char *x, char b);
void __builtin_rl78_not1 (char *x, char b);
char __builtin_rl78_ror1 (char x);
char __builtin_rl78_rol1 (char x);
void __builtin_rl78_ei (void);
void __EI (void);
void __builtin_rl78_di (void);
void __DI(void);
char __builtin_rl78_pswie (void);
void __builtin_rl78_setpswisp (char);
char __builtin_rl78_getpswisp (void);
void __halt(void);
void __stop(void);
void __brk(void);
void __nop(void);
unsigned char __rolb(unsigned char x, unsigned char y);
unsigned char __rorb(unsigned char x, unsigned char y);
unsigned int __rolw(unsigned int x, unsigned char y);
unsigned int __rorw(unsigned int x, unsigned char y);
unsigned long long __mulul(unsigned long x, unsigned long y);
signed long long __mulsl(signed long x, signed long y);
unsigned int __remul(unsigned long x, unsigned int y);
unsigned long __macui(unsigned int x, unsigned int y, unsigned long z);
signed long __macsi(signed int x, signed int y, signed long z);
#endif

/* To make IntelliSense work better for r_bsp module with -frenesas-extensions option */
#if defined( __llvm__ ) && defined( __CCRL__ )
#undef __CCRL__
#endif

/* To make IntelliSense work better for newlib, GCC c++ lib and clang cxx lib*/
#ifdef _MSC_VER
#undef _MSC_VER
#endif
#ifdef _WIN32
#undef _WIN32
#endif

#endif /* !defined( __GNUC__) && !defined( __llvm__ ) */

#endif /* defined(__INTELLISENSE__) || defined(_CLANGD) */

#endif /* C_CPP_INTELLISENSE_HELPER_H */
