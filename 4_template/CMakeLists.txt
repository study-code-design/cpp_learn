cmake_minimum_required(VERSION 3.10)

project(MyProject3)

set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
# include_directories()

project(MyProject3)

set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
# include_directories()

add_executable(1_template 1_template.cpp)
add_executable(2_template_limitation 2_template_limitation.cpp)
add_executable(3_class_template 3_class_template.cpp)
add_executable(4_timing_template 4_timing_template.cpp)
