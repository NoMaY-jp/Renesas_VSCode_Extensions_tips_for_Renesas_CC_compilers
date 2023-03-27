#if __cplusplus > 202002L
const char *cpp_std = "C++23";
#elif __cplusplus > 201703L
const char *cpp_std = "C++20";
#elif __cplusplus >= 201703L
const char *cpp_std = "C++17";
#elif __cplusplus >= 201402L
const char *cpp_std = "C++14";
#elif __cplusplus >= 201103L
const char *cpp_std = "C++11";
#elif  __cplusplus >= 199711L
const char *cpp_std = "C++98";
#else
const char *cpp_std = "Unknown";
#if __cplusplus == 1
const char *cpp_ccrx = "Microsoft(R) Visual C/C++ 6.0 compatible";
#endif
#endif
/*
4.1.7 Conforming Language Specifications
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0107y.html

C++ Language Specifications (When the lang=cpp Option is Selected)
Based on the language specifications compatible with Microsoft(R) Visual C/C++ 6.0

4.2.1 Macro Names
http://tool-support.renesas.com/autoupdate/support/onlinehelp/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0201y.html
http://tool-support.renesas.com/autoupdate/support/onlinehelp/ja-JP/csp/V8.09.00/CS+.chm/Compiler-CCRX.chm/Output/ccrx04c0201y.html

lang=cpp*2 lang=ecpp
__cplusplus 1

Notes 2.
Includes cases where a file with the .cpp, .cp, or .cc extension is compiled without specifying the -lang option.
*/

#if defined(__STDC_VERSION__)
#error Error: The `__STDC_VERSION__` is defined in C++ source.
#endif
