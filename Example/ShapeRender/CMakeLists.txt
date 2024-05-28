cmake_minimum_required(VERSION 3.5)

project(RenderShape)

add_executable(RenderShape main.cpp)

target_include_directories(RenderShape PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Window)
target_include_directories(RenderShape PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Event)

target_include_directories(RenderShape PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/Shape)


target_link_libraries(RenderShape PUBLIC EngineWindow)
target_link_libraries(RenderShape PUBLIC Event)
target_link_libraries(RenderShape PUBLIC Shape2D Triangle Rectangle Circle)