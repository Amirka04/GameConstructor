#pragma once

#include <iostream>
#include <memory.h>
#include <bits/stdc++.h>


#include "glad.h"
#include "GLFW/glfw3.h"
#include "glm.hpp"
// #include "SOIL/SOIL.h"

class window{
    public:
        // инициализация
        static bool initialization(const std::string& title, int w, int h);

        // очистка и закрашивание в опр цвет
        static void clear(const glm::vec4 &color);

        // установка закрытия окна
        static void setShouldCloseWindow(bool flag);
        
        // двойная буферизация
        static void swapBuffers();

        // проверка на закрытие окна
        static bool isShouldCloseWindow();

        // получение размера окна
        static glm::ivec2 getWindowSize();
        
        // установка размера окна
        static void setWindowSize(const glm::ivec2 &winSize);
        
        // получение координат окна
        static glm::ivec2 getWindowPos();

        // установка координат окна
        static void setWindowPos(const glm::ivec2 &winPos);

        // установка иконки
        static void setIcon(const std::string &iconSource);
        
        // получение смещение масштаба окна
        static glm::vec2 getOffsideScale();

        // получение ссылки на главное окно
        static GLFWwindow* getMainWindow();

        // очистка всех ресурсов
        static void finallyzation();
    private:
        static GLFWwindow* win;
        static GLFWimage icon[1];

        static glm::vec2 offsetScale;
        
        static glm::ivec2 windowSize;
        static glm::ivec2 windowPos;
};
