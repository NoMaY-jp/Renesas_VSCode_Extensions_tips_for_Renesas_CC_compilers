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
  if(CMAKE_ARGV${arg_n} MATCHES "^-xcopt=(.+)")
    string(REPLACE ",-" " -" xcopts_t "${CMAKE_MATCH_1}")
    string(JOIN " " xcopts ${xcopts} ${xcopts_t})
  elseif(arg_n EQUAL 10)
    set(ifile ${CMAKE_ARGV${arg_n}})
  elseif(arg_n EQUAL 11)
    set(ofile ${CMAKE_ARGV${arg_n}})
  endif()
endforeach()

string(JOIN " " tmp_string ${ifile} ${ofile} ${xcopts})
separate_arguments(cmd_args_list NATIVE_COMMAND ${tmp_string})

if(msg GREATER 0)
  message("X Converter:")
  #message("DEBUG: Renesas ${arc} ${ver} (Generator: ${gen}) (Message mode: ${msg})")
  #message("DEBUG: cmd = ${cmd}")
  message("DEBUG: args(script) = ${wpr_args_string}")
  message("DEBUG: ifile = ${ifile}")
  message("DEBUG: ofile = ${ofile}")
  message("DEBUG: xcopts = ${xcopts}")
  list(JOIN cmd_args_list " " cmd_args_string)
  message("DEBUG: args(native) = ${cmd_args_string}")
endif()

execute_process(
  COMMAND ${cmd} ${cmd_args_list}
  #COMMAND_ECHO STDOUT # For debugging.
  ENCODING OEM
  OUTPUT_VARIABLE output
  ERROR_VARIABLE output
  RESULT_VARIABLE result
)

# FIXME: Is it better to prepaire command line option something like explicit silencer flag?
if(output MATCHES "Error|Usage")
  # Renesas X Converter does not return any error exit code greater than 0.
  set(result 1)

  # Append the error message for Visual Studio Code or Visual Studio.
  if(($ENV{TERM_PROGRAM} STREQUAL "vscode") OR (NOT $ENV{VSCODE_PID} STREQUAL ""))
    # For Visual Studio Code's Problem Window.
    string(APPEND output "X Converter(0): error: conversion failed.")
  elseif(NOT $ENV{VCTOOLTASK_USE_UNICODE_OUTPUT} STREQUAL "")
    # For Visual Studio's Error List Window.
    string(APPEND output "X Converter: error: conversion failed.")
  endif()

  # Remove blank lines.
  string(REGEX REPLACE "\n+" "\n" output "${output}")
  string(REGEX REPLACE "^\n?([^\n].*[^\n]|[^\n])\n?$" "\\1" output "${output}")
  #string(REGEX REPLACE "^\n+$" "" output "${output}") # No this case.
  message(${output})
else()
  if((NOT gen MATCHES "^Ninja") OR (msg GREATER 0))
    message("X Converter Completed")
  endif()
endif()

if(result GREATER 0)
  # To reduce CMake stack dump display, it is better to use neither macro() nor function().
  # TODO: Is there any way to disable CMake stack dump display?
  # TODO: Is there any way for the script to exit with exit code greater than 1?
  message("\nCMake RENESAS X Converter wrapper aborted at the following line due to X Converter error")
  message(FATAL_ERROR) # This causes CMake stack dump display and then the script exits with exit code 1.
endif()
