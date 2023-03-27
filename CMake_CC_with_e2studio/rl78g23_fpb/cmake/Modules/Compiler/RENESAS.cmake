# This file is processed when the Renesas C Compiler is used
#
# CPU <arch> supported in CMake: RX, RL78 and RH850
#
# The compiler user documentation is architecture-dependent
# and it can found with the product installation under Help/Compiler-CC{RX, RL, RH}.chm
#
#
include_guard()

### This file is processed when the IAR C/C++ Compiler is used
###
### CPU <arch> supported in CMake: 8051, Arm, AVR, MSP430, RH850, RISC-V, RL78, RX and V850
###
### The compiler user documentation is architecture-dependent
### and it can found with the product installation under <arch>/doc/{EW,BX}<arch>_DevelopmentGuide.ENU.pdf
###
###
##include_guard()
##
##macro(__compiler_iar_ilink lang)
##  set(CMAKE_EXECUTABLE_SUFFIX ".elf")
##  set(CMAKE_${lang}_OUTPUT_EXTENSION ".o")
##  if (${lang} STREQUAL "C" OR ${lang} STREQUAL "CXX")
##    set(CMAKE_${lang}_COMPILE_OBJECT             "<CMAKE_${lang}_COMPILER> ${CMAKE_IAR_${lang}_FLAG} --silent <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT>")
##    set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "<CMAKE_${lang}_COMPILER> ${CMAKE_IAR_${lang}_FLAG} --silent <SOURCE> <DEFINES> <INCLUDES> <FLAGS> --preprocess=cnl <PREPROCESSED_SOURCE>")
##    set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE     "<CMAKE_${lang}_COMPILER> ${CMAKE_IAR_${lang}_FLAG} --silent <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -lAH <ASSEMBLY_SOURCE> -o <OBJECT>.dummy")
##
##    set(CMAKE_${lang}_RESPONSE_FILE_LINK_FLAG "-f ")
##    set(CMAKE_DEPFILE_FLAGS_${lang} "--dependencies=ns <DEP_FILE>")
##
##    string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
##    string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -r")
##    string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Ohz -DNDEBUG")
##    string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -Oh -DNDEBUG")
##    string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -Oh -r -DNDEBUG")
##  endif()
##
##  set(CMAKE_${lang}_LINK_EXECUTABLE "<CMAKE_LINKER> --silent <OBJECTS> <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS> <LINK_LIBRARIES> -o <TARGET>")
##  set(CMAKE_${lang}_CREATE_STATIC_LIBRARY "<CMAKE_AR> <TARGET> --create <LINK_FLAGS> <OBJECTS>")
##  set(CMAKE_${lang}_ARCHIVE_CREATE "<CMAKE_AR> <TARGET> --create <LINK_FLAGS> <OBJECTS>")
##  set(CMAKE_${lang}_ARCHIVE_APPEND "<CMAKE_AR> <TARGET> --replace <LINK_FLAGS> <OBJECTS>")
##  set(CMAKE_${lang}_ARCHIVE_FINISH "")
##endmacro()
##
##macro(__compiler_iar_xlink lang)
##  set(CMAKE_EXECUTABLE_SUFFIX ".bin")
##  if (${lang} STREQUAL "C" OR ${lang} STREQUAL "CXX")
##
##    set(CMAKE_${lang}_COMPILE_OBJECT             "<CMAKE_${lang}_COMPILER> ${CMAKE_IAR_${lang}_FLAG} --silent <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -o <OBJECT>")
##    set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "<CMAKE_${lang}_COMPILER> ${CMAKE_IAR_${lang}_FLAG} --silent <SOURCE> <DEFINES> <INCLUDES> <FLAGS> --preprocess=cnl <PREPROCESSED_SOURCE>")
##    set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE     "<CMAKE_${lang}_COMPILER> ${CMAKE_IAR_${lang}_FLAG} --silent <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -lAH <ASSEMBLY_SOURCE> -o <OBJECT>.dummy")
##
##    set(CMAKE_${lang}_RESPONSE_FILE_LINK_FLAG "-f ")
##    set(CMAKE_DEPFILE_FLAGS_${lang} "--dependencies=ns <DEP_FILE>")
##
##    string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
##    string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -r")
##    string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Ohz -DNDEBUG")
##    string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -Oh -DNDEBUG")
##    string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " -Oh -r -DNDEBUG")
##  endif()
##
##  set(CMAKE_${lang}_LINK_EXECUTABLE "<CMAKE_LINKER> -S <OBJECTS> <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS> <LINK_LIBRARIES> -o <TARGET>")
##  set(CMAKE_${lang}_CREATE_STATIC_LIBRARY "<CMAKE_AR> <TARGET> <LINK_FLAGS> <OBJECTS>")
##  set(CMAKE_${lang}_ARCHIVE_CREATE "<CMAKE_AR> <TARGET> <LINK_FLAGS> <OBJECTS>")
##  set(CMAKE_${lang}_ARCHIVE_APPEND "")
##  set(CMAKE_${lang}_ARCHIVE_FINISH "")
##
##  set(CMAKE_LIBRARY_PATH_FLAG "-I")
##endmacro()

