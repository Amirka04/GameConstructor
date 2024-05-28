cmake_minimum_required(VERSION 3.5)

add_library(Rectangle STATIC Rectangle.cpp Rectangle.hpp)

target_include_directories(Rectangle PUBLIC "../Shape2D")
target_link_libraries(Rectangle PUBLIC Shape2D)