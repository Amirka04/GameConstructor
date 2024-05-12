cmake_minimum_required(VERSION 3.5)

add_library( glad STATIC gladLib/glad.c include/glad/glad.h include/KHR/khrplatform.h )

target_include_directories(glad PUBLIC include)