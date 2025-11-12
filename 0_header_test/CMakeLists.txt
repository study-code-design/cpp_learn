cmake_minimum_required(VERSION 3.11)
project(header_test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# 如果 OpenCV 在非标准路径，你也可以在 cmake 命令行传 -DOpenCV_DIR=...
set(OpenCV_DIR /home/tu/cpp_learn/opencv/build)
find_package(OpenCV REQUIRED)

set(SRC
    src/test1.cpp
    src/test2.cpp
)

add_library(${PROJECT_NAME} SHARED ${SRC})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${OpenCV_LIBS}
)

#设置动态库输出路径
set(LiBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

