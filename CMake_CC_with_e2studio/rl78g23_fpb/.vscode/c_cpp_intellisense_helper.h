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
  /* Be aware that clangd and IntelliSense don't define __STDC_VERSION__ when -std=c90 is specified. */
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
3.2.2 Macros
https://www.renesas.com/us/en/document/mat/cc-rl-c14-technical-preview-version-users-manual
https://www.renesas.com/jp/ja/document/mat/cc-rl-c14-technical-preview-version-users-manual
*/
#if defined(__cplusplus)

#if defined(__clang__)
#undef __clang__
#endif
#define __clang__ 1
#if defined(__STDC_HOSTED__)
#undef __STDC_HOSTED__
#endif
#define __STDC_HOSTED__ 0
#if defined(__STDC__)
#undef __STDC__
#endif
#define __STDC__ 1
#if defined(__STDC_VERSION__)
#undef __STDC_VERSION__
#endif
#if defined(__STDC_IEC_559__)
#undef __STDC_IEC_559__
#endif
/*
Name             Definition when -lang=cpp14 is specified
__cplusplus      201402L
__clang__        1
__STDC_HOSTED__  0
__STDC__         1
__STDC_VERSION__ Undefined
__STDC_IEC_559__ Undefined
*/

#else /* defined(__cplusplus) */

#if defined(__clang__)
#undef __clang__
#endif
#if defined(__STDC_HOSTED__)
#undef __STDC_HOSTED__
#endif
#if (INTELISENSE_HELPER_C_STANDARD == 99)
#define __STDC_HOSTED__ 0
#endif
#if defined(__STDC__)
#undef __STDC__
#endif
#if defined(INTELISENSE_HELPER_C_EXTENSIONS) && (INTELISENSE_HELPER_C_EXTENSIONS == 0)
#define __STDC__ 1
#endif
#if defined(__STDC_IEC_559__)
#undef __STDC_IEC_559__
#endif
#if (INTELISENSE_HELPER_C_STANDARD == 99)
#define __STDC_IEC_559__ 1
#endif
/*
Name             Definition when -lang=c or -lang=c99 is specified
__cplusplus      Undefined
__clang__        Undefined
__STDC_HOSTED__  0 (when -lang=c99 is specified), Undefined (otherwise)
__STDC__         1 (when -strict_std is specified), Undefined (otherwise)
__STDC_VERSION__ 199409L (when both -lang=c and -strict_std are specified)
                 199901L (when -lang=c99 is specified)
__STDC_IEC_559__ 1 (when -lang=c99 is specified), Undefined (otherwise)
*/

#endif /* defined(__cplusplus) */

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
#if !defined(__cplusplus)
#include <builtin.h>
#else
#include <../../builtin.h>
#endif

/*
For other differnce between CC-RL and MSVC/Clang
*/
#if defined(_WIN32)
#undef _WIN32
#endif
#if defined(_MSC_VER)
#undef _MSC_VER
#endif
#if defined(__cplusplus)
#if defined(__ELF__)
#undef __ELF__
#endif
#define __ELF__ 1
#if defined(_LIBCPP_HAS_NO_THREADS)
#undef _LIBCPP_HAS_NO_THREADS
#endif
#define _LIBCPP_HAS_NO_THREADS 1
#if defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#undef _LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
#endif
#define _LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER 1
#endif /* defined(__cplusplus) */
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
#if defined(_WIN32)
#undef _WIN32
#endif
#if defined(_MSC_VER)
#undef _MSC_VER
#endif

#endif /* !defined( __GNUC__) && !defined( __llvm__ ) */

#endif /* defined(__INTELLISENSE__) || defined(_CLANGD) */

#endif /* C_CPP_INTELLISENSE_HELPER_H */
