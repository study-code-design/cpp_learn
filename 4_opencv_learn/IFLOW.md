# OpenCV 学习项目 - iFlow 配置文档

## 项目概述

这是一个基于 C++20 的 OpenCV 学习项目，包含 11 个独立的计算机视觉示例程序。项目采用 CMake 构建系统，专注于 OpenCV 核心功能的实践学习。

**主要技术栈：**
- **语言**: C++20
- **计算机视觉库**: OpenCV (4.x)
- **构建系统**: CMake (最低版本 3.11)
- **开发环境**: Windows (支持 Visual Studio/MinGW) 和 Linux

**项目结构：**
- 11 个独立的可执行文件，每个演示不同的 OpenCV 功能
- 示例图片和视频资源位于 `pictures/` 目录
- 支持多种构建配置（Debug/Release）

## 构建和运行

### 前置要求
- CMake 3.11+
- C++20 兼容的编译器 (Visual Studio 2019+, GCC 10+, Clang 10+)
- OpenCV 4.x 库（已编译）

### 构建命令

#### 方法 1: 使用 CMake 预设（推荐）
```bash
# Debug 构建
cmake --preset debug
cmake --build build/debug

# Release 构建
cmake --preset release
cmake --build build/release
```

#### 方法 2: 手动 CMake 构建
```bash
# 创建构建目录
mkdir build && cd build

# 配置（Windows - Visual Studio）
cmake .. -G "Visual Studio 16 2019" -A x64

# 配置（Windows - MinGW）
cmake .. -G "MinGW Makefiles"

# 配置（Linux）
cmake .. -G "Unix Makefiles"

# 构建所有目标
cmake --build . --config Debug
```

### 运行示例程序

每个示例都是独立的可执行文件，构建后位于构建目录中：

```bash
# 运行图片加载示例
./build/debug/1_load_image

# 运行视频处理示例
./build/debug/2_load_video

# 运行 CamScanner 示例（需要图片路径参数）
./build/debug/11_CamScanner path/to/image.jpg
```

### VS Code 集成

项目已配置 VS Code 任务，可直接使用快捷键运行：
- **Ctrl+Shift+B**: 构建当前文件
- **F5**: 调试当前文件

## 开发规范

### 代码风格
- **命名规范**: 使用小写字母和下划线（snake_case）
  - 文件: `1_load_image.cpp`
  - 函数: `pre_processing()`, `getContours_()`
  - 变量: `img_path`, `img_gray`

- **OpenCV 使用**: 每个示例独立包含所需 OpenCV 头文件
  ```cpp
  #include <opencv2/imgcodecs.hpp>
  #include <opencv2/highgui.hpp>
  #include <opencv2/imgproc.hpp>
  ```

- **命名空间**: 在函数内部使用 `using namespace cv;` 和 `using namespace std;`

### 项目配置

**CMakeLists.txt 关键配置:**
- C++20 标准 (`CMAKE_CXX_STANDARD 20`)
- 自动导出编译命令 (`CMAKE_EXPORT_COMPILE_COMMANDS ON`)
- Debug 构建类型 (`CMAKE_BUILD_TYPE Debug`)
- 动态查找 OpenCV 库 (`find_package(OpenCV REQUIRED)`)

**OpenCV 集成:**
- 优先使用 OpenCV 导入目标 (`OpenCV::OpenCV`)
- 回退到传统变量方式 (`${OpenCV_LIBS}`)
- 包含 OpenCV 头文件目录 (`${OpenCV_INCLUDE_DIRS}`)

### 资源管理

**图片资源** (`pictures/` 目录):
- `shapes.png`: 形状检测示例用图
- `green_ball.jpg`: 颜色检测示例用图
- `objects.jpg`: 物体检测示例用图
- `doc.png`: 文档扫描示例用图

**视频资源**:
- `video.mp4`: 视频处理示例用视频

## 示例程序功能说明

### 基础功能示例
1. **1_load_image.cpp**: 图片加载和显示基础
2. **2_load_video.cpp**: 视频流处理和基本变换
3. **3_base_func.cpp**: OpenCV 基础函数演示
4. **4_resize_crop.cpp**: 图像缩放和裁剪操作
5. **5_drawShaps_texts.cpp**: 图形绘制和文本渲染
6. **6_wrap_image.cpp**: 图像几何变换

### 高级应用示例
7. **7_detect_color.cpp**: 颜色空间转换和颜色检测
8. **8_find_shapes.cpp**: 轮廓检测和形状识别
9. **9_face_detection.cpp**: 人脸检测实现
10. **10_strokes_track.cpp**: 手势追踪功能
11. **11_CamScanner.cpp**: 文档扫描和透视变换（完整应用）

## 跨平台支持

项目支持多种平台和构建环境：

**Windows:**
- Visual Studio 2019/2022 (MSVC)
- MinGW-w64
- CLion (内置 CMake 支持)

**Linux:**
- GCC 10+
- Clang 10+
- 系统包管理器安装的 OpenCV

**CMake 预设:**
- `debug`: Debug 构建配置
- `release`: Release 优化构建
- `custom_file`: 自定义工具链配置

## 注意事项

1. **OpenCV 路径配置**: 确保 `OpenCV_DIR` 环境变量指向正确的 OpenCV 安装路径
2. **资源路径**: 示例中的图片路径为绝对路径，可能需要根据实际环境修改
3. **摄像头支持**: 部分示例需要摄像头设备支持
4. **网络摄像头**: `2_load_video.cpp` 支持网络摄像头流（需修改 URL）
