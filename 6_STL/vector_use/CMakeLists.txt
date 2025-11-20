cmake_minimum_required(VERSION 3.10)
project(VECTOR_USE)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
set(INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

# 将头文件目录添加到所有目标的包含路径
include_directories(${INCLUDE_DIR})
add_executable(1_learn_STL 1_learn_STL.cpp)
add_executable(2_self_class_vector 2_self_class_vector.cpp)
add_executable(3_nest_stl 3_nest_stl.cpp)
add_executable(4_vector_constro 4_vector_constro.cpp)
add_executable(5_insert_del 5_insert_del.cpp)
add_executable(6_swap 6_swap.cpp)

target_link_directories(4_vector_constro PRIVATE ${INCLUDE_DIR})
target_link_directories(5_insert_del PRIVATE ${INCLUDE_DIR})
