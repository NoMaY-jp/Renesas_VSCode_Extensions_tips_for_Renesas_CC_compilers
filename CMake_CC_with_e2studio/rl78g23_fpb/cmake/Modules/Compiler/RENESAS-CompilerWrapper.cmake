set(msg ${CMAKE_ARGV5})
set(gen ${CMAKE_ARGV6})
set(e2studio_support_area ${CMAKE_ARGV7})
set(arc ${CMAKE_ARGV8})
set(ver ${CMAKE_ARGV9})
set(cmd ${CMAKE_ARGV10})
set(cmd_args_first 11)
math(EXPR cmd_args_last "${CMAKE_ARGC} - 1")
# FIXME: Check list operation such as remove/add/replace/find/etc
foreach(arg_n RANGE ${cmd_args_first} ${cmd_args_last})
  string(JOIN " " cmd_args_string ${cmd_args_string} ${CMAKE_ARGV${arg_n}})
  # FIXME: Remove the following code because CMake's script mode option parser is fixed.
  if(CMAKE_ARGV${arg_n} MATCHES "^'(-P)'$") # This is not only for other than Ninja but also for Ninja because of interoperability.
    # As of today, compiler's `-P` option needs a workaround due to conflict with CMake's `-P` option for other than Ninja.
    set(CMAKE_ARGV${arg_n} ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^'(-S)'$") # This is not only for other than Ninja but also for Ninja because of interoperability.
    # CMake 3.24.0 no longer needs this workaround but it is kept for a while for the backward compatibilty.
    set(CMAKE_ARGV${arg_n} ${CMAKE_MATCH_1})
  endif()
  # FIXME: Refactor source file check.
  if((NOT CMAKE_ARGV${arg_n} MATCHES "\\.(obj|i|p|pp|s|asm|src|d|rsp|sub)$") AND CMAKE_ARGV${arg_n} MATCHES "^([^-].*)")
    set(src_name ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-isa=|-cpu=|-Xcpu=)(.+)")
    set(target_opt ${CMAKE_MATCH_1}${CMAKE_MATCH_2})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-std=.+")
    # When clangd or IntelliSense is used along with CMake, it is useful to tell them about `-std=`.
    # But it is not a compilers' native flag. Therefore it is removed here.
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-isystem.+")
    # When clangd (not IntelliSense) is used along with CMake, it is useful to tell them about `-isystem${_RENESAS_${lang}_COMPILER_PATH}/include or inc`.
    # But it is not a compilers' native flag. Therefore it is removed here.
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-include[^=].*")
    # When clangd or IntelliSense is used along with CMake, it is useful to tell them about `-include<c_cpp_intellisense_helper.h>`.
    # But it is not a compilers' native flag. Therefore it is removed here.
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-MF=)(.+)")
    set(dep_name ${CMAKE_MATCH_2})
    if(arc STREQUAL RX)
      list(APPEND dep_args_list -output=dep=${CMAKE_MATCH_2})
    elseif(arc STREQUAL RL78)
      list(APPEND dep_args_list -o ${CMAKE_MATCH_2})
    elseif(arc STREQUAL RH850)
      list(APPEND dep_args_list -o${CMAKE_MATCH_2})
    endif()
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-MT=)(.+)")
    set(obj_name ${CMAKE_MATCH_2})
    list(APPEND dep_args_list ${CMAKE_MATCH_1}${CMAKE_MATCH_2})
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-M)(.*)")
    list(APPEND dep_args_list ${CMAKE_MATCH_1}${CMAKE_MATCH_2})
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-I(.+)" AND arc STREQUAL RX)
    #message("DEBUG: ${CMAKE_ARGV${arg_n}}")
    set(CMAKE_ARGV${arg_n} -include=${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-D(.+)" AND arc STREQUAL RX)
    #message("DEBUG: ${CMAKE_ARGV${arg_n}}")
    set(CMAKE_ARGV${arg_n} -define=${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(@|-subcommand=)(.+)")
    # For not only CMake-generated subcommand files but also user own subcommand files.
    set(rsp_name ${CMAKE_MATCH_2})
    file(READ ${rsp_name} rsp_content_string)
    separate_arguments(rsp_content_list NATIVE_COMMAND ${rsp_content_string})
    foreach(opt ${rsp_content_list})
      #message("DEBUG: ${opt}")
      if(opt MATCHES "^(-isa=|-cpu=|-Xcpu=)(.+)")
        set(target_opt ${CMAKE_MATCH_1}${CMAKE_MATCH_2})
      endif()
    endforeach()
    foreach(opt ${rsp_content_list})
      if(opt MATCHES "^-std=.+")
        # When clangd or IntelliSense is used along with CMake, it is useful to tell them about `-std=`.
        # But it is not a compilers' native flag. Therefore it is removed here.
        # I.e. nothing to do but only set a flag.
        set(sub_content_save true)
      elseif(opt MATCHES "^-isystem.+")
        # When clangd (not IntelliSense) is used along with CMake, it is useful to tell them about `-isystem${_RENESAS_${lang}_COMPILER_PATH}/include or inc`.
        # But it is not a compilers' native flag. Therefore it is removed here.
        # I.e. nothing to do but only set a flag.
        set(sub_content_save true)
      elseif(opt MATCHES "^-include[^=].*")
        # When clangd or IntelliSense is used along with CMake, it is useful to tell them about `-include<c_cpp_intellisense_helper.h>`.
        # But it is not a compilers' native flag. Therefore it is removed here.
        # I.e. nothing to do but only set a flag.
        set(sub_content_save true)
      elseif(opt MATCHES "^-I(.+)" AND arc STREQUAL RX)
        #message("DEBUG: ${opt}")
        string(JOIN " " sub_content_string ${sub_content_string} -include=${CMAKE_MATCH_1})
        set(sub_content_save true)
      elseif(opt MATCHES "^-D(.+)" AND arc STREQUAL RX)
        #message("DEBUG: ${opt}")
        string(JOIN " " sub_content_string ${sub_content_string} -define=${CMAKE_MATCH_1})
        set(sub_content_save true)
      else()
        string(JOIN " " sub_content_string ${sub_content_string} ${opt})
      endif()
    endforeach()
  endif()
endforeach()

# Replace subcommand file names and/or subcommand file options if necessary. Of course, subcommand file itself if necessary.
foreach(arg_n RANGE ${cmd_args_first} ${cmd_args_last})
  if(CMAKE_ARGV${arg_n} MATCHES "^(@|-subcommand=)(.+)" AND (arc STREQUAL RX OR arc STREQUAL RL78))
    if(sub_content_save)
      if(NOT sub_name)
        string(REGEX REPLACE "\\.[^.]+$" ".sub" sub_name ${obj_name})
        set(CMAKE_ARGV${arg_n} -subcommand=${sub_name})
        #message("DEBUG: sub_name=${sub_name}")
        file(WRITE ${sub_name} ${sub_content_string})
      else()
        set(CMAKE_ARGV${arg_n} " ")
      endif()
    else()
      if(CMAKE_MATCH_1 STREQUAL @)
        set(CMAKE_ARGV${arg_n} -subcommand=${CMAKE_MATCH_2})
      endif()
    endif()
  elseif(CMAKE_ARGV${arg_n} MATCHES "^@.+" AND arc STREQUAL RH850)
    if(sub_content_save)
      if(NOT sub_name)
        string(REGEX REPLACE "\\.[^.]+$" ".sub" sub_name ${obj_name})
        set(CMAKE_ARGV${arg_n} @${sub_name})
        #message("DEBUG: sub_name=${sub_name}")
        file(WRITE ${sub_name} ${sub_content_string})
      else()
        set(CMAKE_ARGV${arg_n} " ")
      endif()
    endif()
  endif()
  list(APPEND cmd_args_list ${CMAKE_ARGV${arg_n}})
endforeach()

# In some cases, there are no target option during CMake's compiler check process.
if(NOT target_opt)
  if(arc STREQUAL RX)
    set(try_compile_compiler_target_arg -isa=rxv1)
    set(try_compile_compile_source_lang -lang=cpp)
  elseif(arc STREQUAL RL78)
    set(try_compile_compiler_target_arg -cpu=S2)
    set(try_compile_compile_source_lang -lang=cpp)
    set(try_compile_compiler_msg_lang -msg_lang=english) # Japanese characters cannot be displayed correctly in the process.
  elseif(arc STREQUAL RH850)
    set(try_compile_compiler_target_arg -Xcommon=rh850) # CC-RX V1.00 and V1.01 need this option.
    set(try_compile_compiler_msg_lang -Xmsg_lang=english) # Japanese characters cannot be displayed correctly in the process.
  endif()
  if(src_name MATCHES "CMakeScratch(/|\\\\)[^/\\\\]+(/|\\\\)test(C|CXX)Compiler\\.(c|cxx|cpp)$")
    list(PREPEND cmd_args_list ${try_compile_compiler_target_arg} ${try_compile_compiler_msg_lang})
    if(src_name MATCHES "\\.cxx$")
      list(PREPEND cmd_args_list ${try_compile_compile_source_lang})
    endif()
    #message("DEBUG: src_name = ${src_name}")
  elseif(src_name MATCHES "Modules(/|\\\\)(CMake(C|CXX)CompilerABI\\.(c|cxx|cpp))$")
    list(PREPEND cmd_args_list ${try_compile_compiler_target_arg} ${try_compile_compiler_msg_lang})
    if(src_name MATCHES "\\.cxx$")
      list(PREPEND cmd_args_list ${try_compile_compile_source_lang})
    endif()
    #message("DEBUG: src_name = ${src_name}")
  elseif(src_name MATCHES "CMakeScratch(/|\\\\)[^/\\\\]+(/|\\\\)feature_tests\\.(c|cxx|cpp)$")
    list(PREPEND cmd_args_list ${try_compile_compiler_target_arg} ${try_compile_compiler_msg_lang})
    if(src_name MATCHES "\\.cxx$")
      list(PREPEND cmd_args_list ${try_compile_compile_source_lang})
    endif()
    #message("DEBUG: src_name = ${src_name}")
  endif()
endif()

list(REMOVE_ITEM cmd_args_list " ")

if(msg GREATER 1)
  #message("DEBUG: Renesas ${arc} ${ver} (Generator: ${gen}) (Message mode: ${msg})")
  #message("DEBUG: cmd = ${cmd}")
  message("DEBUG: args(script) = ${cmd_args_string}")
  list(JOIN cmd_args_list " " cmd_args_string)
  message("DEBUG: args(native) = ${cmd_args_string}")
endif()

# Renesas CC-RX needs some settings of environment variables.
# ccrx.exe:  The `BIN_RX` (or `Path`) has to be set to contain the path to macrx.exe of the compiler.
# asrx.exe:  The `BIN_RX` (or `Path`) has to be set to contain the path to macrx.exe of the compiler.
# lbgrx.exe: The `BIN_RX` has to be set to point the path to ccrx.exe of the compiler.
# rlink.exe: The `Path` has to be set to contain the path to prelnk.exe of the compiler without `-noprelink` flag.
# It has to be taken care that lbgrx.exe calls both ccrx.exe and rlink.exe and 
# the 'Path' has to be set for the both. (But the both path are the same usually.)
if(arc STREQUAL RX)
  get_filename_component(bin_path "${cmd}/../" ABSOLUTE)
  set(ENV{BIN_RX} "${bin_path}")
endif()

execute_process(
  COMMAND ${cmd} ${cmd_args_list}
  #COMMAND_ECHO STDOUT # For debugging.
  ENCODING OEM
  OUTPUT_VARIABLE output
  ERROR_VARIABLE output
  RESULT_VARIABLE result
)

if(result EQUAL 0 AND dep_name)
  list(APPEND cmd_args_list ${dep_args_list})
  if(arc STREQUAL RX)
    # Show error messages but do not show warning messages and information messages.
    if(ver VERSION_GREATER_EQUAL 2.8.0)
      list(APPEND cmd_args_list -no_warning=0-99999)
    else()
      # Warning messages explicitly changed from information messages by user cannot be suppressed.
      list(APPEND cmd_args_list -change_message=information=0-99999 -nomessage=0-99999)
    endif()
  elseif(arc STREQUAL RL78)
    list(APPEND cmd_args_list -no_warning_num=0-99999)
  elseif(arc STREQUAL RH850)
    list(APPEND cmd_args_list -Xno_warning=0-99999)
  endif()

  if(msg GREATER 1)
    list(JOIN cmd_args_list " " cmd_args_string)
    message("DEBUG: args(depend) = ${cmd_args_string}")
  endif()

  execute_process(
    COMMAND ${cmd} ${cmd_args_list}
    #COMMAND_ECHO STDOUT # For debugging.
    ENCODING OEM
    OUTPUT_VARIABLE output_dep
    ERROR_VARIABLE output_dep
    RESULT_VARIABLE result_dep
  )

  if(result_dep GREATER 0)
    # Basically output_dep is not necessary but this case is unusual and therefore replace output by output_dep.
    set(output ${output_dep})
  endif()
  set(result ${result_dep})
endif()

if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL "") OR (NOT $ENV{VCTOOLTASK_USE_UNICODE_OUTPUT} STREQUAL ""))

  # file(line):Ccode:message --> file(line): error Ccode: message
  # file(line):Ecode:message --> file(line): error Ecode: message
  # file(line):Fcode:message --> file(line): error Fcode: message
  string(REGEX REPLACE "([^\n]+)\\(([0-9]+)\\):([CEF][0-9]+):([^\n]+)" "\\1(\\2): error \\3: \\4" output "${output}")

  # file(line):Wcode:message --> file(line): warning Wcode: message
  string(REGEX REPLACE "([^\n]+)\\(([0-9]+)\\):(W[0-9]+):([^\n]+)" "\\1(\\2): warning \\3: \\4" output "${output}")

  # file(line):Mcode:message --> file(line): info Mcode: message
  string(REGEX REPLACE "([^\n]+)\\(([0-9]+)\\):(M[0-9]+):([^\n]+)" "\\1(\\2): info \\3: \\4" output "${output}")

  # Ccode:message --> file: error Ccode: message    # `<RENESAS-CC>` is a place holder for source file path.
  # Ecode:message --> file: error Ecode: message    # `<RENESAS-CC>` is a place holder for source file path.
  # Fcode:message --> file: error Fcode: message    # `<RENESAS-CC>` is a place holder for source file path.
  string(REGEX REPLACE "(^|\n)([CEF][0-9]+):([^\n]+)" "\\1<RENESAS-CC>: error \\2: \\3" output "${output}")

  # Wcode:message --> file: warning Wcode: message    # `<RENESAS-CC>` is a place holder for source file path.
  string(REGEX REPLACE "(^|\n)(W[0-9]+):([^\n]+)" "\\1<RENESAS-CC>: warning \\2: \\3" output "${output}")

  # Mcode:message --> file: info Mcode: message    # `<RENESAS-CC>` is a place holder for source file path.
  string(REGEX REPLACE "(^|\n)(M[0-9]+):([^\n]+)" "\\1<RENESAS-CC>: info \\2: \\3" output "${output}")

  if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL ""))
    # VSCode's Problem View needs `(num)` before `:`
    string(REGEX REPLACE "(^|\n)<RENESAS-CC>: (error|warning|info)( [^\n]+)" "\\1<RENESAS-CC>(0): \\2\\3" output "${output}")
    string(REPLACE "<RENESAS-CC>" "${src_name}" output "${output}")
  else()
    # Visual Studio's Error List Window does not recognize the following severity in the case of C/C++.
    # info, information, message, suggestion
    string(REGEX REPLACE "([^\n]+)\\(([0-9]+)\\): info( [^\n]+)" "\\1(\\2): warning\\3 (Information)" output "${output}")
    string(REGEX REPLACE "(^|\n)<RENESAS-CC>: info( [^\n]+)" "\\1<RENESAS-CC>: warning\\2 (Information)" output "${output}")
    string(REPLACE "<RENESAS-CC>" "${src_name}" output "${output}")
  endif()

