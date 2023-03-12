cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR) # 3.26.0-rc2 or later

if(CMAKE_TOOLCHAIN_FILE MATCHES ".*(ex2xx|ex4xx|ex6xx)\\.cmake" AND NOT EXAMPLE_CXX_PROJ_TYPE)
    # The following setting is to test the language definition order issue in project() (or enable_language()).
    set(EXAMPLE_CXX_PROJ_TYPE 1) # 1: The order is `CXX C`. or 2: The order is `C CXX`.
endif()

if(CMAKE_TOOLCHAIN_FILE MATCHES ".*/cross\\.cmake$")

    # The following setting can be set to 1 or 2 for CXX project example.
    #set(EXAMPLE_CXX_PROJ_TYPE 1) # Not defined: Not CXX project. or 1: The order is `CXX C`. or 2: The order is `C CXX`.

endif()

if(NOT EXAMPLE_CXX_PROJ_TYPE)

    project(tb_rx65n C ASM)
    set(CPPAPP_DEF 0)

elseif(EXAMPLE_CXX_PROJ_TYPE EQUAL 1)

    project(tb_rx65n CXX C ASM)
    set(CPPAPP_DEF 1)

elseif(EXAMPLE_CXX_PROJ_TYPE EQUAL 2)

    project(tb_rx65n C CXX ASM)
    set(CPPAPP_DEF 1)

endif()

set(GSG_BASE_DIR ${CMAKE_SOURCE_DIR})

if(NOT DEFINED DEBUG_RSP_FILE)
    set(DEBUG_RSP_FILE FALSE) # TRUE or FALSE
endif()
include(${GSG_BASE_DIR}/dbg_rspf_src/CMakeLists_DEBUG_RSP_FILE.txt)

if(COMMAND SET_DIRECTORY_OPTIONS)
    SET_DIRECTORY_OPTIONS()
endif()

add_executable(${PROJECT_NAME}
    ${DBG_RSPF_MAIN_SRC_C}

    ${GSG_BASE_DIR}/src/smc_gen/general/r_cg_hardware_setup.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_smc_cgc.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_smc_cgc_user.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_smc_interrupt.c

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/board/generic_rx65n/hwsetup.c

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/dbsct.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/lowlvl.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/lowsrc.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/mcu_locks.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_common.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_cpu.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_interrupts.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_locking.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_mcu_startup.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_software_interrupt.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_rx_intrinsic_functions.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/resetprg.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/sbrk.c

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/rx65n/mcu_clocks.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/rx65n/mcu_init.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/rx65n/mcu_interrupts.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/rx65n/mcu_mapped_interrupts.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/rx65n/vecttbl.c

    ${GSG_BASE_DIR}/src/smc_gen/r_pincfg/Pin.c

    ${GSG_BASE_DIR}/src/tb_rx65n.c
    ${GSG_BASE_DIR}/src/sample_asm.src
    ${GSG_BASE_DIR}/src/sample_cpp.cpp # This file is activated in only CXX project.
    ${GSG_BASE_DIR}/src/test_dep_scan_etc_c.c
    ${GSG_BASE_DIR}/src/test_dep_scan_etc_asm.src
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${DBG_RSPF_MAIN_INC_C}

    ${GSG_BASE_DIR}/src/smc_gen/general
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp
    ${GSG_BASE_DIR}/src/smc_gen/r_config
    ${GSG_BASE_DIR}/src/smc_gen/r_pincfg
    ${GSG_BASE_DIR}/src
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    TB_RX65N=1
    DEF_WITHOUT_VAL
    DEF_NOT_NUMBER=ABCXYZ
    CPPAPP=${CPPAPP_DEF}
)

add_library(sample_lib1 ${DBG_RSPF_LIB1_SRC_C} lib_src/lib1/sample_lib1a_c.c lib_src/lib1/sample_lib1b_c.c)
add_library(sample_lib2 ${DBG_RSPF_LIB2_SRC_C} lib_src/lib2/sample_lib2a_c.c lib_src/lib2/sample_lib2b_c.c)
add_library(sample_lib3 ${DBG_RSPF_LIB3_SRC_C} lib_src/lib3/sample_lib3a_c.c lib_src/lib3/sample_lib3b_c.c)

target_include_directories(sample_lib1
    PRIVATE
    ${DBG_RSPF_LIB1_INC_C}
    PUBLIC
    ${GSG_BASE_DIR}/lib_src/lib1/inc
)
target_include_directories(sample_lib2
    PRIVATE
    ${DBG_RSPF_LIB2_INC_C}
    PUBLIC
    ${GSG_BASE_DIR}/lib_src/lib2/inc
)
target_include_directories(sample_lib3
    PRIVATE
    ${DBG_RSPF_LIB3_INC_C}
    PUBLIC
    ${GSG_BASE_DIR}/lib_src/lib3/inc
)

target_link_libraries(${PROJECT_NAME} sample_lib1 sample_lib2 sample_lib3)

if(COMMAND SET_TARGET_OPTIONS)
    SET_TARGET_OPTIONS()
endif()
