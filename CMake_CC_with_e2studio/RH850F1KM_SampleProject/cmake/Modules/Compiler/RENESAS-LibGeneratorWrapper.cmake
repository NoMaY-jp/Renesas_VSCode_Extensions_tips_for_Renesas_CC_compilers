set(msg ${CMAKE_ARGV4})
set(gen ${CMAKE_ARGV5})
set(e2studio_support_area ${CMAKE_ARGV6})
set(arc ${CMAKE_ARGV7})
set(ver ${CMAKE_ARGV8})
set(cmd ${CMAKE_ARGV9})
set(cmd_args_first 10)
math(EXPR cmd_args_last "${CMAKE_ARGC} - 1")
# FIXME: Check list operation such as remove/add/replace/find/etc
foreach(arg_n RANGE ${cmd_args_first} ${cmd_args_last})
  string(JOIN " " wpr_args_string ${wpr_args_string} ${CMAKE_ARGV${arg_n}})
  if(CMAKE_ARGV${arg_n} MATCHES "^(-nologo|-logo)$")
    set(logo ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-output_lbg=(.+)")
    set(lbgoutput -output=${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options_c_arg1=(.+)")
    set(c_arg1 ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options_c_flags=(.+)")
    string(REPLACE ",-" " -" c_flags "${CMAKE_MATCH_1}")
##  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options_cxx_arg1=(.+)")
##    set(cxx_arg1 ${CMAKE_MATCH_1})
##  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options_cxx_flags=(.+)")
##    string(REPLACE ",-" " -" cxx_flags "${CMAKE_MATCH_1}")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options_c_std=(.+)")
    set(c_std ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options=(.+)")
    string(REPLACE ",-" " -" compile_options_t "${CMAKE_MATCH_1}")
    string(JOIN " " compile_options ${compile_options} ${compile_options_t})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-link_language=(.+)")
    set(link_language ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-lbgopt=(.+)")
    string(REPLACE ",-" " -" lbgopts_t "${CMAKE_MATCH_1}")
    string(JOIN " " lbgopts ${lbgopts} ${lbgopts_t})
  endif()
endforeach()

if(c_std MATCHES "^-lang=(c|c90)$")
  # These options are unintentionally added by RENESAS.cmake's __init_library_generate_options() function.
  # Therefore these options should be ignored.
  # Nothing to do.
else()
  string(JOIN " " lbgopts_library_options ${lbgopts_library_options} ${c_std})
endif()
separate_arguments(lbgopts_list NATIVE_COMMAND ${lbgopts})
foreach(opt ${lbgopts_list})
  if(opt MATCHES "^(-head=.+|-output=.+|-nofloat|-reent|-lang=.+|-simple_stdio|-secure_malloc|-logo|-nologo)$")
    string(JOIN " " lbgopts_library_options ${lbgopts_library_options} ${opt})
  else()
    string(JOIN " " lbgopts_compile_options ${lbgopts_compile_options} ${opt})
  endif()
endforeach()
if(NOT lbgopts_library_options MATCHES "(^| )-head=")
  string(APPEND lbgopts_library_options " -head=runtime,ctype,math,mathf,stdarg,stdio,stdlib,string")
  if("${c_flags} ${c_std} ${compile_options} ${lbgopts_compile_options}" MATCHES "(^| )-lang=c99( |$)")
    string(APPEND lbgopts_library_options ",c99_complex,fenv,inttypes,wchar,wctype")
  endif()
  if(link_language STREQUAL CXX)
    string(APPEND lbgopts_library_options ",ios,new,complex,cppstring")
  endif()
endif()
if(lbgopts_compile_options)
  string(JOIN " " tmp_string ${logo} ${c_arg1} ${lbgopts_compile_options} ${lbgopts_library_options} ${lbgoutput})
else()
  string(JOIN " " tmp_string ${logo} ${c_arg1} ${c_flags} ${compile_options} ${lbgopts_library_options} ${lbgoutput})
endif()
separate_arguments(cmd_args_list NATIVE_COMMAND ${tmp_string})
# To avoid the following errors (only `lang=c` and `-lang=c99` are valid), remove the following items.
# F0593305:Invalid command parameter "-lang=cpp"
# F0593305:Invalid command parameter "-lang=ecpp"
list(REMOVE_ITEM cmd_args_list -lang=cpp -lang=ecpp) # These may come from c_flags, compile_options, etc.
# To avoid the following errors (these non native options are workaround for IntelliSense), remove the following items.
# F0593305: Invalid command parameter "-IXXXX"
# F0593305: Invalid command parameter "-DXXXX"
# F0593305: Invalid command parameter "@XXXX"
# F0593305: Invalid command parameter "-std=XXXX"
# F0593305: Invalid command parameter "-isystemXXXX"
# F0593305: Invalid command parameter "-includeXXXX"
list(TRANSFORM cmd_args_list REPLACE "^-I.+" " ")
list(TRANSFORM cmd_args_list REPLACE "^-D.+" " ")
list(TRANSFORM cmd_args_list REPLACE "^@.+" " ")
list(TRANSFORM cmd_args_list REPLACE "^-std=.+" " ")
list(TRANSFORM cmd_args_list REPLACE "^-isystem.+" " ")
list(TRANSFORM cmd_args_list REPLACE "^-include[^=].*" " ")
# To avoid strange behavior (somehow always libraries are regenerated), remove the following items.
list(REMOVE_ITEM cmd_args_list -debug)
list(TRANSFORM cmd_args_list REPLACE "^-preinclude=.+" " ")
# And other warnings and errors.  # FIXME: Are there more items?
# W0591300:Command parameter specified twice `-output=XXXX`
list(TRANSFORM cmd_args_list REPLACE "^-output=(prep|src|obj|dep)=.+" " ")
# F0593305:Invalid command parameter `-no_warning=XXXX`
list(TRANSFORM cmd_args_list REPLACE "^-no_warning=.+" " ")
list(REMOVE_ITEM cmd_args_list " ")

if(msg GREATER 0)
  message("Library Generator:")
  #message("DEBUG: Renesas ${arc} ${ver} (Generator: ${gen}) (Message mode: ${msg})")
  #message("DEBUG: cmd = ${cmd}")
  message("DEBUG: args(script) = ${wpr_args_string}")
  message("DEBUG: logo = ${logo}")
  message("DEBUG: c_arg1 = ${c_arg1}")
  message("DEBUG: c_flags = ${c_flags}")
  ##message("DEBUG: cxx_arg1 = ${cxx_arg1}")
  ##message("DEBUG: cxx_flags = ${cxx_flags}")
  message("DEBUG: c_std = ${c_std}")
  message("DEBUG: compile_options = ${compile_options}")
  message("DEBUG: link_language = ${link_language}")
  message("DEBUG: lbgopts = ${lbgopts}")
  message("DEBUG: lbgoutput = ${lbgoutput}")
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
  get_filename_component(bin_path ${cmd}/../ ABSOLUTE)
  set(ENV{BIN_RX} "${bin_path}")
  if(CMAKE_HOST_WIN32)
    set(ENV{Path} "${bin_path};ENV{Path}")
  else()
    set(ENV{Path} "${bin_path}:ENV{Path}")
  endif()
endif()

if(gen MATCHES "^Ninja")
  # Even if any messages are not bufferd by this wrapper script, all messages are buffered by Ninja.
  # Therefore, in the case of Ninja, there are several minutes without any messages during execution
  # of library generator actually generating or regenerating libraries. Since such situation cannot
  # be avoided, we put all messages into the output buffer so that we remove unnecessary messages.
  execute_process(
    COMMAND ${cmd} ${cmd_args_list}
    #COMMAND_ECHO STDOUT # For debugging.
    ENCODING OEM
    OUTPUT_VARIABLE output
    ERROR_VARIABLE output
    RESULT_VARIABLE result
  )
else()
  # On the other hand, in the case of other build systems such as Make, any messages are not buffered
  # by the build system. Therefore, in such case, any messages are NOT buffered by this wrapper script
  # so that all messages are showed immediately and several minutes without any messages are avoided.
  execute_process(
    COMMAND ${cmd} ${cmd_args_list}
    #COMMAND_ECHO STDOUT # For debugging.
    # Comment out the following three lines to show all messages immediately without any buffering.
    #ENCODING OEM
    #OUTPUT_VARIABLE output
    #ERROR_VARIABLE output
    RESULT_VARIABLE result
  )
endif()

# The following operation for the output buffer is performed only when Ninja is used.

# Remove the messages.
string(REPLACE "Compiling start" "" output "${output}")
string(REPLACE "Linking start" "" output "${output}")
string(REPLACE "Renesas Optimizing Linker Completed" "" output "${output}")
if(NOT ((NOT gen MATCHES "^Ninja") OR (msg GREATER 0)))
  string(REPLACE "Library Generator Completed" "" output "${output}")
endif()
# Unfortunately the following warning messages cannot be suppressed by library generator's command line option.
# W0561016:The evaluation version is valid for the remaining NUMBER days
# W0561017:The evaluation period has expired
# W0561200:Backed up file LIBRARYNAME.lib into LIBRARYNAME.lbk
string(REGEX REPLACE "(^|\n)W0561016:([^\n]+)" "" output "${output}")
string(REGEX REPLACE "(^|\n)W0561017:([^\n]+)" "" output "${output}")
string(REGEX REPLACE "(^|\n)W0561200:([^\n]+)" "" output "${output}")

if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL "") OR (NOT $ENV{VCTOOLTASK_USE_UNICODE_OUTPUT} STREQUAL ""))

  # Ccode:message --> Libgen: error Ccode: message
  # Ecode:message --> Libgen: error Ecode: message
  # Fcode:message --> Libgen: error Fcode: message
  string(REGEX REPLACE "(^|\n)([CEF][0-9]+):([^\n]+)" "\\1Libgen: error \\2: \\3" output "${output}")

  # Wcode:message --> Libgen: warning Wcode: message
  string(REGEX REPLACE "(^|\n)(W[0-9]+):([^\n]+)" "\\1Libgen: warning \\2: \\3" output "${output}")

  # Mcode:message --> Libgen: info Mcode: message
  string(REGEX REPLACE "(^|\n)(M[0-9]+):([^\n]+)" "\\1Libgen: info \\2: \\3" output "${output}")

  if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL ""))
    # VSCode's Problem View needs `(num)` before `:`
    string(REGEX REPLACE "(^|\n)Libgen: (error|warning|info)([ :][^\n]+)" "\\1Libgen(0): \\2\\3" output "${output}")
  else()
    # Visual Studio's Error List Window does not recognize the following severity in the case of C/C++.
    # info, information, message, suggestion
    string(REGEX REPLACE "(^|\n)Libgen: info([ :][^\n]+)" "\\1Libgen: warning\\2 (Information)" output "${output}")
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
  message("\nCMake RENESAS Library Generator wrapper aborted at the following line due to Library Generator exit code: ${result}")
  message(FATAL_ERROR) # This causes CMake stack dump display and then the script exits with exit code 1.
endif()
