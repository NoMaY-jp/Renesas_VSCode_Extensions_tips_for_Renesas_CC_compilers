cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR) # 3.26.0-rc2 or later

project(RH850F1KM_SampleProject C ASM)

if(NOT DEFINED DEBUG_RSP_FILE)
    set(DEBUG_RSP_FILE FALSE) # TRUE or FALSE
endif()
set(GSG_BASE_DIR ${CMAKE_SOURCE_DIR})
include(${GSG_BASE_DIR}/dbg_rspf_src/CMakeLists_DEBUG_RSP_FILE.txt)

if(COMMAND SET_DIRECTORY_OPTIONS)
    SET_DIRECTORY_OPTIONS()
endif()

add_executable(${PROJECT_NAME}
    ${DBG_RSPF_MAIN_SRC_C}

    sample_src/sc_cstart.asm
    sample_src/sc_boot.asm
    sample_src/sc_intprg.c

    src/smc_gen/general/r_cg_cgc_user.c
    src/smc_gen/general/r_cg_cgc.c
    src/smc_gen/general/r_cg_intvector.c
    src/smc_gen/general/r_cg_main.c
    src/smc_gen/general/r_cg_systeminit.c
    src/smc_gen/general/r_smc_interrupt.c

    src/smc_gen/r_pincfg/Pin.c

    src/test_dep_scan_etc_c.c
    src/test_dep_scan_etc_asm.asm
    src/language_extensions_and_standard.c
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${DBG_RSPF_MAIN_INC_C}

    src/smc_gen/general
    src/smc_gen/r_pincfg
    ${GSG_BASE_DIR}
    src

    src/test_dep_scan_etc_inc_2
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE
    RH850_F1KM_TRGT=1
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
    lib_src/lib1/inc
)
target_include_directories(sample_lib2
    PRIVATE
    ${DBG_RSPF_LIB2_INC_C}
    PUBLIC
    lib_src/lib2/inc
)
target_include_directories(sample_lib3
    PRIVATE
    ${DBG_RSPF_LIB3_INC_C}
    PUBLIC
    lib_src/lib3/inc
)

target_link_libraries(${PROJECT_NAME} sample_lib1 sample_lib2 sample_lib3)

if(COMMAND SET_TARGET_OPTIONS)
    SET_TARGET_OPTIONS()
endif()
