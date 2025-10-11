cmake_minimum_required(VERSION 3.10)

project(quote)

set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(inn_area inn_area.cpp)
add_executable(new_memory new_memory.cpp)
add_executable(3_quote 3_quote.cpp)
add_executable(4_quote_return 4_quote_return.cpp)
add_executable(5_const_quote 5_const_quote.cpp)
add_executable(6_reload_func 6_reload_func.cpp)
add_executable(7_student_class 7_student_class.cpp)
add_executable(8_cube_example 8_cube_example.cpp)
add_executable(9_circles_point 9_circles_point.cpp
                                         src/point.cpp
                                         src/circles.cpp)

            


