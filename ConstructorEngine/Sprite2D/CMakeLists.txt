cmake_minimum_required(VERSION 3.5)


add_library(Sprite2D STATIC Sprite2D.h Sprite2D.cpp)


target_include_directories(Sprite2D PUBLIC "../Shape/Rectangle/")
target_include_directories(Sprite2D PUBLIC "../core/TextureManager/")
target_include_directories(Sprite2D PUBLIC "../core/Window/")


target_link_libraries(Sprite2D PUBLIC EngineWindow)
target_link_libraries(Sprite2D PUBLIC TextureManager)
target_link_libraries(Sprite2D PUBLIC Rectangle)
