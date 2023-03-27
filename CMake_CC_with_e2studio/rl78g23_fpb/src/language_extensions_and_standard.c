int __callt language_extensions(void);
int __callt language_extensions(void)
{
    static int __saddr sv;
    static int __near nv;
    static int __far fv;
    int __far *pt = __sectop( ".bss" );
    int __far *pe = __secend( ".bss" );

    __nop();

    return sv + nv + fv + *pt + *pe;
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
