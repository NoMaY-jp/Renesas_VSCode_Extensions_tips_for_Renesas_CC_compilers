int language_extensions(void);
int language_extensions(void)
{
    volatile void __evenaccess * portbase = (volatile void __evenaccess *)0x8C000;

    int *pt = __sectop( "B" );
    int *pe = __secend( "B" );
    int sz = __secsize( "B" );

    __nop();

    return *(int *)portbase + *pt + *pe + sz;
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
#endif
/*
4.1.7 Conforming Language Specifications
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html

C Language Specifications (When the lang=c Option is Selected)
ANSI/ISO 9899-1990 American National Standard for Programming Languages -C

C Language Specifications (When the lang=c99 Option is Selected)
ISO/IEC 9899:1999 INTERNATIONAL STANDARD Programming Languages - C

4.2.1 Macro Names
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0201y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0201y.html

lang=c*1 lang=c99
__STDC_VERSION__ 199409L(lang=c*1) 199901L(lang=c99)

Notes 1.
Includes cases where a file with the .c extension is compiled without specifying the -lang option.
*/

#if defined(__cplusplus)
#error Error: The `__cplusplus` is defined in C++ source.
#endif
