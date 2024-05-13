cmake_minimum_required(VERSION 3.5)


set(CMAKE_BUILD_TYPE DEBUG)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glad)
add_subdirectory(glfw3)
add_subdirectory(glm)
