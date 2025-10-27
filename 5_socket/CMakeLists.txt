cmake_minimum_required(VERSION 3.10)

project(Mysocket)

set(CMAKE_CXX_STANDARD 11)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()


add_executable(server server.cpp)
add_executable(client client.cpp)

