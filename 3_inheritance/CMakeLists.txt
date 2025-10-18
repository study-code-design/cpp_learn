cmake_minimum_required(VERSION 3.10)

project(MyProject2)

set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(1_inherit_test 1_inherit_test.cpp)
add_executable(2_polymorphism 2_polymorphism.cpp)
