#ifndef EVENT_H
#define EVENT_H


#include "window.h"


const uint64_t MOUSE_BUTTON = 1024;


class event
{
public:
    // инициализация статических данных и обратных вызовов
    static void init();
    
    // отслеживание нажатия постоянного нажатия клавишу
    static bool KeyPressed(int key);

    // отслеживание одиночного нажатия на клавишу
    static bool jKeyPressed(int key);
    
    // отслеживание постоянного нажатия на кнопки мыши    
    static bool MouseButtonPressed(int button);

    // отслеживание одиночного нажатия на клавишу
    static bool jMouseButtonPressed(int button);

    // получение координат мыши
    static glm::vec2 getCursorPos();

    // получение изменения координат за кадр
    static glm::vec2 getVelocityCursor();

    // обновление событий
    static void update();
    
    // очистка памяти
    static void free();

private:
    static bool* keys;
    static uint64_t *_frames;
    static uint64_t _frame;
    static uint64_t bufferSize;
    static glm::vec2 cursorPos;
    static glm::vec2 CursorVelocity;
private:
    // callbacks
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    static void mouse_callback(GLFWwindow* window, int button, int action, int mods);
    static void mouse_moved_callback(GLFWwindow* window, double xPos, double yPos);
    static void mouse_hovered_window_callback(GLFWwindow* window, int hovered);
};



#endif