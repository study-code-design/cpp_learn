# C++ 学习笔记项目 - iFlow 配置文档

## 项目概述

这是一个综合性的 C++ 学习笔记项目，记录了从基础到高级的 C++ 学习历程。项目采用模块化结构，每个子目录都是一个独立的学习主题，包含完整的代码示例和构建配置。

**主要技术栈：**
- **语言**: C++11/C++20
- **构建系统**: CMake (最低版本 3.10-3.11)
- **计算机视觉**: OpenCV 4.x (部分模块)
- **开发环境**: Windows (主要) 和 Linux
- **版本控制**: Git LFS (用于管理大文件)

**项目结构：**
- 11 个独立的学习模块，涵盖 C++ 核心概念
- 每个模块都有独立的 CMake 构建配置
- 包含算法练习（LeetCode）、计算机视觉、网络编程等实战内容
- 使用 Git LFS 管理视频、安装包等大文件

## 项目模块说明

### 1. 基础 C++ 模块

#### `1_quote_memory/` - 引用与内存管理
- C++ 引用的基本概念和使用
- 内存管理（new/delete）
- 函数重载
- 类和对象基础
- **构建**: `cmake -B build && cmake --build build`

#### `2_constr_and_destr/` - 构造与析构函数
- 构造函数系列（默认、有参、拷贝）
- 深拷贝与浅拷贝
- 静态成员
- this 指针
- const 成员函数
- 运算符重载（+、<<、=、关系运算符）
- **构建**: `cmake -B build && cmake --build build`

#### `3_inheritance/` - 继承与多态
- 继承基础
- 多态实现
- 虚析构函数
- **构建**: `cmake -B build && cmake --build build`

#### `4_template/` - 模板编程
- 函数模板
- 模板特化与限制
- 类模板
- 模板的高级应用
- **构建**: `cmake -B build && cmake --build build`

### 2. 高级应用模块

#### `4_opencv_learn/` - OpenCV 计算机视觉（完整项目）
**最完整的模块，包含 11 个独立的计算机视觉示例**

**示例程序：**
1. **1_load_image.cpp**: 图片加载和显示
2. **2_load_video.cpp**: 视频流处理
3. **3_base_func.cpp**: OpenCV 基础函数
4. **4_resize_crop.cpp**: 图像缩放和裁剪
5. **5_drawShaps_texts.cpp**: 图形绘制和文本渲染
6. **6_wrap_image.cpp**: 图像几何变换
7. **7_detect_color.cpp**: 颜色空间转换和颜色检测
8. **8_find_shapes.cpp**: 轮廓检测和形状识别
9. **9_face_detection.cpp**: 人脸检测
10. **10_strokes_track.cpp**: 手势追踪
11. **11_CamScanner.cpp**: 文档扫描和透视变换（完整应用）

**构建命令：**
```bash
# Debug 构建
cmake --preset debug
cmake --build build/debug

# Release 构建
cmake --preset release
cmake --build build/release

# 手动构建
mkdir build && cd build
cmake .. -G "Visual Studio 16 2019" -A x64  # Windows
cmake --build . --config Debug
```

**运行示例：**
```bash
./build/debug/1_load_image
./build/debug/11_CamScanner path/to/image.jpg
```

**资源文件：**
- `pictures/`: 示例图片（shapes.png, green_ball.jpg, objects.jpg, doc.png）
- `video.mp4`: 视频处理示例

#### `5_socket/` - 网络编程
- TCP 客户端/服务器实现
- Socket 编程基础
- **构建**: `cmake -B build && cmake --build build`

#### `6_STL/` - 标准模板库（STL）
包含多个子模块：
- `vector_use/`: 向量容器（构造、插入删除、交换、嵌套）
- `string_use/`: 字符串操作（赋值、查找、子串）
- `deque_use/`: 双端队列
- `list_use/`: 链表（插入删除）
- `set_use/`: 集合容器
- **构建**: 各子模块有独立的构建配置

### 3. 实战练习模块

#### `leetcode_exame/` - LeetCode 算法题
包含多个算法实现：
- 位运算、字符串处理
- 排序算法
- 数组操作（移动零、接雨水、回文数）
- 双指针技巧（两数之和、三数之和）
- **标准**: C++20
- **构建**: `cmake -B build && cmake --build build`

