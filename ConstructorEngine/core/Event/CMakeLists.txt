cmake_minimum_required(VERSION 3.5)

add_library(Event STATIC event.h event.cpp)

target_include_directories(Event PUBLIC "${CMAKE_SOURCE_DIR}/Engine/core/Window")
target_link_libraries(Event PUBLIC EngineWindow)