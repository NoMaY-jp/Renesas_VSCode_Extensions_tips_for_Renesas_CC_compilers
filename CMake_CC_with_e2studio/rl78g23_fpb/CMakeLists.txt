cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR) # 3.26.0-rc2 or later

project(rl78g23_fpb C ASM)

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

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/cstart.asm

    ${GSG_BASE_DIR}/src/smc_gen/Config_INTC/Config_INTC.c
    ${GSG_BASE_DIR}/src/smc_gen/Config_INTC/Config_INTC_user.c

    ${GSG_BASE_DIR}/src/smc_gen/Config_ITL0/Config_ITL0.c
    ${GSG_BASE_DIR}/src/smc_gen/Config_ITL0/Config_ITL0_user.c

    ${GSG_BASE_DIR}/src/smc_gen/Config_PORT/Config_PORT.c
    ${GSG_BASE_DIR}/src/smc_gen/Config_PORT/Config_PORT_user.c

    ${GSG_BASE_DIR}/src/smc_gen/general/r_cg_itl_common.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_cg_itl_common_user.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_cg_lvd_common.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_cg_lvd_common_user.c
    ${GSG_BASE_DIR}/src/smc_gen/general/r_cg_systeminit.c

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/board/generic_rl78_g23/hdwinit.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/board/generic_rl78_g23/r_bsp_init.c
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/board/generic_rl78_g23/stkinit.asm

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/all/r_bsp_common.c

    ${GSG_BASE_DIR}/src/smc_gen/r_bsp/mcu/rl78_g23/mcu_clocks.c

    ${GSG_BASE_DIR}/src/rl78g23_fpb_main.c
    ${GSG_BASE_DIR}/src/test_dep_scan_etc_c.c
    ${GSG_BASE_DIR}/src/test_dep_scan_etc_asm.asm
    ${GSG_BASE_DIR}/src/language_extensions_and_standard.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${DBG_RSPF_MAIN_INC_C}

    ${GSG_BASE_DIR}/src/smc_gen/Config_INTC
    ${GSG_BASE_DIR}/src/smc_gen/Config_ITL0
    ${GSG_BASE_DIR}/src/smc_gen/Config_PORT
    ${GSG_BASE_DIR}/src/smc_gen/general
    ${GSG_BASE_DIR}/src/smc_gen/r_bsp
    ${GSG_BASE_DIR}/src/smc_gen/r_config
    ${GSG_BASE_DIR}/src

    ${GSG_BASE_DIR}/src/test_dep_scan_etc_inc_2
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    RL78_G23_FPB=1
    DEF_WITHOUT_VAL
    DEF_NOT_NUMBER=ABCXYZ
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