#### `modern_cpp/` - 现代 C++ 特性
- C++11/14/17/20 新特性学习

#### `0_linux_cpp/` - Linux C++ 编程
- Linux 系统编程基础
- 时间、目录、信号、进程管理

#### `0_header_test/` - 头文件与库测试
- CMake 库导出测试
- 头文件组织最佳实践

## 开发规范

### 代码风格
- **命名规范**: 
  - 文件: 小写字母和下划线（如 `1_load_image.cpp`）
  - 函数: 小写字母和下划线（如 `pre_processing()`）
  - 变量: 小写字母和下划线（如 `img_path`）
- **命名空间**: 在函数内部使用 `using namespace cv;` 和 `using namespace std;`
- **C++ 标准**: 
  - 基础模块: C++11
  - OpenCV 和算法模块: C++20

### CMake 配置规范
- **最低版本**: 3.10-3.11
- **C++ 标准**: 明确设置 `CMAKE_CXX_STANDARD`
- **构建类型**: Debug 模式为主（`CMAKE_BUILD_TYPE Debug`）
- **OpenCV 集成**: 动态查找，优先使用导入目标
  ```cmake
  find_package(OpenCV REQUIRED)
  if(TARGET OpenCV::OpenCV)
      target_link_libraries(target PRIVATE OpenCV::OpenCV)
  else()
      target_link_libraries(target PRIVATE ${OpenCV_LIBS})
  endif()
  ```

### Git LFS 配置
项目使用 Git LFS 管理大文件：
```
**/*.mp4 filter=lfs diff=lfs merge=lfs -text
windows_required/opencv-4.12.0-windows.exe filter=lfs diff=lfs merge=lfs -text
windows_required/vs_Community.exe filter=lfs diff=lfs merge=lfs -text
```

**LFS 跟踪的文件类型：**
- 视频文件（.mp4）
- OpenCV Windows 安装包
- Visual Studio Community 安装包

## 构建和运行

### 前置要求
- CMake 3.10+
- C++11/C++20 兼容的编译器
- OpenCV 4.x（用于计算机视觉模块）
- Git LFS（用于克隆大文件）

### 通用构建命令
```bash
# 进入特定模块目录
cd <module_directory>

# 创建构建目录并编译
mkdir build && cd build
cmake .. -G "Visual Studio 16 2019" -A x64  # Windows Visual Studio
cmake .. -G "MinGW Makefiles"              # Windows MinGW
cmake .. -G "Unix Makefiles"               # Linux

# 构建所有目标
cmake --build . --config Debug

# 运行特定示例
./Debug/<executable_name>
```

### IDE 支持
- **Visual Studio**: 直接打开 CMakeLists.txt
- **CLion**: 内置 CMake 支持
- **VS Code**: 已配置 CMake Tools 扩展

## 注意事项

1. **OpenCV 路径配置**: 确保 `OpenCV_DIR` 环境变量指向正确的 OpenCV 安装路径（如 `D:/opencv/build/x64/vc16/lib`）

2. **资源路径**: 示例代码中的图片路径为绝对路径，可能需要根据实际环境修改

3. **摄像头支持**: 部分 OpenCV 示例需要摄像头设备

4. **网络摄像头**: `2_load_video.cpp` 支持网络摄像头流（需修改 URL）

5. **Git LFS**: 克隆项目时需要先安装 Git LFS，否则大文件无法正确下载
   ```bash
   git lfs install
   git clone <repository>
   ```

6. **跨平台注意**: 部分路径硬编码为 Windows 路径（如 `D:/cpp_project/...`），在 Linux 下需要修改

## 学习路径建议

1. **初学者**: `1_quote_memory/` → `2_constr_and_destr/` → `3_inheritance/` → `4_template/`
2. **进阶**: `6_STL/` → `leetcode_exame/` → `4_opencv_learn/`
3. **实战**: `5_socket/` → `modern_cpp/` → `0_linux_cpp/`
4. **完整项目**: 重点学习 `4_opencv_learn/`，包含从基础到完整的计算机视觉应用
