# Ninja or Unix Make can be used.
if(NOT EXAMPLE_CXX_PROJ_TYPE)

#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex1.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex2.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex3.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex4cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex5.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex6.cmake)

elseif((EXAMPLE_CXX_PROJ_TYPE EQUAL 1) OR (EXAMPLE_CXX_PROJ_TYPE EQUAL 2))

#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex2xx.cmake)
#include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex4xx.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/cmake/renesas-rx-ccrx-toolchain-ex6xx.cmake)

endif()
