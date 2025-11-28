cmake_minimum_required(VERSION 3.10)
project(MyOpenCVProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# 查找 OpenCV 和 Eigen3
find_package(OpenCV REQUIRED)
# 要求至少 3.3，使用 NO_MODULE 更倾向于使用 config package（系统上有时需要）
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

find_package(matplotlib_cpp REQUIRED)

message(STATUS "Found OpenCV version: ${OpenCV_VERSION}")
message(STATUS "Eigen3 include dirs: ${EIGEN3_INCLUDE_DIRS}")

# 添加可执行文件
add_executable(1_show_image 1_show_image.cpp)
add_executable(2_show_video 2_show_video.cpp)

# 推荐把 include 路径/依赖绑定到 target 上（modern CMake）
# OpenCV 的 find_package 通常会提供 OpenCV_LIBS 或者 OpenCV::... targets
target_include_directories(1_show_image PRIVATE
                            ${OpenCV_INCLUDE_DIRS})
target_link_libraries(1_show_image PRIVATE ${OpenCV_LIBS})
target_include_directories(2_show_video PRIVATE 
                            ${OpenCV_INCLUDE_DIRS})
target_link_libraries(2_show_video PRIVATE ${OpenCV_LIBS})

# 对 Eigen：使用已导出的目标（header-only）
target_link_libraries(1_show_image PRIVATE Eigen3::Eigen)
target_link_libraries(2_show_video PRIVATE Eigen3::Eigen)

target_link_libraries(1_show_image PRIVATE matplotlib_cpp::matplotlib_cpp)
target_link_libraries(2_show_video PRIVATE matplotlib_cpp::matplotlib_cpp)
# 可选：如果你想一次性让 target 继承 OpenCV 的 include，也可以只用 link：
# target_link_libraries(my_program PRIVATE ${OpenCV_LIBS} Eigen3::Eigen)