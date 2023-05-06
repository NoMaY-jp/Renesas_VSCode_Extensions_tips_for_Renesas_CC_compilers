# This file is processed when the Renesas C Compiler is used
#
include(Compiler/RENESAS)

### This file is processed when the IAR C Compiler is used
###
### C Language Specification support
###  - Newer versions of the IAR C Compiler require the --c89 flag to build a file under the C90 standard.
###  - Earlier versions of the compiler had C90 by default, not requiring the backward-compatibility flag.
###
### The IAR Language Extensions
###  - The IAR Language Extensions can be enabled by -e flag
###
##include(Compiler/IAR)
##include(Compiler/CMakeCommonCompilerMacros)
##
##if(NOT DEFINED CMAKE_C_COMPILER_VERSION)
##  message(FATAL_ERROR "CMAKE_C_COMPILER_VERSION not detected.  This should be automatic.")
##endif()
##
### Unused after CMP0128
##set(CMAKE_C_EXTENSION_COMPILE_OPTION -e)
##
##if(CMAKE_C_COMPILER_VERSION_INTERNAL VERSION_GREATER 7)
##  set(CMAKE_C90_STANDARD_COMPILE_OPTION --c89)
##  set(CMAKE_C90_EXTENSION_COMPILE_OPTION --c89 -e)
##else()
##  set(CMAKE_C90_STANDARD_COMPILE_OPTION "")
##  set(CMAKE_C90_EXTENSION_COMPILE_OPTION -e)
##endif()
##
##set(CMAKE_C${CMAKE_C_STANDARD_COMPUTED_DEFAULT}_STANDARD_COMPILE_OPTION "")
##set(CMAKE_C${CMAKE_C_STANDARD_COMPUTED_DEFAULT}_EXTENSION_COMPILE_OPTION -e)
##
### Architecture specific
##if("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "ARM")
##  if (CMAKE_C_COMPILER_VERSION VERSION_LESS 5)
##    # IAR C Compiler for Arm prior version 5.xx uses XLINK. Support in CMake is not implemented.
##    message(FATAL_ERROR "IAR C Compiler for Arm version ${CMAKE_C_COMPILER_VERSION} not supported by CMake.")
##  endif()
##  __compiler_iar_ilink(C)
##  __compiler_check_default_language_standard(C 5.10 90 6.10 99 8.10 11 8.40 17)
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "RX")
##  __compiler_iar_ilink(C)
##  __compiler_check_default_language_standard(C 1.10 90 2.10 99 4.10 11 4.20 17)
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "RH850")
##  __compiler_iar_ilink(C)
##  __compiler_check_default_language_standard(C 1.10 90 1.10 99 2.10 11 2.21 17)
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "RL78")
##  if(CMAKE_C_COMPILER_VERSION VERSION_LESS 2)
##    # IAR C Compiler for RL78 prior version 2.xx uses XLINK. Support in CMake is not implemented.
##    message(FATAL_ERROR "IAR C Compiler for RL78 version ${CMAKE_C_COMPILER_VERSION} not supported by CMake.")
##  endif()
##  __compiler_iar_ilink(C)
##  __compiler_check_default_language_standard(C 2.10 90 2.10 99 4.10 11 4.20 17)
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "RISCV")
##  __compiler_iar_ilink(C)
##  __compiler_check_default_language_standard(C 1.10 90 1.10 99 1.10 11 1.21 17)
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "AVR")
##  __compiler_iar_xlink(C)
##  __compiler_check_default_language_standard(C 7.10 99)
##  set(CMAKE_C_OUTPUT_EXTENSION ".r90")
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "MSP430")
##  __compiler_iar_xlink(C)
##  __compiler_check_default_language_standard(C 1.10 90 5.10 99)
##  set(CMAKE_C_OUTPUT_EXTENSION ".r43")
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "V850")
##  __compiler_iar_xlink(C)
##  __compiler_check_default_language_standard(C 1.10 90 4.10 99)
##  set(CMAKE_C_OUTPUT_EXTENSION ".r85")
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "8051")
##  __compiler_iar_xlink(C)
##  __compiler_check_default_language_standard(C 6.10 90 8.10 99)
##  set(CMAKE_C_OUTPUT_EXTENSION ".r51")
##
##elseif("${CMAKE_C_COMPILER_ARCHITECTURE_ID}" STREQUAL "STM8")
##  __compiler_iar_ilink(C)
##  __compiler_check_default_language_standard(C 3.11 90 3.11 99)
##
##else()
##  message(FATAL_ERROR "CMAKE_C_COMPILER_ARCHITECTURE_ID not detected. This should be automatic.")
##endif()

