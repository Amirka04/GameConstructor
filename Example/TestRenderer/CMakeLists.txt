cmake_minimum_required(VERSION 3.5)

project(TestRenderer)

add_executable(TestRenderer main.cpp)


target_include_directories(TestRenderer PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Window)
target_include_directories(TestRenderer PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Event)
target_include_directories(TestRenderer PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Render)
target_include_directories(TestRenderer PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/BufferManager)
target_include_directories(TestRenderer PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/Shape)


target_link_libraries(TestRenderer PUBLIC EngineWindow)
target_link_libraries(TestRenderer PUBLIC Event)
target_link_libraries(TestRenderer PUBLIC BufferManager)
target_link_libraries(TestRenderer PUBLIC Shape2D Triangle Rectangle Circle)
target_link_libraries(TestRenderer PUBLIC Renderer)
