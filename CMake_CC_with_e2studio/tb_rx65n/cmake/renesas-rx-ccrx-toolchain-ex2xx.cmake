set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/Modules") # Tell CMake the path of support module for Renesas CC compilers.
if(EXAMPLE_CXX_PROJ_TYPE EQUAL 1)
  set(CMAKE_CXX_COMPILER_ID RENESAS) # Tell CMake that the target compiler is one of Renesas CC compilers.
  set(CMAKE_CXX_COMPILER_ID_RUN TRUE) # Tell CMake that the compiler detection process must be eliminated.
  #set(CMAKE_C_COMPILER_ID RENESAS) # This can be set simultaneously.
  #set(CMAKE_C_COMPILER_ID_RUN TRUE) # This can be set simultaneously.
elseif(EXAMPLE_CXX_PROJ_TYPE EQUAL 2)
  set(CMAKE_C_COMPILER_ID RENESAS) # Tell CMake that the target compiler is one of Renesas CC compilers.
  set(CMAKE_C_COMPILER_ID_RUN TRUE) # Tell CMake that the compiler detection process must be eliminated.
  #set(CMAKE_CXX_COMPILER_ID RENESAS) # This can be set simultaneously.
  #set(CMAKE_CXX_COMPILER_ID_RUN TRUE) # This can be set simultaneously.
endif()

# You can set the tool paths here in stead of setting the environment variable `Path` on Windows.
set(TOOLCHAIN_PATH C:/Renesas/CS+/CC/CC-RX/V3.05.00/bin) # Quote the path with "..." if it includes space.
set(EXTERNAL_TOOLCHAIN_PATH C:/Renesas/e2studio64/SupportFolders/.eclipse/com.renesas.platform_733684649/Utilities/ccrx) # Quote the path with "..." if it includes space.  # For e2 studio.

if(EXAMPLE_CXX_PROJ_TYPE EQUAL 1)
  set(CMAKE_CXX_COMPILER ${TOOLCHAIN_PATH}/ccrx.exe)
elseif(EXAMPLE_CXX_PROJ_TYPE EQUAL 2)
  set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/ccrx.exe)
endif()
set(CMAKE_RENESAS_XCONVERTER ${EXTERNAL_TOOLCHAIN_PATH}/renesas_cc_converter.exe) # In the case of CS+, define the tool as "" or exclude the tool from `Path`.

#########
# FLAGS #
#########

set(CMAKE_C_STANDARD 99)
#set(CMAKE_C_STANDARD_REQUIRED ON) # CMake's default is OFF.
#set(CMAKE_C_EXTENSIONS OFF) # CC-RX/RL/RH's default is ON and CC-RX has no strict standard option.

if(EXAMPLE_CXX_PROJ_TYPE EQUAL 1)
  set(CMAKE_CXX_FLAGS "-isa=rxv2 -goptimize -type_size_access_to_volatile -outcode=utf8 -utf8 -nomessage=21644,20010,23034,23035,20177,23033")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lang=ecpp") # -lang=cpp and/or -exception and/or -rtti=on
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -listfile=.")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -debug -g_line") # This line is intended for test purpose.
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -no_warning=20826 -preinclude=${CMAKE_CURRENT_LIST_DIR}/../src/pre_include.h") # This line is intended for test purpose.
else()
  set(CMAKE_C_FLAGS   "-isa=rxv2 -goptimize -type_size_access_to_volatile -outcode=utf8 -utf8 -nomessage=21644,20010,23034,23035,20177,23033")
  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -listfile=.")
  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -debug -g_line") # This line is intended for test purpose.
  set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -no_warning=20826 -preinclude=${CMAKE_CURRENT_LIST_DIR}/../src/pre_include.h") # This line is intended for test purpose.
endif()
set(CMAKE_ASM_FLAGS "-isa=rxv2 -goptimize -utf8")
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -listfile=. -define=aaa,bbb=999,ccc,ddd=\"qqq\",eee") # Somehow not `"qqq"` but `qqq` is passed to the assembler.
set(CMAKE_ASM_FLAGS "${CMAKE_ASM_FLAGS} -debug") # This line is intended for test purpose.

if(EXAMPLE_CXX_PROJ_TYPE EQUAL 1)
  set(CMAKE_LBG_FLAGS "${CMAKE_CXX_FLAGS}") #-head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string,ios,new,complex,cppstring,c99_complex,fenv,inttypes,wchar,wctype")
else()
  set(CMAKE_LBG_FLAGS "${CMAKE_C_FLAGS}")   #-head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string,ios,new,complex,cppstring,c99_complex,fenv,inttypes,wchar,wctype")
endif()
# Unfortunately, in the case of Ninja, there are several minutes without any messages during execution
# of library generator actually generating or regenerating libraries. Please wait for a while.

set(CMAKE_EXE_LINKER_FLAGS "-optimize=short_format,branch,symbol_delete -stack \
-start=SU,SI,B_1,R_1,B_2,R_2,B,R/04,P,C_1,C_2,C,C$$*,D*,W*,L/0FFE00000,EXCEPTVECT/0FFFFFF80,RESETVECT/0FFFFFFFC \
-rom=D=R,D_1=R_1,D_2=R_2 \
-vect=_undefined_interrupt_source_isr \
-change_message=warning=2300,2142 -total_size -list -show=all \
-form=s -byte_count=20 -xcopt=-dsp_section=DSP"
-debug) # This line is intended for test purpose.
# If you want to use `C$*` string for `-start` flag, please take care of `$` character as above.
# Fortunately, in the case of Ninja, simple single `$` still can be used for `-start` flag.

#######
# END #
#######

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
