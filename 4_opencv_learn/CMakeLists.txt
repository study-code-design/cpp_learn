cmake_minimum_required(VERSION 3.11)
project(4_opencv_learn LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 查找 OpenCV - 优先使用导入目标
find_package(OpenCV REQUIRED)

# 从系统路径查找 matplotlib_cpp
find_package(matplotlib_cpp REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
# 使用 OpenCV 的导入目标（如果可用）
if(TARGET OpenCV::OpenCV)
    message(STATUS "Using OpenCV imported target: OpenCV::OpenCV")
    set(OPENCV_TARGET OpenCV::OpenCV)
else()
    message(STATUS "Using OpenCV variables: ${OpenCV_LIBS}")
    set(OPENCV_TARGET ${OpenCV_LIBS})
endif()

# 创建可执行文件 - 使用正确的目标名称
add_executable(1_load_image 1_load_image.cpp)
target_link_libraries(1_load_image PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(2_load_video 2_load_video.cpp)
target_link_libraries(2_load_video PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(3_base_func 3_base_func.cpp)
target_link_libraries(3_base_func PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(4_resize_crop 4_resize_crop.cpp)
target_link_libraries(4_resize_crop PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(5_drawShaps_texts 5_drawShaps_texts.cpp)
target_link_libraries(5_drawShaps_texts PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(6_wrap_image 6_wrap_image.cpp)
target_link_libraries(6_wrap_image PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(7_detect_color 7_detect_color.cpp)
target_link_libraries(7_detect_color PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(8_find_shapes 8_find_shapes.cpp)
target_link_libraries(8_find_shapes PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(9_face_detection 9_face_detection.cpp)
target_link_libraries(9_face_detection PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(10_strokes_track 10_strokes_track.cpp)
target_link_libraries(10_strokes_track PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)

add_executable(11_CamScanner 11_CamScanner.cpp)
target_link_libraries(11_CamScanner PRIVATE ${OPENCV_TARGET} matplotlib_cpp::matplotlib_cpp)