cmake_minimum_required(VERSION 3.5)


add_library(EngineWindow STATIC window.cpp window.h)


target_include_directories(EngineWindow PUBLIC glad/include/glad)
target_include_directories(EngineWindow PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/lib/glm/glm)
target_include_directories(EngineWindow PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/lib/glfw3/include)


target_link_libraries(EngineWindow PUBLIC glad)
target_link_libraries(EngineWindow PUBLIC glfw)
target_link_libraries(EngineWindow PUBLIC glm::glm)