if(NOT CMAKE_C_COMPILER_ARCHITECTURE_ID)
  message(FATAL_ERROR "CMAKE_C_COMPILER_ARCHITECTURE_ID not detected. This should be automatic.")
elseif(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
  # Nothing to do here.
elseif(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
  # Nothing to do here.
elseif(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
  # Nothing to do here.
else()
  # Never come here because of the architecure detection code in the `Modules/CMakePlatformId.h.in`.
endif()

if(NOT CMAKE_C_COMPILER_VERSION)
  message(FATAL_ERROR "CMAKE_C_COMPILER_VERSION not detected. This should be automatic.")
endif()

if(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
  if(CMAKE_C_COMPILER_VERSION VERSION_LESS 2.3)
    # CC-RX V2.02 or older does not support -MM and -MT which are necessary to generate GCC like dependency files.
    message(FATAL_ERROR "Renesas RX Family Compiler version ${CMAKE_C_COMPILER_VERSION} is not supported by CMake.")
  endif()
endif()

if(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
  set(CMAKE_C90_EXTENSION_COMPILE_OPTION "") # This is the default language standard of the compiler.
  set(CMAKE_C90_STANDARD_COMPILE_OPTION  "") # No strict standard option.

  set(CMAKE_C99_EXTENSION_COMPILE_OPTION -lang=c99)
  set(CMAKE_C99_STANDARD_COMPILE_OPTION  -lang=c99) # No strict standard option.

  __compiler_check_default_language_standard(C 2.0 90)

elseif(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
  set(CMAKE_C90_EXTENSION_COMPILE_OPTION "") # This is the default language standard of the compiler.
  set(CMAKE_C90_STANDARD_COMPILE_OPTION  -ansi)

  if(CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 1.6)
    set(CMAKE_C99_EXTENSION_COMPILE_OPTION -lang=c99)
    set(CMAKE_C99_STANDARD_COMPILE_OPTION  -lang=c99 -ansi)
  endif()

  __compiler_check_default_language_standard(C 1.0 90)

elseif(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
  set(CMAKE_C90_EXTENSION_COMPILE_OPTION "") # This is the default language standard of the compiler.
  set(CMAKE_C90_STANDARD_COMPILE_OPTION  -Xansi)

  if(CMAKE_C_COMPILER_VERSION VERSION_GREATER_EQUAL 1.7)
    set(CMAKE_C99_EXTENSION_COMPILE_OPTION -lang=c99)
    set(CMAKE_C99_STANDARD_COMPILE_OPTION  -lang=c99 -Xansi)
  endif()

  __compiler_check_default_language_standard(C 1.0 90)

endif()

__compiler_renesas(C)

if((NOT DEFINED CMAKE_DEPENDS_USE_COMPILER OR CMAKE_DEPENDS_USE_COMPILER)
    AND CMAKE_GENERATOR MATCHES "Makefiles|WMake"
    AND CMAKE_DEPFILE_FLAGS_C
    )
  # dependencies are computed by the compiler itself
  set(CMAKE_C_DEPFILE_FORMAT gcc)
  set(CMAKE_C_DEPENDS_USE_COMPILER TRUE)
endif()
