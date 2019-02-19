cmake_minimum_required(VERSION 3.0.0)
project(LeetCode VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(problems
    001_two_sum
    002_add_two_numbers
    003_length_of_longest_substring
    004_median_of_sorted_arrays
    005_longest_palindromic_substring
    167_two_sum_II
)
foreach(pro ${problems})
  add_executable(${pro} ${pro}.cc)
endforeach()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
