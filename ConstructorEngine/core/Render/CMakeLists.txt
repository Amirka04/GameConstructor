cmake_minimum_required(VERSION 3.5)

add_library(Renderer STATIC Renderer.h Renderer.cpp)
add_library(RenderItem STATIC RenderItem.h RenderItem.cpp)

target_link_libraries(RenderItem PUBLIC Renderer)