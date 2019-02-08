cmake_minimum_required(VERSION 3.0.0)
project(LeetCode VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
add_executable(001_two_sum 001_two_sum.cc)
add_executable(002_add_two_numbers 002_add_two_numbers.cc)
add_executable(003_length_of_longest_substring 003_length_of_longest_substring.cc)
add_executable(167_two_sum_II 167_two_sum_II.cc)
add_executable(004_median_of_sorted_arrays 004_median_of_sorted_arrays.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
