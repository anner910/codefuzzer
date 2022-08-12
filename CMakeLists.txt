cmake_minimum_required(VERSION 3.22)

# 声明一个 cmake 工程
project(codefuzzer)

aux_source_directory(codefuzzer/core/ DIR_SRCS)
aux_source_directory(codefuzzer/mutator/ DIR_SRCS)
aux_source_directory(codefuzzer/plus/ DIR_SRCS)

set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -O0 -g -fno-omit-frame-pointer")
set(CMAKE_C_FLAGS " ${CMAKE_C_FLAGS} -O0 -g -fno-omit-frame-pointer")

# 添加库( 库名（自己设置） 库的实现文件及路径 ）
add_library(codefuzzer STATIC ${DIR_SRCS})
