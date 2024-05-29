cmake_minimum_required(VERSION 3.5)

add_library(BufferManager STATIC BufferManager.cpp BufferManager.h)

target_include_directories(BufferManager PUBLIC "../Window")
target_link_libraries(BufferManager PUBLIC EngineWindow)
