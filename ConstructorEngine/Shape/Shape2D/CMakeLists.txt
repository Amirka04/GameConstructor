cmake_minimum_required(VERSION 3.5)


add_library(Shape2D STATIC Shape2D.h Shape2D.cpp)


target_include_directories(Shape2D PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Window)
target_link_libraries(Shape2D PUBLIC EngineWindow)


target_include_directories(Shape2D PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/BufferManager)
target_link_libraries(Shape2D PUBLIC BufferManager)
