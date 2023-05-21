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
  if(CMAKE_ARGV${arg_n} MATCHES "^-subcommand_rsp=(.+)\\.([^.]+)$")
    # This is not a native option.
    set(rsp_name ${CMAKE_MATCH_1}.${CMAKE_MATCH_2})
    set(sub_name ${CMAKE_MATCH_1}.sub)
    set(CMAKE_ARGV${arg_n} "-subcommand=${sub_name}")
    #message("DEBUG: rsp_name=${rsp_name}")
    #message("DEBUG: sub_name=${sub_name}")
    file(READ ${rsp_name} rsp_sub_cnvt)
    string(REGEX REPLACE "^ *([^- ].*)" "-Input=\\1" rsp_sub_cnvt "${rsp_sub_cnvt}")
    string(REGEX REPLACE "\n *([^- ][^\n]*)" "\n-Input=\\1" rsp_sub_cnvt "${rsp_sub_cnvt}")
    string(REGEX REPLACE " *-library=" "\n-library=" rsp_sub_cnvt "${rsp_sub_cnvt}")
    file(WRITE ${sub_name} ${rsp_sub_cnvt})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-start=)(.+)")
    set(start_opt ${CMAKE_MATCH_1})
    set(start_sec ${CMAKE_MATCH_2})
    if(gen MATCHES "^Ninja")
      string(REPLACE "$$" "$" start_sec ${start_sec})
    else()
      string(REPLACE "\\$" "$" start_sec ${start_sec})
    endif()
    set(CMAKE_ARGV${arg_n} ${start_opt}${start_sec})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-device=)(.+)" AND arc STREQUAL RL78)
    get_filename_component(device_file_path ${CMAKE_MATCH_2} PATH)
    if(NOT device_file_path)
      if(e2studio_support_area STREQUAL -)
        # For CS+
        get_filename_component(device_file_path ${cmd}/../../../../Device/RL78/Devicefile ABSOLUTE)
      else()
        # For e2 studio
        get_filename_component(device_file_path ${e2studio_support_area}/DebugComp/RL78/RL78/Common ABSOLUTE)
      endif()
      if(EXISTS ${device_file_path}/${CMAKE_MATCH_2})
        set(CMAKE_ARGV${arg_n} ${CMAKE_MATCH_1}${device_file_path}/${CMAKE_MATCH_2})
      endif()
    endif()
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-[Nn][Oo][Pp][Rr][Ee].*)")
    set(noprelink_opt ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-link_language=(C|CXX)$")
    # This is not a native option.
    set(link_language ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-compile_options=.*-cpu=(S1|S2|S3)$")
    # This is not a native option.
    set(link_cpu_type ${CMAKE_MATCH_1})
  endif()
endforeach()

# Note: Renesas exe linker options' additional behavior
# If `-form=` is not specified, both -form=abs and -form=s are regarded as being specified.
# If only -form=s is specified, -form=abs is regarded as being specified. On the other hand,
# if only -form=abs is specified, -form=s is not regarded as being specified.
# If only either of -form=<hex|bin> is specified, -form=abs is regarded as being specified
# but -form=s is not regarded as being specified in addition to the -form=<hex|bin>.
foreach(arg_n RANGE ${cmd_args_first} ${cmd_args_last})
  if(CMAKE_ARGV${arg_n} MATCHES "^-form_exe=(.+)")
    # This is not a native option.
    set(exe_link_mode true)
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-output_exe=(.+)")
    # This is not a native option.
    set(exe_link_abs_name ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-[Ff][Oo][^=]*=[Aa]")
    # -form=absolute
    set(explicit_form_abs true)
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-[Ff][Oo][^=]*=[SsHhBb]")
    # -form=stype
    # -form=hexadecimal
    # -form=binary
    set(explicit_form_mot_hex_bin true)
  endif()
endforeach()
if(exe_link_mode)
  if(explicit_form_abs AND NOT explicit_form_mot_hex_bin)
    set(args2 "")
  else()
    set(args2 "2")
  endif()
else()
    set(args2 "")
endif()

# Note: Renesas exe linker options' additional behavior
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
foreach(arg_n RANGE ${cmd_args_first} ${cmd_args_last})
  if(CMAKE_ARGV${arg_n} MATCHES "^-(compile_options|link_language|lbgopt|xcopt)")
    # These are not native options.
    # Nothing to do.
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-form_exe=(.+)")
    # This is not a native option.
    # Nothing to do.
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-output_exe=(.+)")
    # This is not a native option.
    # Nothing to do.
  elseif(CMAKE_ARGV${arg_n} MATCHES "^-[Ff][Oo][^=]*=[SsHhBb]")
    # -form=stype
    # -form=hexadecimal
    # -form=binary
    if(args2)
      list(APPEND cmd_args2_list ${CMAKE_ARGV${arg_n}})
    else()
      list(APPEND cmd_args_list ${CMAKE_ARGV${arg_n}})
    endif()
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-[^=]+)")
    string(TOUPPER ${CMAKE_MATCH_1} opt)
    if(opt MATCHES "^-(BY|FIX_RECORD_LENGTH_AND_ALIGN|REC|END_RECORD|S9|SP|CR|OU)")
      # -byte_count=<num>
      # -fix_record_length_and_align=<num>
      # -record=<item>
      # -end_record=<item>
      # -s9
      # -space[=<num|item>]
      # -crc=<sub_option>
      # -output=<sub_option>
      if(args2)
        list(APPEND cmd_args2_list ${CMAKE_ARGV${arg_n}})
      else()
        list(APPEND cmd_args_list ${CMAKE_ARGV${arg_n}})
      endif()
    else()
      list(APPEND cmd_args_list ${CMAKE_ARGV${arg_n}})
    endif()
  else()
    list(APPEND cmd_args_list ${CMAKE_ARGV${arg_n}})
  endif()
endforeach()

if(exe_link_mode)
  if(explicit_form_abs)
    list(APPEND cmd_args_list -output=${exe_link_abs_name})
  else()
    list(APPEND cmd_args_list -form=abs -output=${exe_link_abs_name})
  endif()
  if((NOT noprelink_opt) AND (NOT link_language STREQUAL CXX))
    if(arc STREQUAL RX)
      list(APPEND cmd_args_list -noprelink)
    endif()
  endif()
  list(JOIN cmd_args_list " " cmd_args_string)
  if(args2)
    if(explicit_form_mot_hex_bin)
      list(PREPEND cmd_args2_list -nologo ${exe_link_abs_name})
    else()
      list(PREPEND cmd_args2_list -nologo ${exe_link_abs_name} -form=s)
    endif()
    # Suppress the following warning messages in the case of other than `-form=abs`. Because there
    # are no way to suppress them by user's toolchain file(s) or user's CMakeLists.txt file(s)
    # in such cases.
    # W0561016:The evaluation version is valid for the remaining NUMBER days
    # W0561017:The evaluation period has expired
    # Note: Somehow `-nomessage` is necessary though it is documented as default.
    if(arc STREQUAL RX)
      if(ver VERSION_GREATER_EQUAL 2.7)
        list(APPEND cmd_args2_list -nomessage -change_message=information=1016,1017)
      endif()
    elseif(arc STREQUAL RL78)
      if(ver VERSION_GREATER_EQUAL 1.5)
        list(APPEND cmd_args2_list -nomessage -change_message=information=1016,1017)
      endif()
    elseif(arc STREQUAL RH850)
      if(ver VERSION_GREATER_EQUAL 1.6)
        list(APPEND cmd_args2_list -nomessage -change_message=information=1016,1017)
      endif()
    endif()
    list(JOIN cmd_args2_list " " cmd_args2_string)
  endif()
else()
  # Suppress the following warning messages in the case of other than `-form=abs`. Because there
  # are no way to suppress them by user's toolchain file(s) or user's CMakeLists.txt file(s)
  # in such cases. For example, in the case of linking static library.
  # W0561016:The evaluation version is valid for the remaining NUMBER days
  # W0561017:The evaluation period has expired
  # W0561200:Backed up file LIBRARYNAME.lib into LIBRARYNAME.lbk
  # Note: Though `-nomessage` is documented as default, it is used just to be sure.
  if(arc STREQUAL RX)
    if(ver VERSION_GREATER_EQUAL 2.7)
      list(APPEND cmd_args_list -nomessage -change_message=information=1016,1017,1200)
    else()
      list(APPEND cmd_args_list -nomessage -change_message=information=1200)
    endif()
  elseif(arc STREQUAL RL78)
    if(ver VERSION_GREATER_EQUAL 1.5)
      list(APPEND cmd_args_list -nomessage -change_message=information=1016,1017,1200)
    else()
      list(APPEND cmd_args_list -nomessage -change_message=information=1200)
    endif()
  elseif(arc STREQUAL RH850)
    if(ver VERSION_GREATER_EQUAL 1.6)
      list(APPEND cmd_args_list -nomessage -change_message=information=1016,1017,1200)
    else()
      list(APPEND cmd_args_list -nomessage -change_message=information=1200)
    endif()
  endif()
  list(JOIN cmd_args_list " " cmd_args_string)
endif()

if((msg GREATER 1) OR ((msg EQUAL 1) AND exe_link_mode))
  message("Linker:")
  #message("DEBUG: Renesas ${arc} ${ver} (Generator: ${gen}) (Message mode: ${msg})")
  #message("DEBUG: cmd = ${cmd}")
  message("DEBUG: args(script) = ${wpr_args_string}")
  message("DEBUG: args(native) = ${cmd_args_string}")
  if(args2)
    message("DEBUG: args(native2) = ${cmd_args2_string}")
  endif()
endif()

# Add the library path of the compiler to library search environment variable of Renesas linker.
if(CMAKE_HOST_WIN32)
  set(path_join_char ";")
else()
  set(path_join_char ":")
endif()
get_filename_component(root_path ${cmd}/../.. ABSOLUTE)
if(DEFINED ENV{HLNK_DIR})
  set(ENV{HLNK_DIR} "${root_path}${path_join_char}$ENV{HLNK_DIR}")
else()
  set(ENV{HLNK_DIR} "${root_path}")
endif()
get_filename_component(lib_path ${cmd}/../../lib ABSOLUTE)
set(ENV{HLNK_DIR} "${lib_path}${path_join_char}$ENV{HLNK_DIR}")
if(link_language STREQUAL CXX AND link_cpu_type)
  get_filename_component(lib_cxx_cpu_path ${cmd}/../../lib/CXX/${link_cpu_type} ABSOLUTE)
  set(ENV{HLNK_DIR} "${lib_cxx_cpu_path}${path_join_char}$ENV{HLNK_DIR}")
endif()
if(exe_link_mode AND msg GREATER 0)
  message("DEBUG: HLNK_DIR = $ENV{HLNK_DIR}")
endif()

# Renesas CC-RX needs some settings of environment variables.
# ccrx.exe:  The `BIN_RX` (or `Path`) has to be set to contain the path to macrx.exe of the compiler.
# asrx.exe:  The `BIN_RX` (or `Path`) has to be set to contain the path to macrx.exe of the compiler.
# lbgrx.exe: The `BIN_RX` has to be set to point the path to ccrx.exe of the compiler.
# rlink.exe: The `Path` has to be set to contain the path to prelnk.exe of the compiler without `-noprelink` flag.
# It has to be taken care that lbgrx.exe calls both ccrx.exe and rlink.exe and 
# the 'Path' has to be set for the both. (But the both path are the same usually.)
if(arc STREQUAL RX)
  get_filename_component(bin_path ${cmd}/.. ABSOLUTE)
  if(CMAKE_HOST_WIN32)
    set(ENV{Path} "${bin_path};ENV{Path}")
  else()
    set(ENV{Path} "${bin_path}:ENV{Path}")
  endif()
endif()

execute_process(
  COMMAND ${cmd} ${cmd_args_list}
  #COMMAND_ECHO STDOUT # For debugging.
  ENCODING OEM
  OUTPUT_VARIABLE output
  ERROR_VARIABLE output
  RESULT_VARIABLE result
)

# Reduce the message. (The message may be removed later completely.)
if((NOT exe_link_mode) OR args2)
  string(REPLACE "Renesas Optimizing Linker Completed" "" output "${output}")
endif()

if(result EQUAL 0 AND args2)
  execute_process(
    COMMAND ${cmd} ${cmd_args2_list}
    #COMMAND_ECHO STDOUT # For debugging.
    ENCODING OEM
    OUTPUT_VARIABLE output_args2
    ERROR_VARIABLE output_args2
    RESULT_VARIABLE result_args2
  )

  set(output ${output}\n${output_args2})
  set(result ${result_args2})
endif()

# Remove the message.
if(NOT ((NOT gen MATCHES "^Ninja") OR (msg GREATER 0)))
  string(REPLACE "Renesas Optimizing Linker Completed" "" output "${output}")
endif()

# Convert the total section size messages.
# RAMDATA SECTION:  hhhhhhhh Byte(s) --> RAMDATA SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s))
# ROMDATA SECTION:  hhhhhhhh Byte(s) --> ROMDATA SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s))
# PROGRAM SECTION:  hhhhhhhh Byte(s) --> PROGRAM SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s))
if(${output} MATCHES "(^|\n)(RAMDATA SECTION:  )([^ ]+)( [^\n]+)")
  math(EXPR octal_value 0x${CMAKE_MATCH_3})
  string(REPLACE "${CMAKE_MATCH_2}${CMAKE_MATCH_3}${CMAKE_MATCH_4}" "${CMAKE_MATCH_2}${CMAKE_MATCH_3}${CMAKE_MATCH_4}  (${octal_value} Byte(s))" output "${output}")
endif()
if(${output} MATCHES "(^|\n)(ROMDATA SECTION:  )([^ ]+)( [^\n]+)")
  math(EXPR octal_value 0x${CMAKE_MATCH_3})
  string(REPLACE "${CMAKE_MATCH_2}${CMAKE_MATCH_3}${CMAKE_MATCH_4}" "${CMAKE_MATCH_2}${CMAKE_MATCH_3}${CMAKE_MATCH_4}  (${octal_value} Byte(s))" output "${output}")
endif()
if(${output} MATCHES "(^|\n)(PROGRAM SECTION:  )([^ ]+)( [^\n]+)")
  math(EXPR octal_value 0x${CMAKE_MATCH_3})
  string(REPLACE "${CMAKE_MATCH_2}${CMAKE_MATCH_3}${CMAKE_MATCH_4}" "${CMAKE_MATCH_2}${CMAKE_MATCH_3}${CMAKE_MATCH_4}  (${octal_value} Byte(s))" output "${output}")
endif()

if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL "") OR (NOT $ENV{VCTOOLTASK_USE_UNICODE_OUTPUT} STREQUAL ""))

  # Ccode:message --> Linker: error Ccode: message
  # Ecode:message --> Linker: error Ecode: message
  # Fcode:message --> Linker: error Fcode: message
  string(REGEX REPLACE "(^|\n)([CEF][0-9]+):([^\n]+)" "\\1Linker: error \\2: \\3" output "${output}")

  # Wcode:message --> Linker: warning Wcode: message
  string(REGEX REPLACE "(^|\n)(W[0-9]+):([^\n]+)" "\\1Linker: warning \\2: \\3" output "${output}")

  # Mcode:message --> Linker: info Mcode: message
  string(REGEX REPLACE "(^|\n)(M[0-9]+):([^\n]+)" "\\1Linker: info \\2: \\3" output "${output}")

  # RAMDATA SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s)) --> Linker: info: RAMDATA SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s))' '
  # ROMDATA SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s)) --> Linker: info: ROMDATA SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s))' '
  # PROGRAM SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s)) --> Linker: info: PROGRAM SECTION:  hhhhhhhh Byte(s)  (d* Bytes(s))' '
  # The last white space is added for Visual Studio (It is ignored in the case of VSCode.)
  string(REGEX REPLACE "(^|\n)(RAMDATA|ROMDATA|PROGRAM)( SECTION:  [^\n]+)" "\\1Linker: info: \\2\\3 " output "${output}")

  if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL ""))
    # VSCode's Problem View needs `(num)` before `:`
    string(REGEX REPLACE "(^|\n)Linker: (error|warning|info)([ :][^\n]+)" "\\1Linker(0): \\2\\3" output "${output}")
  else()
    # Visual Studio's Error List Window does not recognize the following severity in the case of C/C++.
    # info, information, message, suggestion
    string(REGEX REPLACE "(^|\n)Linker: info([ :][^\n]+)" "\\1Linker: warning\\2 (Information)" output "${output}")
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
  message("\nCMake RENESAS linker wrapper aborted at the following line due to linker exit code: ${result}")
  message(FATAL_ERROR) # This causes CMake stack dump display and then the script exits with exit code 1.
endif()
