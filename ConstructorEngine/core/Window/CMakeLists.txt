cmake_minimum_required(VERSION 3.5)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)


add_library(EngineWindow STATIC window.cpp window.h)


target_include_directories(EngineWindow PUBLIC glad/include/glad)

target_link_libraries(EngineWindow PUBLIC glfw)
target_link_libraries(EngineWindow PUBLIC glad)
target_link_libraries(EngineWindow PUBLIC glm::glm)