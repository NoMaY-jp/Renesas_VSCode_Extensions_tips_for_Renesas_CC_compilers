# This is an example of a toolchain file for Renesas CC-RL Compiler. Other examples are here:
# https://gitlab.kitware.com/NoMaY-jp/Renesas_CC_compilers_tips_for_CMake

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/Modules) # Tell CMake the path of support module for Renesas CC compilers.
set(CMAKE_SYSTEM_NAME Generic-RenesasCC) # Tell CMake that this toolchain file is to be used for cross-compiling using Renesas CC compilers.

# You can set the tool paths here in stead of setting the environment variable `Path` on Windows.
set(TOOLCHAIN_PATH C:/Renesas/CS+/CC/CC-RL/V1.12.00/bin) # Quote the path with "..." if it includes space.
set(EXTERNAL_TOOLCHAIN_PATH C:/Renesas/e2studio64/SupportFolders/.eclipse/com.renesas.platform_733684649/Utilities/ccrl) # Quote the path with "..." if it includes space.  # For e2 studio.

set(CMAKE_C_COMPILER ${TOOLCHAIN_PATH}/ccrl.exe -cpu=S3)
set(CMAKE_RENESAS_XCONVERTER ${EXTERNAL_TOOLCHAIN_PATH}/renesas_cc_converter.exe) # In the case of CS+, define the tool as "" or exclude the tool from `Path`.

set(CMAKE_C_STANDARD 99) # Tell the support module for Renesas CC compilers about the language standard for initial setting.

############################
macro(SET_DIRECTORY_OPTIONS)
############################

set(CMAKE_C_STANDARD 99)

add_link_options(
-library=rl78em4r.lib,rl78em4s99.lib,malloc_n.lib
-device=DR7F100GLG.DVF
-auto_section_layout
-rom=.data=.dataR,.sdata=.sdataR
-user_opt_byte=EFFFE8
-ocdbg=85
-security_id=00000000000000000000
-debug_monitor=1FF00-1FFFF
)

##########
endmacro()
##########

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

# If `-library=` is specified with relative paths, both of the following folders are also searched.
# <compiler path>/lib
# <compiler path>

# Additionally, in the case of CC-RL C++14, if `-library=` is specified with relative paths,
# one of the following folders is also searched depending on `-cpu=' option used for compiler.
# <compiler path>/lib/cxx/s1
# <compiler path>/lib/cxx/s2
# <compiler path>/lib/cxx/s3

# If `-device=` is specified with relative path, either of the following folders is also searched.
# <install path of CS+ for CC>/Device/RL78/Devicefile
# <support area path of e2 studio>/DebugComp/RL78/RL78/Common
#
# Please be aware that actual implementation is as follow.
# <folder path containing rlink.exe>/../../../Device/RL78/Devicefile
# <folder path containing renesas_cc_converter.exe>/../../DebugComp/RL78/RL78/Common

#----------------------------------------------------
# Note: Renesas compiler options' additional behavior
#----------------------------------------------------

# The following usage is removed because Visual Studio 2022 17.6 includes CMake 3.26.0-msvc3.
## The following usage is deprecated because CMake 3.26.0-rc2 no longer causes any problem.
### In the case of other than Ninja, `-P` and `-S` cannot be used. Please quote the option
### with single quotation character as follow:
### '-P'
### '-S'

# When the language standard such as C90 or C99 is specified by CMake's language standard variables
# and/or commands, the following definitions may be passed to not only LLVM clangd language server
# but also CC-RL by `-D` option as follows.
# -DINTELISENSE_HELPER_C_STANDARD=<value>
# -DINTELISENSE_HELPER_C_EXTENSIONS=<value>

#---------------------------------------------------------------------
# Note: DebugComp, Internal and Utilities folder location of e2 studio
#---------------------------------------------------------------------

# Renesas' FAQ
#
# https://en-support.renesas.com/knowledgeBase/19891761
# https://ja-support.renesas.com/knowledgeBase/19851044
