cmake_minimum_required(VERSION 3.5)

add_library(Circle STATIC Circle.cpp Circle.hpp)

target_include_directories(Circle PUBLIC "../Shape2D")
target_link_libraries(Circle PUBLIC Shape2D)