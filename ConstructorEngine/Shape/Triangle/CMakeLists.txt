cmake_minimum_required(VERSION 3.5)

add_library(Triangle STATIC Triangle.cpp Triangle.hpp)

target_include_directories(Triangle PUBLIC "../Shape2D")
target_link_libraries(Triangle PUBLIC Shape2D)