include(Compiler/CMakeCommonCompilerMacros)

if(NOT DEFINED _RENESAS_NIGHTLY_TEST_MSG)
  set(_RENESAS_NIGHTLY_TEST_MSG 0)
endif()

if(CMAKE_C_COMPILER_ARCHITECTURE_ID STREQUAL "RX" OR CMAKE_CXX_COMPILER_ARCHITECTURE_ID STREQUAL "RX" )
  function(add_library_generate_options)
    set(opts_list ${ARGV})
    #list(JOIN opts_list " " opts_string) # DEBUG
    #message("DEBUG: add_library_generate_options: argv: ${opts_string}")

    # The `-lbgopt=` is not a native option of either Renesas Linker or Renesas Library Generator.
    # It is intended to be used for cmake wrapper scripts for Renesas build tools.
    list(JOIN opts_list "," opts_string)
    set(lopt -lbgopt=${opts_string})
    add_link_options(${lopt})
    #message("DEBUG: add_library_generate_options: lopt: ${lopt}")
  endfunction()

  function(target_library_generate_options)
    set(argv_list ${ARGV})
    #list(JOIN argv_list " " argv_string) # DEBUG
    #message("DEBUG: target_library_generate_options: argv: ${argv_string}")

    # The `-lbgopt=` is not a native option of either Renesas Linker or Renesas Library Generator.
    # It is intended to be used for cmake wrapper scripts for Renesas build tools.
    list(POP_FRONT argv_list args_list)
    foreach(arg ${argv_list})
      if(arg MATCHES "^BEFORE$")
        list(APPEND args_list ${arg})
      elseif(arg MATCHES "^(INTERFACE|PUBLIC|PRIVATE)$")
        if(opts_scope OR opts_list)
          list(JOIN opts_list "," opts_string)
          list(APPEND args_list ${opts_scope} -lbgopt=${opts_string})
        endif()
        set(opts_scope ${arg})
        set(opts_list)
      else()
        list(APPEND opts_list ${arg})
      endif()
    endforeach()
    if(opts_scope OR opts_list)
      list(JOIN opts_list "," opts_string)
      list(APPEND args_list ${opts_scope} -lbgopt=${opts_string})
    endif()
    target_link_options(${args_list})
    #list(JOIN args_list " " lopt) # DEBUG
    #message("DEBUG: target_library_generate_options: lopt: ${lopt}")
  endfunction()

  function(__init_library_generate_options)
    if(CMAKE_C_COMPILER_ARG1)
      set(lopt -compile_options_c_arg1=${CMAKE_C_COMPILER_ARG1})
      add_link_options(${lopt})
      #message("DEBUG: __init_library_generate_options: CMAKE_C_COMPILER_ARG1: ${lopt}")
    endif()

    if(CMAKE_C_FLAGS)
      separate_arguments(c_flags_list NATIVE_COMMAND "${CMAKE_C_FLAGS}")
      list(JOIN c_flags_list "," c_flags_string)
      set(lopt -compile_options_c_flags=${c_flags_string})
      add_link_options(${lopt})
      #message("DEBUG: __init_library_generate_options: CMAKE_C_FLAGS: ${lopt}")
    endif()

##    if(CMAKE_CXX_COMPILER_ARG1)
##      set(lopt -compile_options_cxx_arg1=${CMAKE_CXX_COMPILER_ARG1})
##      add_link_options(${lopt})
##      message("DEBUG: __init_library_generate_options: CMAKE_CXX_COMPILER_ARG1: ${lopt}")
##    endif()

