cmake_minimum_required(VERSION 3.0.0)
project(CommonAlgorithm VERSION 0.1.0)

# include(CTest)
# enable_testing()
set(SRC_DIRECTORY ${PROJECT_SOURCE_DIR}/sort)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(quicksort ${SRC_DIRECTORY}/quicksort.c)
add_executable(mergesort ${SRC_DIRECTORY}/mergesort.c)
add_executable(radixsort ${SRC_DIRECTORY}/radixsort.c)
add_executable(bubblesort ${SRC_DIRECTORY}/bubblesort.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
