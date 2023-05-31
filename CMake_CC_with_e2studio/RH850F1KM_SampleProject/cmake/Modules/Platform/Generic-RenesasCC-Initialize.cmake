#message("DEBUG: Generic-RenesasCC-Initialize is included.")
#message("DEBUG: CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
#message("DEBUG: CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
#message("DEBUG: CMAKE_SYSTEM_ARCH = ${CMAKE_SYSTEM_ARCH}")
########message("DEBUG: CMAKE_EXECUTABLE_SUFFIX ${CMAKE_EXECUTABLE_SUFFIX}")

# This is a platform definition file for embedded platforms
# using Renesas CC compilers.

if(NOT CMAKE_SYSTEM_PROCESSOR)
  set(CMAKE_C_COMPILER_ID RenesasCC)
  set(CMAKE_C_COMPILER_ID_RUN TRUE)
  set(CMAKE_CXX_COMPILER_ID RenesasCC)
  set(CMAKE_CXX_COMPILER_ID_RUN TRUE)

elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL RX)
  set(CMAKE_C_COMPILER_ID RenesasCC)
  set(CMAKE_C_COMPILER_ID_RUN TRUE)
  set(CMAKE_CXX_COMPILER_ID RenesasCC)
  set(CMAKE_CXX_COMPILER_ID_RUN TRUE)

  if(NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER ccrx)
  endif()
  if(NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER ccrx)
  endif()

  if(NOT CMAKE_SYSTEM_ARCH)
    # Nothing to do.
  elseif(CMAKE_SYSTEM_ARCH MATCHES "([Rr][Xx][Vv].+)")
    string(TOLOWER ${CMAKE_MATCH_1} CMAKE_MATCH_1)
    if(NOT CMAKE_C_COMPILER_ARG1)
      set(CMAKE_C_COMPILER_ARG1 -isa=${CMAKE_MATCH_1})
    endif()
    if(NOT CMAKE_CXX_COMPILER_ARG1)
      set(CMAKE_CXX_COMPILER_ARG1 -isa=${CMAKE_MATCH_1})
    endif()
  else()
    # If other cases will be added in the future. Do not lower/upper the string for the safe.
    if(NOT CMAKE_C_COMPILER_ARG1)
      set(CMAKE_C_COMPILER_ARG1 -isa=${CMAKE_SYSTEM_ARCH})
    endif()
    if(NOT CMAKE_CXX_COMPILER_ARG1)
      set(CMAKE_CXX_COMPILER_ARG1 -isa=${CMAKE_SYSTEM_ARCH})
    endif()
  endif()

  set(CMAKE_SYSTEM_PROGRAM_PATH /bin /ccrx)

elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL RL78)
  set(CMAKE_C_COMPILER_ID RenesasCC)
  set(CMAKE_C_COMPILER_ID_RUN TRUE)
  set(CMAKE_CXX_COMPILER_ID RenesasCC)
  set(CMAKE_CXX_COMPILER_ID_RUN TRUE)

  if(NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER ccrl)
  endif()
  if(NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER ccrl)
  endif()

  if(NOT CMAKE_SYSTEM_ARCH)
    # Nothing to do.
  elseif(CMAKE_SYSTEM_ARCH MATCHES "([Ss].+)")
    string(TOUPPER ${CMAKE_MATCH_1} CMAKE_MATCH_1)
    if(NOT CMAKE_C_COMPILER_ARG1)
      set(CMAKE_C_COMPILER_ARG1 -cpu=${CMAKE_MATCH_1})
    endif()
    if(NOT CMAKE_CXX_COMPILER_ARG1)
      set(CMAKE_CXX_COMPILER_ARG1 -cpu=${CMAKE_MATCH_1})
    endif()
  else()
    # If other cases will be added in the future. Do not lower/upper the string for the safe.
    if(NOT CMAKE_C_COMPILER_ARG1)
      set(CMAKE_C_COMPILER_ARG1 -cpu=${CMAKE_SYSTEM_ARCH})
    endif()
    if(NOT CMAKE_CXX_COMPILER_ARG1)
      set(CMAKE_CXX_COMPILER_ARG1 -cpu=${CMAKE_SYSTEM_ARCH})
    endif()
  endif()

  set(CMAKE_SYSTEM_PROGRAM_PATH /bin /ccrl)

elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL RH850)
  set(CMAKE_C_COMPILER_ID RenesasCC)
  set(CMAKE_C_COMPILER_ID_RUN TRUE)
  #set(CMAKE_CXX_COMPILER_ID RenesasCC) # CC-RH does not support C++ as of todyay.
  #set(CMAKE_CXX_COMPILER_ID_RUN TRUE)  # CC-RH does not support C++ as of todyay.

  if(NOT CMAKE_C_COMPILER)
    set(CMAKE_C_COMPILER ccrh)
  endif()
  #if(NOT CMAKE_CXX_COMPILER) # CC-RH does not support C++ as of todyay.
  #  set(CMAKE_CXX_COMPILER ccrh)
  #endif()

  if(NOT CMAKE_SYSTEM_ARCH)
    # Nothing to do.
  elseif(CMAKE_SYSTEM_ARCH MATCHES "([Gg].+)")
    string(TOLOWER ${CMAKE_MATCH_1} CMAKE_MATCH_1)
    if(NOT CMAKE_C_COMPILER_ARG1)
      set(CMAKE_C_COMPILER_ARG1 -Xcpu=${CMAKE_MATCH_1})
    endif()
    #if(NOT CMAKE_CXX_COMPILER_ARG1) # CC-RH does not support C++ as of todyay.
    #  set(CMAKE_CXX_COMPILER_ARG1 -Xcpu=${CMAKE_MATCH_1}})
    #endif()
  else()
    # If other cases will be added in the future. Do not lower/upper the string for the safe.
    if(NOT CMAKE_C_COMPILER_ARG1)
      set(CMAKE_C_COMPILER_ARG1 -Xcpu=${CMAKE_SYSTEM_ARCH})
    endif()
    #if(NOT CMAKE_CXX_COMPILER_ARG1) # CC-RH does not support C++ as of todyay.
    #  set(CMAKE_CXX_COMPILER_ARG1 -Xcpu=${CMAKE_SYSTEM_ARCH})
    #endif()
  endif()

  set(CMAKE_SYSTEM_PROGRAM_PATH /bin /ccrh)

else()
  message(FATAL_ERROR "CMAKE_SYSTEM_PROCESSOR: Processor ${CMAKE_SYSTEM_PROCESSOR} is unknown.")
endif()
