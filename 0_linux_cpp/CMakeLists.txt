cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
# include_directories($(CMAKE_SOURCE_DIR)/include)

add_executable(1_time 1_time.cpp)
add_executable(2_dir 2_dir.cpp)
add_executable(3_signal 3_signal.cpp)
add_executable(4_process 4_process.cpp)
add_executable(test_ros test_ros.cpp)