endif()

# Remove blank lines.
string(REGEX REPLACE "\n+" "\n" output "${output}")
string(REGEX REPLACE "^\n?([^\n].*[^\n]|[^\n])\n?$" "\\1" output "${output}")
string(REGEX REPLACE "^\n+$" "" output "${output}")
if(output)
  message(${output})
endif()

if(result GREATER 0)
  # To reduce CMake stack dump display, it is better to use neither macro() nor function().
  # TODO: Is there any way to disable CMake stack dump display?
  # TODO: Is there any way for the script to exit with exit code greater than 1?
  message("\nCMake RENESAS compiler wrapper aborted at the following line due to compiler exit code: ${result}")
  message(FATAL_ERROR) # This causes CMake stack dump display and then the script exits with exit code 1.
endif()

# Renesas CC-{RX, RL, RH}'s dependency file is not compatible with GCC's dependency file, and
# CMake can not parse the file due to the incompatibility. Therefore the file has to be converted.
if(dep_name AND (NOT gen MATCHES "^Ninja"))
  file(READ ${dep_name} dep_file)
  string(REGEX REPLACE "\n[^:]*: ([^\n]*)" " \\\\\n  \\1" dep_file "${dep_file}")
  file(WRITE ${dep_name} ${dep_file})
endif()
