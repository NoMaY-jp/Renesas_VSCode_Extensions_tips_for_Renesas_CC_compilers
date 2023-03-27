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
  if(CMAKE_ARGV${arg_n} MATCHES "^([^-].*)")
    set(src_name ${CMAKE_MATCH_1})
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-MF=)(.+)")
    set(dep_name ${CMAKE_MATCH_2})
    list(APPEND dep_args_list ${CMAKE_MATCH_1}${CMAKE_MATCH_2})
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-M)(.*)")
    list(APPEND dep_args_list ${CMAKE_MATCH_1}${CMAKE_MATCH_2})
    set(CMAKE_ARGV${arg_n} " ")
  elseif(CMAKE_ARGV${arg_n} MATCHES "^(-output=obj=)(.+)") # This option is RX only.
    set(obj_name ${CMAKE_MATCH_2})
  else()
    if(arc STREQUAL RX)
      if(CMAKE_ARGV${arg_n} MATCHES "^(-listfile=)(.+|$)")
        set(output_lst_arg_opt  ${CMAKE_MATCH_1})
        set(output_lst_arg_path ${CMAKE_MATCH_2})
      elseif(CMAKE_ARGV${arg_n} MATCHES "^(-define=)(.+)")
        set(defs_opt  ${CMAKE_MATCH_1})
        set(defs_defs ${CMAKE_MATCH_2})
        set(defs_cvrt )
        while(defs_defs)
          if(defs_defs MATCHES "(^[^=,]+)=(\"[^\"]*\"|[^,]*)(,.+|$)")
            string(JOIN "," defs_cvrt ${defs_cvrt} ${CMAKE_MATCH_1}=${CMAKE_MATCH_2})
          elseif(defs_defs MATCHES "(^[^=,]+)()(,.+|$)")
            string(JOIN "," defs_cvrt ${defs_cvrt} ${CMAKE_MATCH_1}=1)
          elseif(defs_defs MATCHES "(^)()(,.+|$)")
            # Nothing to do.
          endif()
          if(CMAKE_MATCH_3)
            string(SUBSTRING ${CMAKE_MATCH_3} 1 -1 defs_defs)
          else()
            set(defs_defs )
          endif()
        endwhile()
        set(CMAKE_ARGV${arg_n} ${defs_opt}${defs_cvrt})
      elseif(CMAKE_ARGV${arg_n} MATCHES "^(-subcommand=)(.+)")
        # For not only CMake-generated subcommand files but also user own subcommand files.
        set(rsp_name ${CMAKE_MATCH_2})
        file(READ ${rsp_name} rsp_content_string)
        separate_arguments(rsp_content_list NATIVE_COMMAND ${rsp_content_string})
        foreach(opt ${rsp_content_list})
          if(opt MATCHES "^(-listfile=)(.+|$)")
            set(output_lst_arg_opt   ${CMAKE_MATCH_1})
            set(output_lst_arg_path  ${CMAKE_MATCH_2})
          elseif(opt MATCHES "^(-define=)(.+)")
            set(defs_opt  ${CMAKE_MATCH_1})
            set(defs_defs ${CMAKE_MATCH_2})
            set(defs_cvrt )
            while(defs_defs)
              if(defs_defs MATCHES "(^[^=,]+)=(\"[^\"]*\"|[^,]*)(,.+|$)")
                string(JOIN "," defs_cvrt ${defs_cvrt} ${CMAKE_MATCH_1}=${CMAKE_MATCH_2})
              elseif(defs_defs MATCHES "(^[^=,]+)()(,.+|$)")
                string(JOIN "," defs_cvrt ${defs_cvrt} ${CMAKE_MATCH_1}=1)
              elseif(defs_defs MATCHES "(^)()(,.+|$)")
                # Nothing to do.
              endif()
              if(CMAKE_MATCH_3)
                string(SUBSTRING ${CMAKE_MATCH_3} 1 -1 defs_defs)
              else()
                set(defs_defs )
              endif()
            endwhile()
            set(opt ${defs_opt}${defs_cvrt})
          endif()
          #message("DEBUG: ${opt}")
          string(JOIN "\n" sub_content_string ${sub_content_string} ${opt})
        endforeach()
        if(NOT sub_name)
          # FIXME: Assert: obj_name
          set(sub_name ${obj_name}.sub)
          set(CMAKE_ARGV${arg_n} -subcommand=${sub_name})
        else()
          set(CMAKE_ARGV${arg_n} " ")
        endif()
      endif()
    endif()
  endif()
  list(APPEND cmd_args_list ${CMAKE_ARGV${arg_n}})
endforeach()
if(sub_name)
  #message("DEBUG: sub_name=${sub_name}")
  file(WRITE ${sub_name} ${sub_content_string})
endif()

# Renesas compiler options' additional behavior
# Assembler's `-listfile=` can be followed by one of the following items.
# .
# ..
# <path>/
# Nothing are followed. (This is the same as followed by `.`.)
# Please do not use the path which includes any Japanese characters.
if(arc STREQUAL RX AND output_lst_arg_opt)
  math(EXPR cmd_args_last "${cmd_args_last} + 1")
  get_filename_component(src_name_wle ${src_name} NAME_WLE)
  if(output_lst_arg_opt AND (NOT output_lst_arg_path))
    set(CMAKE_ARGV${cmd_args_last} -listfile=${src_name_wle}.lst)
  elseif(output_lst_arg_path STREQUAL .)
    set(CMAKE_ARGV${cmd_args_last} -listfile=${src_name_wle}.lst)
  elseif(output_lst_arg_path STREQUAL ..)
    set(CMAKE_ARGV${cmd_args_last} -listfile=../${src_name_wle}.lst)
  elseif(output_lst_arg_path MATCHES "(.*)(/|\\\\)$")
    set(CMAKE_ARGV${cmd_args_last} -listfile=${CMAKE_MATCH_1}/${src_name_wle}.lst)
  elseif(output_lst_arg_path MATCHES "(.*)(/|\\\\)\\.$")
    set(CMAKE_ARGV${cmd_args_last} -listfile=${CMAKE_MATCH_1}/${src_name_wle}.lst)
  elseif(output_lst_arg_path MATCHES "(.*)(/|\\\\)\\.\\.$")
    set(CMAKE_ARGV${cmd_args_last} -listfile=${CMAKE_MATCH_1}/../${src_name_wle}.lst)
  endif()
  list(APPEND cmd_args_list ${CMAKE_ARGV${cmd_args_last}})
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
    # No such options.
  elseif(arc STREQUAL RL78)
    list(APPEND cmd_args_list -no_warning=0-99999)
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
  message("\nCMake RENESAS assembler wrapper aborted at the following line due to assembler exit code: ${result}")
  message(FATAL_ERROR) # This causes CMake stack dump display and then the script exits with exit code 1.
endif()

# Renesas CC-{RX, RL, RH}'s dependency file is not compatible with GCC's dependency file, and
# CMake can not parse the file due to the incompatibility. Therefore the file has to be converted.
if(dep_name AND (NOT gen MATCHES "^Ninja"))
  file(READ ${dep_name} dep_file)
  string(REGEX REPLACE "\n[^:]*: ([^\n]*)" " \\\\\n  \\1" dep_file "${dep_file}")
  file(WRITE ${dep_name} ${dep_file})
endif()
