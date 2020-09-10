cmake_minimum_required(VERSION 3.14)
project(CppDemo1)

#代码路径
aux_source_directory(. DIR_ROOT_SRCS)

set(CMAKE_CXX_STANDARD 17)

# 添加头文件路径
include_directories(
        ${PROJECT_SOURCE_DIR}/struct_demo
)

add_subdirectory(struct_demo)

add_subdirectory(class_demo)

add_subdirectory(stl_demo)

add_executable(CppDemo1 main.cpp)

target_link_libraries(CppDemo1 struct_demo class_demo stl_demo)
