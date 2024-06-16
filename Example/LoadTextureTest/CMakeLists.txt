cmake_minimum_required(VERSION 3.5)

project(LoadTextureTest)

add_executable(LoadTextureTest main.cpp)


target_include_directories(LoadTextureTest PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Window)
target_include_directories(LoadTextureTest PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Event)
target_include_directories(LoadTextureTest PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/Render)
target_include_directories(LoadTextureTest PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/BufferManager)
target_include_directories(LoadTextureTest PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/core/TextureManager)
target_include_directories(LoadTextureTest PUBLIC ${CMAKE_SOURCE_DIR}/ConstructorEngine/Sprite2D)



target_link_libraries(LoadTextureTest PUBLIC EngineWindow)
target_link_libraries(LoadTextureTest PUBLIC Event)
target_link_libraries(LoadTextureTest PUBLIC Shape2D Triangle Rectangle Circle)
target_link_libraries(LoadTextureTest PUBLIC Renderer)
target_link_libraries(LoadTextureTest PUBLIC BufferManager)
target_link_libraries(LoadTextureTest PUBLIC TextureManager)
target_link_libraries(LoadTextureTest PUBLIC Sprite2D)
