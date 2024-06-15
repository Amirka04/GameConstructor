cmake_minimum_required(VERSION 3.5)

add_library(TextureManager STATIC TextureManager.h TextureManager.cpp)

target_include_directories(TextureManager PUBLIC ../Window)
target_link_libraries(TextureManager PUBLIC EngineWindow)