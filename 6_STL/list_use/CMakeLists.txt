cmake_minimum_required(VERSION 3.31)
project(list_use)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

#include_directories和target_include_directories都可以链接头文件，前者为全局作用域，后者为指定的作用域
#include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(1_list 1_list.cpp)
add_executable(2_insert_delete 2_insert_delete.cpp)
target_include_directories(1_list PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(2_insert_delete PUBLIC ${CMAKE_SOURCE_DIR}/include)
