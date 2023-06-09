# Ninja or Unix Make can be used.
if(NOT EXAMPLE_CXX_PROJ_TYPE)

##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex1.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex2.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex3.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex4.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex5.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex6.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex11.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex12.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex13.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex14.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex15.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex16.cmake)

elseif((EXAMPLE_CXX_PROJ_TYPE EQUAL 1) OR (EXAMPLE_CXX_PROJ_TYPE EQUAL 2))

##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex2xx.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex4xx.cmake)
##include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex6xx.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex12xx.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex14xx.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rl78-ccrl-toolchain-ex16xx.cmake)

endif()
