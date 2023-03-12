# This file is processed when the Renesas C++ Compiler is used
#
#  - C++ Language is supported by only CC-RX.
#  - C++ Language Specification is compatible with Visual C++ 6.0.
#
include(Compiler/RENESAS)

### This file is processed when the IAR C++ Compiler is used
###
### C++ Language Specification support
###  - Newer versions of the IAR C++ Compiler require the --c++ flag to build a C++ file.
###    Earlier versions for non-ARM architectures provided Embedded C++, enabled with the --eec++ flag.
###
### The IAR Language Extensions
###  - The IAR Language Extensions can be enabled by -e flag
###
##include(Compiler/IAR)
##include(Compiler/CMakeCommonCompilerMacros)
##
##if(NOT DEFINED CMAKE_CXX_COMPILER_VERSION)
##  message(FATAL_ERROR "CMAKE_CXX_COMPILER_VERSION not detected. This should be automatic.")
##endif()
##
### Whenever needed, override this default behavior using CMAKE_IAR_CXX_FLAG in your toolchain file.
##if(NOT CMAKE_IAR_CXX_FLAG)
##  set(_CMAKE_IAR_MODERNCXX_LIST 14 17)
##  if(${CMAKE_CXX_STANDARD_COMPUTED_DEFAULT} IN_LIST _CMAKE_IAR_MODERNCXX_LIST OR
##     ("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "ARM" AND ${CMAKE_CXX_STANDARD_COMPUTED_DEFAULT} EQUAL 98))
##    string(PREPEND CMAKE_CXX_FLAGS "--c++ ")
##  else()
##    string(PREPEND CMAKE_CXX_FLAGS "--eec++ ")
##  endif()
##  unset(_CMAKE_IAR_MODERNCXX_LIST)
##endif()
##
##set(CMAKE_CXX_STANDARD_COMPILE_OPTION "")
##set(CMAKE_CXX_EXTENSION_COMPILE_OPTION -e) # Unused after CMP0128
##
##set(CMAKE_CXX${CMAKE_CXX_STANDARD_COMPUTED_DEFAULT}_STANDARD_COMPILE_OPTION "")
##set(CMAKE_CXX${CMAKE_CXX_STANDARD_COMPUTED_DEFAULT}_EXTENSION_COMPILE_OPTION -e)
##
### Architecture specific
##if("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "ARM")
##  if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5)
##    # IAR C++ Compiler for Arm prior version 5.xx uses XLINK. Support in CMake is not implemented.
##    message(FATAL_ERROR "IAR C++ Compiler for Arm version ${CMAKE_CXX_COMPILER_VERSION} not supported by CMake.")
##  endif()
##  __compiler_iar_ilink(CXX)
##  __compiler_check_default_language_standard(CXX 5.10 98 8.10 14 8.40 17)
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "RX")
##  __compiler_iar_ilink(CXX)
##  __compiler_check_default_language_standard(CXX 2.10 98 4.10 14 4.20 17)
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "RH850")
##  __compiler_iar_ilink(CXX)
##  __compiler_check_default_language_standard(CXX 1.10 98 2.10 14 2.21 17)
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "RL78")
##  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 2)
##    # # IAR C++ Compiler for RL78 prior version 2.xx uses XLINK. Support in CMake is not implemented.
##    message(FATAL_ERROR "IAR C++ Compiler for RL78 version ${CMAKE_CXX_COMPILER_VERSION} not supported by CMake.")
##  endif()
##  __compiler_iar_ilink(CXX)
##  __compiler_check_default_language_standard(CXX 2.10 98 4.10 14 4.20 17)
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "RISCV")
##  __compiler_iar_ilink(CXX)
##  __compiler_check_default_language_standard(CXX 1.10 98 1.10 14 1.21 17)
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "AVR")
##  __compiler_iar_xlink(CXX)
##  __compiler_check_default_language_standard(CXX 7.10 98)
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "MSP430")
##  __compiler_iar_xlink(CXX)
##  __compiler_check_default_language_standard(CXX 5.10 98)
##  set(CMAKE_CXX_OUTPUT_EXTENSION ".r43")
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "V850")
##  __compiler_iar_xlink(CXX)
##  __compiler_check_default_language_standard(CXX 1.10 98)
##  set(CMAKE_C_OUTPUT_EXTENSION ".r85")
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "8051")
##  __compiler_iar_xlink(CXX)
##  __compiler_check_default_language_standard(CXX 6.10 98)
##  set(CMAKE_C_OUTPUT_EXTENSION ".r51")
##
##elseif("${CMAKE_CXX_COMPILER_ARCHITECTURE_ID}" STREQUAL "STM8")
##  __compiler_iar_ilink(CXX)
##  __compiler_check_default_language_standard(CXX 3.11 98)
##
##else()
##  message(FATAL_ERROR "CMAKE_CXX_COMPILER_ARCHITECTURE_ID not detected. This should be automatic." )
##endif()

if(NOT CMAKE_CXX_COMPILER_ARCHITECTURE_ID)
  message(FATAL_ERROR "CMAKE_CXX_COMPILER_ARCHITECTURE_ID not detected. This should be automatic.")
elseif(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
  # Nothing to do here.
elseif(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
  message(FATAL_ERROR "C++ is not supported by Renesas RL78 Family Compiler.")
elseif(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
  message(FATAL_ERROR "C++ is not supported by Renesas RH850 Family Compiler.")
else()
  # Never come here because of the architecure detection code in the `Modules/CMakePlatformId.h.in`.
endif()

if(NOT CMAKE_CXX_COMPILER_VERSION)
  message(FATAL_ERROR "CMAKE_CXX_COMPILER_VERSION not detected. This should be automatic.")
endif()

if(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
  if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 2.0)
    message(FATAL_ERROR "Renesas RX Family Compiler version ${CMAKE_CXX_COMPILER_VERSION} is not supported by CMake.")
  endif()
endif()

__compiler_renesas(CXX)

if((NOT DEFINED CMAKE_DEPENDS_USE_COMPILER OR CMAKE_DEPENDS_USE_COMPILER)
    AND CMAKE_GENERATOR MATCHES "Makefiles|WMake"
    AND CMAKE_DEPFILE_FLAGS_CXX
    )
  # dependencies are computed by the compiler itself
  set(CMAKE_CXX_DEPFILE_FORMAT gcc)
  set(CMAKE_CXX_DEPENDS_USE_COMPILER TRUE)
endif()

if(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
  set(CMAKE_CXX98_STANDARD_COMPILE_OPTION "") # FIXME: CC-RX does not support any C++ standards.
  set(CMAKE_CXX98_EXTENSION_COMPILE_OPTION "") # FIXME: CC-RX does not support any C++ standards.

  __compiler_check_default_language_standard(CXX 2.0 98) # FIXME: CC-RX does not support any C++ standards.

elseif(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
  # Nothing to do here. (C++ is not supported.)

elseif(CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
  # Nothing to do here. (C++ is not supported.)

endif()
