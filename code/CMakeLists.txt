cmake_minimum_required(VERSION 3.17)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp sets.h grid.cpp grid.h lagrange_Interpolation.cpp lagrange_Interpolation.h matrix_operations.cpp matrix_operations.h norm.cpp norm.h output.cpp output.h spline_Interpolation.cpp spline_Interpolation.h test_functions.cpp test_functions.h)