##    if(CMAKE_CXX_FLAGS)
##      separate_arguments(cxx_flags_list NATIVE_COMMAND "${CMAKE_CXX_FLAGS}")
##      list(JOIN cxx_flags_list "," cxx_flags_string)
##      set(lopt -compile_options_cxx_flags=${cxx_flags_string})
##      add_link_options(${lopt})
##      message("DEBUG: __init_library_generate_options: CMAKE_CXX_FLAGS: ${lopt}")
##    endif()

    set(lopt -compile_options_c_std=-lang=c$<TARGET_PROPERTY:C_STANDARD>) # At this moment, this is just a generator expresiion.
    add_link_options(${lopt})
    #message("DEBUG: __init_library_generate_options: C_STANDARD: ${lopt}")

    set(lopt -compile_options=$<JOIN:$<TARGET_PROPERTY:COMPILE_OPTIONS>,$<COMMA>>) # At this moment, this is just a generator expresiion.
    add_link_options(${lopt})
    #message("DEBUG: __init_library_generate_options: COMPILE_OPTIONS: ${lopt}")

    set(lopt -link_language=$<LINK_LANGUAGE>) # At this moment, this is just a generator expresiion.
    add_link_options(${lopt})
    #message("DEBUG: __init_library_generate_options: LINK_LANGUAGE: ${lopt}")

    if(CMAKE_LBG_FLAGS)
      separate_arguments(lbg_flags_list NATIVE_COMMAND "${CMAKE_LBG_FLAGS}")
      list(JOIN lbg_flags_list "," lbg_flags_string)
      set(lopt -lbgopt=${lbg_flags_string})
      add_link_options(${lopt})
      #message("DEBUG: __init_library_generate_options: CMAKE_LBG_FLAGS: ${lopt}")
    endif()
  endfunction()

  function(__compiler_renesas_debug_disp_var var)
    if(NOT DEFINED ${var})
      message("DEBUG: ${var} = undefined")
    elseif(NOT ${var})
      message("DEBUG: ${var} = empty}")
    else()
      message("DEBUG: ${var} = ${${var}}")
    endif()
  endfunction()

  # The following code is necessary after re-configuration without compiler search.
  # In that case, Modules/Compiler/RENESAS-FindBinUtils.cmake is not used.
  #__compiler_renesas_debug_disp_var(CMAKE_C_FLAGS)
  #__compiler_renesas_debug_disp_var(CMAKE_CXX_FLAGS)
  if(CMAKE_C_COMPILER AND CMAKE_CXX_COMPILER)
    if((NOT CMAKE_CXX_FLAGS) AND CMAKE_C_FLAGS)
      set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS})
      string(REGEX REPLACE "^(|.* )-lang=[^ ]* *" "\\1" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
    endif()
    if((NOT CMAKE_C_FLAGS) AND CMAKE_CXX_FLAGS)
      set(CMAKE_C_FLAGS ${CMAKE_CXX_FLAGS})
      string(REGEX REPLACE "^(|.* )-lang=[^ ]* *" "\\1" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
      string(REGEX REPLACE "^(|.* )-rtti=[^ ]* *" "\\1" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
      string(REGEX REPLACE "^(|.* )-exception *"  "\\1" CMAKE_C_FLAGS ${CMAKE_C_FLAGS})
    endif()
  endif()
  #__compiler_renesas_debug_disp_var(CMAKE_C_FLAGS)
  #__compiler_renesas_debug_disp_var(CMAKE_CXX_FLAGS)

  __init_library_generate_options()
endif()

#message("DEBUG: RENESAS.cmake is included for the following language.")

macro(__compiler_renesas lang)
  #message("DEBUG: Language ${lang}")

  # Renesas CC-{RX, RL, RH} need the following setting.
  if(NOT DEFINED CMAKE_TRY_COMPILE_TARGET_TYPE)
    #message("DEBUG: set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)")
    set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
  endif()

  # CMake uses reponse file automatically when it is necessary. However,
  # it is also possible that CMake uses response files always.
  # To reduce `cases which have to be considered`, the following variables are set.
  # Perhaps there are little impact about a total build time. However, other than Ninja,
  # it is also possible that you can define your own setting in the toolchain file.
  # In the case of Ninja, states of the setting variable are defined/not defined, i.e. 
  # none of any pair of ON/OFF, TRUE/FALSE, 1/0, therefore always reponse file is used.
  # TODO: The following variables might be prepared for debugging, so that they should not be used?
  if(CMAKE_GENERATOR MATCHES "^Ninja")
    #message("DEBUG: set(CMAKE_NINJA_FORCE_RESPONSE_FILE ON)")
    set(CMAKE_NINJA_FORCE_RESPONSE_FILE ON)
  else()
    if(NOT DEFINED CMAKE_${lang}_USE_RESPONSE_FILE_FOR_INCLUDES)
      #message("DEBUG: set(CMAKE_${lang}_USE_RESPONSE_FILE_FOR_INCLUDES 1)")
      set(CMAKE_${lang}_USE_RESPONSE_FILE_FOR_INCLUDES 1)
    endif()
    if(NOT DEFINED CMAKE_${lang}_USE_RESPONSE_FILE_FOR_OBJECTS)
      #message("DEBUG: set(CMAKE_${lang}_USE_RESPONSE_FILE_FOR_OBJECTS 1)")
      set(CMAKE_${lang}_USE_RESPONSE_FILE_FOR_OBJECTS 1)
    endif()
    if(NOT DEFINED CMAKE_${lang}_USE_RESPONSE_FILE_FOR_LIBRARIES)
      #message("DEBUG: set(CMAKE_${lang}_USE_RESPONSE_FILE_FOR_LIBRARIES 1)")
      set(CMAKE_${lang}_USE_RESPONSE_FILE_FOR_LIBRARIES 1)
    endif()
  endif()

  # CMAKE_MODULE_PATH hooks for Renesas compiler/assembler/linker/etc wrapper scripts.
  # Somehow CMake's script mode checks a second name of existing file for a second `-P` even if it is after `--`.
  find_file(_RENESAS_COMPILER_WRAPPER   Compiler/RENESAS-CompilerWrapper.cmake     PATHS ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules REQUIRED NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
  find_file(_RENESAS_ASSEMBLER_WRAPPER  Compiler/RENESAS-AssemblerWrapper.cmake    PATHS ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules REQUIRED NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
  find_file(_RENESAS_LINKER_WRAPPER     Compiler/RENESAS-LinkerWrapper.cmake       PATHS ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules REQUIRED NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
  find_file(_RENESAS_LIBGEN_WRAPPER     Compiler/RENESAS-LibGeneratorWrapper.cmake PATHS ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules REQUIRED NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
  find_file(_RENESAS_XCONVERTER_WRAPPER Compiler/RENESAS-XConverterWrapper.cmake   PATHS ${CMAKE_MODULE_PATH} ${CMAKE_ROOT}/Modules REQUIRED NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
  set(_RENESAS_COMPILER_WRAPPER   "<CMAKE_COMMAND> -P \"${_RENESAS_COMPILER_WRAPPER}\" ")
  set(_RENESAS_ASSEMBLER_WRAPPER  "<CMAKE_COMMAND> -P \"${_RENESAS_ASSEMBLER_WRAPPER}\" ")
  set(_RENESAS_LINKER_WRAPPER     "<CMAKE_COMMAND> -P \"${_RENESAS_LINKER_WRAPPER}\" ")
  set(_RENESAS_LIBGEN_WRAPPER     "<CMAKE_COMMAND> -P \"${_RENESAS_LIBGEN_WRAPPER}\" ")
  set(_RENESAS_XCONVERTER_WRAPPER "<CMAKE_COMMAND> -P \"${_RENESAS_XCONVERTER_WRAPPER}\" ")
  get_filename_component(_RENESAS_${lang}_COMPILER_PATH ${CMAKE_${lang}_COMPILER}/../.. ABSOLUTE)
  if(CMAKE_RENESAS_XCONVERTER)
    get_filename_component(_RENESAS_E2STUDIO_SUPPORT_AREA ${CMAKE_RENESAS_XCONVERTER}/../../.. ABSOLUTE)
  endif()
  if(_RENESAS_E2STUDIO_SUPPORT_AREA)
    set(_RENESAS_E2STUDIO_SUPPORT_AREA \"${_RENESAS_E2STUDIO_SUPPORT_AREA}\")
  else()
    set(_RENESAS_E2STUDIO_SUPPORT_AREA -)
  endif()
  # When clangd finds `--` in options, it ignores all options after `--' because it is widely used behavior in Linux world.
  # https://discourse.llvm.org/t/clangd-cant-parse-source-correctly-when-just-option-is-included-in-command-field-of-compile-commands-json/69427/3
  # Unfortunately, all options including `-I` or `-D` or `@`, etc are after `--` and therefore also these options are ignored.
  # The following `-z --` is a workaround to prevent clangd from doing such behavior because clangd recognaize it as not `--' but `-z --`.
  # Fortunately, as of today, CMake ignores unrecognized option such as `-z`.
  string(APPEND _RENESAS_COMPILER_WRAPPER   "-z -- ${_RENESAS_NIGHTLY_TEST_MSG} \"${CMAKE_GENERATOR}\" ${_RENESAS_E2STUDIO_SUPPORT_AREA} ")
  string(APPEND _RENESAS_ASSEMBLER_WRAPPER  "-z -- ${_RENESAS_NIGHTLY_TEST_MSG} \"${CMAKE_GENERATOR}\" ${_RENESAS_E2STUDIO_SUPPORT_AREA} ")
  string(APPEND _RENESAS_LINKER_WRAPPER     "-- ${_RENESAS_NIGHTLY_TEST_MSG} \"${CMAKE_GENERATOR}\" ${_RENESAS_E2STUDIO_SUPPORT_AREA} ")
  string(APPEND _RENESAS_LIBGEN_WRAPPER     "-- ${_RENESAS_NIGHTLY_TEST_MSG} \"${CMAKE_GENERATOR}\" ${_RENESAS_E2STUDIO_SUPPORT_AREA} ")
  string(APPEND _RENESAS_XCONVERTER_WRAPPER "-- ${_RENESAS_NIGHTLY_TEST_MSG} \"${CMAKE_GENERATOR}\" ${_RENESAS_E2STUDIO_SUPPORT_AREA} ")

  set(CMAKE_${lang}_OUTPUT_EXTENSION ".obj")

  if(${lang} STREQUAL "C" OR ${lang} STREQUAL "CXX")

    # Note: <FLAGS> includes CMAKE_${lang}_FLAGS, CMAKE_${lang}_FLAGS_<config> and `language standard flags`.
    # When clangd is used along with CMake, be aware that it recognizes `-I` and `-D` but neither `-include=` nor `-define=`.
    # When clangd is used along with CMake, be aware that it recognizes `@` but not `-subcommand=`.
    # When clangd is used along with CMake, it is useful to tell clangd about `-std=` and `-isystem${_RENESAS_${lang}_COMPILER_PATH}/include or inc`.
    # But `-std=` and `-isystem` are not native flags but flags for wrapper script. (These flags are removed in the script.)
    if(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
      #set(CMAKE_${lang}_COMPILE_OPTIONS_TARGET "-isa=") # Not supported (at least as of today).
      set(CMAKE_INCLUDE_FLAG_${lang} "-I") # `-I` is not a native flag but a flag for wrapper script. (The flag is converted to `include=` in the script.)
      set(CMAKE_${lang}_DEFINE_FLAG "-D") # `-D` is not a native flag but a flag for wrapper script. (The flag is converted to `define=` in the script.)
      set(CMAKE_${lang}_RESPONSE_FILE_FLAG "@") # `@` is not a native flag but a flag for wrapper script.
      set(CMAKE_DEPFILE_FLAGS_${lang} "-MM -MT=<OBJECT> -MF=<DEP_FILE>") # `-MF=` is not a native flag but a flag for wrapper script.
      string(APPEND _RENESAS_COMPILER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_${lang}_COMPILER>")
      set(CMAKE_${lang}_COMPILE_OBJECT             "${_RENESAS_COMPILER_WRAPPER} <SOURCE> -output=obj=<OBJECT> -nologo <DEFINES> <INCLUDES> <FLAGS>")
      set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "${_RENESAS_COMPILER_WRAPPER} <SOURCE> -nologo <DEFINES> <INCLUDES> <FLAGS> -output=prep=<PREPROCESSED_SOURCE>")
      set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE     "${_RENESAS_COMPILER_WRAPPER} <SOURCE> -nologo <DEFINES> <INCLUDES> <FLAGS> -output=src=<ASSEMBLY_SOURCE>")

      if(${lang} STREQUAL "C")
        if(CMAKE_C_STANDARD)
          string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c${CMAKE_C_STANDARD} -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/include\"")
        else()
          string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c${CMAKE_C_STANDARD_COMPUTED_DEFAULT} -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/include\"")
        endif()
      else()
        # FIXME: CC-RX does not support any C++ standards.
        string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c++98 -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/include\"")
      endif()

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
      #set(CMAKE_${lang}_COMPILE_OPTIONS_TARGET "-cpu=") # Not supported (at least as of today).
      set(CMAKE_INCLUDE_FLAG_${lang} "-I") # This is the same as default setting.
      set(CMAKE_${lang}_DEFINE_FLAG "-D") # This is the same as default setting.
      set(CMAKE_${lang}_RESPONSE_FILE_FLAG "@") # `@` is not a native flag but a flag for wrapper script.
      set(CMAKE_DEPFILE_FLAGS_${lang} "-M -MT=<OBJECT> -MF=<DEP_FILE>") # `-MF=` is not a native flag but a flag for wrapper script.
      string(APPEND _RENESAS_COMPILER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_${lang}_COMPILER>")
      set(CMAKE_${lang}_COMPILE_OBJECT             "${_RENESAS_COMPILER_WRAPPER} <SOURCE> -c -o <OBJECT> <DEFINES> <INCLUDES> <FLAGS>")
      set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "${_RENESAS_COMPILER_WRAPPER} <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -P -o <PREPROCESSED_SOURCE>")
      set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE     "${_RENESAS_COMPILER_WRAPPER} <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -S -o <ASSEMBLY_SOURCE>")

      if(${lang} STREQUAL "C")
        if(CMAKE_C_STANDARD)
          string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c${CMAKE_C_STANDARD} -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/inc\"")
        else()
          string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c${CMAKE_C_STANDARD_COMPUTED_DEFAULT} -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/inc\"")
        endif()
      endif()

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
      #set(CMAKE_${lang}_COMPILE_OPTIONS_TARGET "-Xcpu=") # Not supported (at least as of today).
      set(CMAKE_INCLUDE_FLAG_${lang} "-I") # This is the same as default setting.
      set(CMAKE_${lang}_DEFINE_FLAG "-D") # This is the same as default setting.
      set(CMAKE_${lang}_RESPONSE_FILE_FLAG "@") # This is the same as default setting.
      set(CMAKE_DEPFILE_FLAGS_${lang} "-M -MT=<OBJECT> -MF=<DEP_FILE>") # `-MF=` is not a native flag but a flag for wrapper script.
      string(APPEND _RENESAS_COMPILER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_${lang}_COMPILER>")
      set(CMAKE_${lang}_COMPILE_OBJECT             "${_RENESAS_COMPILER_WRAPPER} <SOURCE> -o<OBJECT> -c <DEFINES> <INCLUDES> <FLAGS>")
      set(CMAKE_${lang}_CREATE_PREPROCESSED_SOURCE "${_RENESAS_COMPILER_WRAPPER} <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -P -o<PREPROCESSED_SOURCE>")
      set(CMAKE_${lang}_CREATE_ASSEMBLY_SOURCE     "${_RENESAS_COMPILER_WRAPPER} <SOURCE> <DEFINES> <INCLUDES> <FLAGS> -S -o<ASSEMBLY_SOURCE>")

      if(${lang} STREQUAL "C")
        if(CMAKE_C_STANDARD)
          string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c${CMAKE_C_STANDARD} -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/inc\"")
        else()
          string(APPEND CMAKE_${lang}_COMPILE_OBJECT " -std=c${CMAKE_C_STANDARD_COMPUTED_DEFAULT} -isystem\"${_RENESAS_${lang}_COMPILER_PATH}/inc\"")
        endif()
      endif()

    endif()

    # Note: Some compilers use different optimization level between RELEASE and RELWITHDEBINFO as follows.
    #                   ARMCC           GNU             PGI          SunPro           Windows-Clang  and more.
    # DEBUG             default(-O0)    default(-O0)    -O0          default(-xO0)    -O0
    # MINSIZEREL        -Ospace         -Os             -O2 -s       -xO2 -xspace     -Os
    # RELEASE           -Otime          -O3             -O3 -fast    -xO3             -O3
    # RELWITHDEBINFO    -O2             -O2             -O2          -xO2             -O2
    # Therefore the following flags are used for Renesas CC-{RX, RL, RH}.
    #                   CC-RX                                    CC-{RL, RH}
    # DEBUG             -optimize=0                              -Onothing
    # MINSIZEREL        -optimize=max -size (default)            -Osize
    # RELEASE           -optimize=max -speed                     -Ospeed
    # RELWITHDEBINFO    -optimize=2 (default) -size (default)    -Odefault (default)
    if(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
      set(_RENESAS_DEBUG_G_GL_GDB "-debug")
      if(CMAKE_${lang}_COMPILER_VERSION VERSION_GREATER_EQUAL 3.2)
        string(APPEND _RENESAS_DEBUG_G_GL_GDB " -g_line")
      endif()
      string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
      string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -optimize=0 ${_RENESAS_DEBUG_G_GL_GDB}")
      string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -optimize=max -define=NDEBUG")
      string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -optimize=max -speed -define=NDEBUG")
      string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " ${_RENESAS_DEBUG_G_GL_GDB} -define=NDEBUG")

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
      set(_RENESAS_DEBUG_G_GL_GDB "-g")
      if(CMAKE_${lang}_COMPILER_VERSION VERSION_GREATER_EQUAL 1.2)
        string(APPEND _RENESAS_DEBUG_G_GL_GDB " -g_line")
      endif()
      string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
      string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -Onothing ${_RENESAS_DEBUG_G_GL_GDB}")
      string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Osize -DNDEBUG")
      string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -Ospeed -DNDEBUG")
      string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " ${_RENESAS_DEBUG_G_GL_GDB} -DNDEBUG")

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
      set(_RENESAS_DEBUG_G_GL_GDB "-g")
      if(CMAKE_${lang}_COMPILER_VERSION VERSION_GREATER_EQUAL 1.5)
        string(APPEND _RENESAS_DEBUG_G_GL_GDB " -g_line")
      endif()
      if(CMAKE_${lang}_COMPILER_VERSION VERSION_GREATER_EQUAL 2.4)
        if(CMAKE_RENESAS_XCONVERTER)
          string(APPEND _RENESAS_DEBUG_G_GL_GDB " -gdb_compatible")
        endif()
      endif()
      string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
      string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " -Onothing ${_RENESAS_DEBUG_G_GL_GDB}")
      string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -Osize -DNDEBUG")
      string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -Ospeed -DNDEBUG")
      string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " ${_RENESAS_DEBUG_G_GL_GDB} -DNDEBUG")

    endif()
    unset(_RENESAS_DEBUG_G_GL_GDB)

  else() # ASM${ASM_DIALECT}

    # Note: <FLAGS> includes CMAKE_${lang}_FLAGS, CMAKE_${lang}_FLAGS_<config>
    if(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
      #set(CMAKE_${lang}_COMPILE_OPTIONS_TARGET "-isa=") # Not supported (at least as of today).
      set(CMAKE_INCLUDE_FLAG_${lang} "-include=")
      set(CMAKE_${lang}_DEFINE_FLAG "-define=")
      set(CMAKE_${lang}_RESPONSE_FILE_FLAG "-subcommand=")
      set(CMAKE_DEPFILE_FLAGS_${lang} "-MM -MT=<OBJECT> -MF=<DEP_FILE>")
      string(APPEND _RENESAS_ASSEMBLER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_${lang}_COMPILER>")
      set(CMAKE_${lang}_COMPILE_OBJECT "${_RENESAS_ASSEMBLER_WRAPPER} <SOURCE> -output=<OBJECT> -nologo <DEFINES> <INCLUDES> <FLAGS>")
      set(CMAKE_${lang}_SOURCE_FILE_EXTENSIONS src asm s)

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
      #set(CMAKE_${lang}_COMPILE_OPTIONS_TARGET "-cpu=") # Not supported (at least as of today).
      set(CMAKE_INCLUDE_FLAG_${lang} "-include=")
      set(CMAKE_${lang}_DEFINE_FLAG "-define=")
      set(CMAKE_${lang}_RESPONSE_FILE_FLAG "@")
      set(CMAKE_DEPFILE_FLAGS_${lang} "-MM -MT=<OBJECT> -MF=<DEP_FILE>")
      string(APPEND _RENESAS_ASSEMBLER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_${lang}_COMPILER>")
      set(CMAKE_${lang}_COMPILE_OBJECT "${_RENESAS_ASSEMBLER_WRAPPER} <SOURCE> -output=<OBJECT> <DEFINES> <INCLUDES> <FLAGS>")
      set(CMAKE_${lang}_SOURCE_FILE_EXTENSIONS asm s)

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
      #set(CMAKE_${lang}_COMPILE_OPTIONS_TARGET "-Xcpu=") # Not supported (at least as of today).
      set(CMAKE_INCLUDE_FLAG_${lang} "-I") # This is the same as default setting.
      set(CMAKE_${lang}_DEFINE_FLAG "-D") # This is the same as default setting.
      set(CMAKE_${lang}_RESPONSE_FILE_FLAG "@")
      set(CMAKE_DEPFILE_FLAGS_${lang} "-MM -MT=<OBJECT> -MF=<DEP_FILE>")
      string(APPEND _RENESAS_ASSEMBLER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_${lang}_COMPILER>")
      set(CMAKE_${lang}_COMPILE_OBJECT "${_RENESAS_ASSEMBLER_WRAPPER} <SOURCE> -o<OBJECT> <DEFINES> <INCLUDES> <FLAGS>")
      set(CMAKE_${lang}_SOURCE_FILE_EXTENSIONS asm s)

    endif()

    if(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
      set(_RENESAS_DEBUG_G_GL_GDB "-debug")
      string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
      string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " ${_RENESAS_DEBUG_G_GL_GDB}")
      string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -define=NDEBUG=1")
      string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -define=NDEBUG=1")
      string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " ${_RENESAS_DEBUG_G_GL_GDB} -define=NDEBUG=1")

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RL78")
      set(_RENESAS_DEBUG_G_GL_GDB "-debug")
      string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
      string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " ${_RENESAS_DEBUG_G_GL_GDB}")
      string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -define=NDEBUG=1")
      string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -define=NDEBUG=1")
      string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " ${_RENESAS_DEBUG_G_GL_GDB} -define=NDEBUG=1")

    elseif(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RH850")
      set(_RENESAS_DEBUG_G_GL_GDB "-g")
      string(APPEND CMAKE_${lang}_FLAGS_INIT " ")
      string(APPEND CMAKE_${lang}_FLAGS_DEBUG_INIT " ${_RENESAS_DEBUG_G_GL_GDB}")
      string(APPEND CMAKE_${lang}_FLAGS_MINSIZEREL_INIT " -DNDEBUG=1")
      string(APPEND CMAKE_${lang}_FLAGS_RELEASE_INIT " -DNDEBUG=1")
      string(APPEND CMAKE_${lang}_FLAGS_RELWITHDEBINFO_INIT " ${_RENESAS_DEBUG_G_GL_GDB} -DNDEBUG=1")

    endif()
    unset(_RENESAS_DEBUG_G_GL_GDB)

  endif()

  if(CMAKE_RENESAS_XCONVERTER)
    # This is alternative suffix used for debgging with e2 studio and {rx, rl78, V850?}-elf-gdb.
    set(CMAKE_EXECUTABLE_SUFFIX ".x")
  else()
    # This is native suffix used by Renesas CC-{RX, RL, RH} compilers and for debugging with CS+.
    set(CMAKE_EXECUTABLE_SUFFIX ".abs")
  endif()

  set(CMAKE_STATIC_LIBRARY_PREFIX "")
  set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")
  
  set(CMAKE_FIND_LIBRARY_PREFIXES "")
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")

  # This might be done in Modules/Platform/Generic.cmake in the case that `set(CMAKE_SYSTEM_NAME Generic)` was done.
  # The following setting here is for the case that it might not be done.
  set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS FALSE)
  
  #message("CMAKE_LIBRARY_PATH_FLAG       = ${CMAKE_LIBRARY_PATH_FLAG}") # This is defined elsewhere.
  #message("CMAKE_LIBRARY_PATH_TERMINATOR = ${CMAKE_LIBRARY_PATH_TERMINATOR}")
  #message("CMAKE_LINK_OBJECT_FILE_FLAG   = ${CMAKE_LINK_OBJECT_FILE_FLAG}")
  #message("CMAKE_LINK_LIBRARY_FLAG       = ${CMAKE_LINK_LIBRARY_FLAG}") # This is defined elsewhere.
  #message("CMAKE_LINK_LIBRARY_FILE_FLAG  = ${CMAKE_LINK_LIBRARY_FILE_FLAG}")
  set(CMAKE_LIBRARY_PATH_FLAG "") # Renesas CC-{RX, RL, RH} do not support this kind of flag.
  set(CMAKE_LIBRARY_PATH_TERMINATOR "") # Digital Mars D compiler needs this variable.
  set(CMAKE_LINK_OBJECT_FILE_FLAG "") # Openwatcom compiler needs this variable.
  set(CMAKE_LINK_LIBRARY_FLAG "-library=") # This variable may not be used because the following variable is defined.
  set(CMAKE_LINK_LIBRARY_FILE_FLAG "-library=") # Openwatcom compiler and Renesas CC-{RX, RL, RH} need this variable.
  set(CMAKE_LINK_LIBRARY_SUFFIX ".lib") # This variable seems to belong to this group.

  set(CMAKE_${lang}_LINKER_WRAPPER_FLAG " ") # No compiler driver is used for Renesas linker of CC-{RX, RL, RH}.
  set(CMAKE_${lang}_LINKER_WRAPPER_FLAG_SEP "") # No compiler driver is used for Renesas linker of  CC-{RX, RL, RH}.
  set(CMAKE_${lang}_LINK_WITH_STANDARD_COMPILE_OPTION 0) # Only SunPro compiler needs this variable.

  # This flag is not a Renesas linker's native flag. This is for Renesas linker wrapper script.
  set(CMAKE_${lang}_RESPONSE_FILE_LINK_FLAG "-subcommand_rsp=")

  # Renesas linker uses CMAKE_${lang}_CREATE_STATIC_LIBRARY variable in stead of the following.
  set(CMAKE_${lang}_ARCHIVE_CREATE "")
  set(CMAKE_${lang}_ARCHIVE_APPEND "")
  set(CMAKE_${lang}_ARCHIVE_FINISH "")

  # Note: <LINK_FLAGS> includes CMAKE_EXE_LINKER_FLAGS and CMAKE_EXE_LINKER_FLAGS_<config>.
  string(APPEND _RENESAS_LINKER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} <CMAKE_LINKER>")
  # CMAKE_RENESAS_LIBRARY_GENERATOR may have space(s) in the path, so that it needs to be quoted for Ninja.
  string(APPEND _RENESAS_LIBGEN_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} \"${CMAKE_RENESAS_LIBRARY_GENERATOR}\"")
  # CMAKE_RENESAS_XCONVERTER may have space(s) in the path, so that it needs to be quoted for Ninja.
  string(APPEND _RENESAS_XCONVERTER_WRAPPER "${CMAKE_${lang}_COMPILER_ARCHITECTURE_ID} ${CMAKE_${lang}_COMPILER_VERSION} \"${CMAKE_RENESAS_XCONVERTER}\"")

  set(CMAKE_${lang}_CREATE_STATIC_LIBRARY
    "${_RENESAS_LINKER_WRAPPER} -nologo <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -form=lib -output=<TARGET>"
  )

  if(CMAKE_${lang}_COMPILER_ARCHITECTURE_ID STREQUAL "RX")
    # <TARGET_NAME> is used instead of <TARGET_BASE> for Ninja because Ninja's <TARGET_BASE> is the same as <TARGET>. # FIXME: Is it OK?
    # `-output_lbg=` is not a Renesas library generator's native flag. This is for Renesas library generator wrapper script.
    # `-form_exe=` and `-output_exe=` are not Renesas linker's native flags. These are for Renesas linker wrapper script.
    set(CMAKE_${lang}_LINK_EXECUTABLE
      "${_RENESAS_LIBGEN_WRAPPER} -nologo <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS> -output_lbg=<TARGET_NAME>.lib"
      "${_RENESAS_LINKER_WRAPPER} -nologo <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -library=<TARGET_NAME>.lib -form_exe=abs -output_exe=<TARGET_NAME>.abs"
    )

  else() # RL78 or RH850
    # <TARGET_NAME> is used instead of <TARGET_BASE> for Ninja because Ninja's <TARGET_BASE> is the same as <TARGET>. # FIXME: Is it OK?
    # `-form_exe=` and `-output_exe=` are not Renesas linker's native flags. These are for Renesas linker wrapper script.
    set(CMAKE_${lang}_LINK_EXECUTABLE
      "${_RENESAS_LINKER_WRAPPER} -nologo <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> <LINK_LIBRARIES> -form_exe=abs -output_exe=<TARGET_NAME>.abs"
    )

  endif()

  if(CMAKE_RENESAS_XCONVERTER)
    # <TARGET_NAME> is used instead of <TARGET_BASE> for Ninja because Ninja's <TARGET_BASE> is the same as <TARGET>. # FIXME: Is it OK?
    list(APPEND CMAKE_${lang}_LINK_EXECUTABLE
      "${_RENESAS_XCONVERTER_WRAPPER} <TARGET_NAME>.abs <TARGET> <CMAKE_${lang}_LINK_FLAGS> <LINK_FLAGS>"
    )
  endif()

  # The debug information can be controlled by equivalent flags of compiler or assembler.
  # Moreover debug capability is sometimes desired even if MINSIZEREL or RELEASE is selected.
  # (Please be aware that optimazation flags are different between RELEASE and RELWITHDEBINFO.)
  # DO NOT USE `-nodebug` flag of linker so that debug capability can be provided in such case
  # by adding debug information flag(s) such as `-debug` or `-g` of compiler or assembler 
  # in user's toolchain file(s) or user's CMakeLists.txt file(s).
  #string(APPEND CMAKE_EXE_LINKER_FLAGS_INIT " ")
  #string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT " ") # -debug (default)
  #string(APPEND CMAKE_EXE_LINKER_FLAGS_MINSIZEREL_INIT " ") # DO NOT USE -nodebug
  #string(APPEND CMAKE_EXE_LINKER_FLAGS_RELEASE_INIT " ") # DO NOT USE -nodebug
  #string(APPEND CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO_INIT " ") # -debug (default)

  unset(_RENESAS_COMPILER_WRAPPER)
  unset(_RENESAS_ASSEMBLER_WRAPPER)
  unset(_RENESAS_LINKER_WRAPPER)
  unset(_RENESAS_LIBGEN_WRAPPER)
  unset(_RENESAS_XCONVERTER_WRAPPER)
  unset(_RENESAS_E2STUDIO_SUPPORT_AREA)
  unset(_RENESAS_${lang}_COMPILER_PATH)

endmacro()
