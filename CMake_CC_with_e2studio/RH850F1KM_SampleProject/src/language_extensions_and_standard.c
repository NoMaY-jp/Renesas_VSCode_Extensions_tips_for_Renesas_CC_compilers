void language_extensions(void);
void language_extensions(void)
{
#if defined(__INTELLISENSE__) || defined(_CLANGD)
    __fp16 fp16v; /* CC-RH professional version only */
#endif

    __nop();

    return;
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
4.2.2 Macro
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0202y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRH.chm/Output/ccrh04c0202y.html

__STDC_VERSION__
199409L (when -lang=c99 is not specified)
199901L (when -lang=c99 is specified)
*/
