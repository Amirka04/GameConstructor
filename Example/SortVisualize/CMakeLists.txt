cmake_minimum_required(VERSION 3.5)

project(SortVisualize)

add_executable(SortVisualize main.cpp)


target_include_directories(SortVisualize PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Window)
target_include_directories(SortVisualize PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Event)
target_include_directories(SortVisualize PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Render)
target_include_directories(SortVisualize PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/BufferManager)

target_include_directories(SortVisualize PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/Shape)

target_link_libraries(SortVisualize PUBLIC EngineWindow)
target_link_libraries(SortVisualize PUBLIC Event)
target_link_libraries(SortVisualize PUBLIC Shape2D Triangle Rectangle Circle)
target_link_libraries(SortVisualize PUBLIC Renderer)
target_link_libraries(SortVisualize PUBLIC BufferManager)