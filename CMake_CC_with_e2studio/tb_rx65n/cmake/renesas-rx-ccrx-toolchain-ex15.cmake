set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/Modules) # Tell CMake the path of support module for Renesas CC compilers.
set(CMAKE_SYSTEM_NAME Generic-RenesasCC) # Tell CMake that this toolchain file is to be used for cross-compiling using Renesas CC compilers.
set(CMAKE_SYSTEM_PROCESSOR RX)
set(CMAKE_SYSTEM_ARCH RXv2)

# You can set the tool paths here in stead of setting the environment variable `Path` on Windows.
set(TOOLCHAIN_ROOT C:/Renesas/CS+/CC/CC-RX/V3.05.00) # Quote the path with "..." if it includes space.
set(EXTERNAL_TOOLCHAIN_ROOT C:/Renesas/e2studio64/SupportFolders/.eclipse/com.renesas.platform_733684649/Utilities) # Quote the path with "..." if it includes space.  # For e2 studio.
set(CMAKE_FIND_ROOT_PATH ${TOOLCHAIN_ROOT} ${EXTERNAL_TOOLCHAIN_ROOT}) # In the case of CS+, ${EXTERNAL_TOOLCHAIN_ROOT} isn't necessary.

set(CMAKE_C_STANDARD 99) # Tell the support module for Renesas CC compilers about the language standard for initial setting.

#########################
macro(SET_TARGET_OPTIONS)
#########################

target_compile_features(tb_rx65n PRIVATE c_std_99)

target_library_generate_options(tb_rx65n PRIVATE
-head=runtime,stdio,stdlib,string # -head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string,c99_complex,fenv,inttypes,wchar,wctype
)
# Unfortunately, in the case of Ninja, there are several minutes without any messages during execution
# of library generator actually generating or regenerating libraries. Please wait for a while.

target_link_options(tb_rx65n PRIVATE
-start=SU,SI,B_1,R_1,B_2,R_2,B,R/04,P,C_1,C_2,C,C$*,D*,W*,L/0FFE00000,EXCEPTVECT/0FFFFFF80,RESETVECT/0FFFFFFFC
-rom=D=R,D_1=R_1,D_2=R_2
)

##########
endmacro()
##########

#------------------------------------------
# Note: Renesas specific flags and commands
#------------------------------------------

#set(CMAKE_LBG_FLAGS "<flag> ...")
#add_library_generate_options(<option> ...)
#target_library_generate_options(<target> [BEFORE] <INTERFACE|PUBLIC|PRIVATE> [items1...] [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
# If at least one of the above commands is done, specified options are used for Renesas Library Generator.

# Unless options other than the following are specifed, options specified for the compiler are also used
# for the library generator. But if options other than the following are specifed, options specified for
# the compiler are no longer used for the library generator and any options have to be specified by doing
# the above commands. 
# -head=<items>
# -output=<file>
# -nofloat
# -reent
# -lang=<item>
# -simple_stdio
# -secure_malloc
# -logo
# -nologo

# If `-head=` option is not included in the options for the library generator, the following is used.
# For C90
# -head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string
# For C99
# -head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string,c99_complex,fenv,inttypes,wchar,wctype
# For C++ or EC++, and C90 (Note that C++ language specification is compatible with Visual Studio 6.0)
# -head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string,ios,new,complex,cppstring
# For C++ or EC++, and C99 (Note that C++ language specification is compatible with Visual Studio 6.0)
# -head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string,ios,new,complex,cppstring,c99_complex,fenv,inttypes,wchar,wctype
# You can remove unused items from -head= list to make a generating time shorter.

# Since add_library_generate_options() and target_library_generate_options() are not CMake's native command,
# so that these commands cannot be used before enable_language() or project().

#----------------------------------------
# Note: Renesas pseudo exe linker options
#----------------------------------------

# -xcopt=<XConverter options>
# The `-xcopt=` is not a native option of either Renesas Linker or Renesas XConverter.
# It is intended to be used for CMake's wrapper scripts for Renesas build tools.
# The <XConvert options> are passed not to rlink.exe but to renesas_cc_converter.exe.

#------------------------------------------------------
# Note: Renesas exe linker options' additional behavior
#------------------------------------------------------

# If `-form=` is not specified, both -form=abs and -form=s are regarded as being specified.
#
# If only -form=s is specified, -form=abs is regarded as being specified. On the other hand,
# if only -form=abs is specified, -form=s is not regarded as being specified.
#
# If only either of -form=<hex|bin> is specified, -form=abs is regarded as being specified
# but -form=s is not regarded as being specified in addition to the -form=<hex|bin>.
#
# If -form=abs and one of -form=<s|hex|bin> are specified simultaneously, Renesas linker is
# executed twice. The first execution is performed with -form=abs, the second execution is
# performed with the specified one of -form=<s|hex|bin>. In the case, the following options
# are regarded as being specified for the second execution if these options are specified.
# -byte_count=<num>
# -fix_record_length_and_align=<num>
# -record=<item>
# -end_record=<item>
# -s9
# -space[=<num|item>]
# -crc=<sub_option>
# -output=<sub_option>

# If neither enable_language() nor project() activate C++ language mode, `-noprelink` is
# specified automatically.

#----------------------------------------------------
# Note: Renesas compiler options' additional behavior
#----------------------------------------------------

# Assembler's `-listfile=` can be followed by one of the following items.
# .
# ..
# <path>/
# Nothing are followed. (This is the same as followed by `.`.)
#
# Please do not use the path which includes any Japanese characters.

# Assembler's `-define=` can accept a symbol without a value. In the case, the symbol is
# regarded as being specified with 1. (i.e `-define=<symbol>=1`)

# Clang-like -I and -D options can be used.
# Especially when LLVM clangd language server and Microsoft VSCode are used together with CMake,
# using above options is recommended instead of CC-RX's -include= and -define= options
# if there are some reasons to use CC-RX's these options in the CMakeLists.txt and/or toolchain file.

# When the language standard such as C90 or C99 is specified by CMake's language standard variables
# and/or commands, the following definitions may be passed to not only LLVM clangd language server
# but also CC-RX by `-D` option as follows.
# -DINTELISENSE_HELPER_C_STANDARD=<value>

#---------------------------------------------------------------------
# Note: DebugComp, Internal and Utilities folder location of e2 studio
#---------------------------------------------------------------------

# Renesas' FAQ
#
# https://en-support.renesas.com/knowledgeBase/19891761
# https://ja-support.renesas.com/knowledgeBase/19851044
