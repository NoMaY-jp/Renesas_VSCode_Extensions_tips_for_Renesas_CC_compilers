#message("DEBUG: Generic-RenesasCC is included.")
#message("DEBUG: CMAKE_SYSTEM_NAME = ${CMAKE_SYSTEM_NAME}")
#message("DEBUG: CMAKE_SYSTEM_PROCESSOR = ${CMAKE_SYSTEM_PROCESSOR}")
#message("DEBUG: CMAKE_SYSTEM_ARCH = ${CMAKE_SYSTEM_ARCH}")
########message("DEBUG: CMAKE_EXECUTABLE_SUFFIX ${CMAKE_EXECUTABLE_SUFFIX}")

# This is a platform definition file for embedded platforms
# using Renesas CC compilers.

include(Platform/Generic)

# Override the setting for Renesas CC compilers.
if(NOT CMAKE_SYSTEM_PROCESSOR)
  # Nothing to do.

elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL RX)
  set(CMAKE_SYSTEM_INCLUDE_PATH /include )

elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL RL78)
  set(CMAKE_SYSTEM_INCLUDE_PATH /inc )

elseif(CMAKE_SYSTEM_PROCESSOR STREQUAL RH850)
  set(CMAKE_SYSTEM_INCLUDE_PATH /inc )

endif()
