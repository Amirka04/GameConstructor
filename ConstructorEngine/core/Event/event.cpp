#include "event.h"


bool* event::keys = nullptr;
uint64_t *event::_frames = nullptr;
uint64_t event::_frame = 0;
uint64_t event::bufferSize = 1032;
glm::vec2 event::cursorPos = {0, 0};
glm::vec2 event::CursorVelocity = {0, 0};



void event::init(){
    keys = new bool[bufferSize];
    memset(keys, false, sizeof(bool) * bufferSize);

    _frames = new uint64_t[bufferSize];
    memset(_frames, 0, sizeof(uint64_t) * bufferSize);

    glfwSetKeyCallback(window::getMainWindow(), event::key_callback);
    glfwSetMouseButtonCallback(window::getMainWindow(), event::mouse_callback);
    glfwSetCursorPosCallback(window::getMainWindow(), event::mouse_moved_callback);
    glfwSetCursorEnterCallback(window::getMainWindow(), event::mouse_hovered_window_callback);
}


// key
bool event::KeyPressed(int key){
    return keys[key];
}
bool event::jKeyPressed(int key){
    return keys[key] && (_frames[key] == _frame);
}


// mouse
bool event::MouseButtonPressed(int button){
    return keys[MOUSE_BUTTON + button];
}
bool event::jMouseButtonPressed(int button){
    return keys[MOUSE_BUTTON + button] && (_frames[MOUSE_BUTTON + button] == _frame);
}



void event::update(){
    ++_frame;
    glfwPollEvents();
}


void event::free(){
    std::cout << "Очистка систем рендеринга" << std::endl;

    delete keys;
    delete _frames;

    keys = nullptr;
    _frames = nullptr;

    _frame = 0;
}



void event::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(action == GLFW_PRESS){
        keys[key] = true;
        _frames[key] = _frame;
    }
    else
        if(action == GLFW_RELEASE)
            keys[key] = false;
}


glm::vec2 event::getCursorPos(){ return cursorPos; }

glm::vec2 event::getVelocityCursor(){ return CursorVelocity; }


void event::mouse_callback(GLFWwindow* window, int button, int action, int mods){
    if(action == GLFW_PRESS){
        keys[MOUSE_BUTTON + button] = true;
        _frames[MOUSE_BUTTON + button] = _frame;
    }
    else
        if(action == GLFW_RELEASE)
            keys[MOUSE_BUTTON + button] = false;    
}


void event::mouse_moved_callback(GLFWwindow* window, double xPos, double yPos){
    // glm::vec2 NewCursorPosition = WindowCursorPosToOpenGL(glm::vec2{xPos, yPos});

    glm::vec2 NewCursorPosition{
        (1 - (xPos / (window::getWindowSize().x / 2.0))) * -1,
        1 - (yPos / (window::getWindowSize().y / 2.0))
    };

    CursorVelocity = NewCursorPosition - cursorPos;
    
    cursorPos = NewCursorPosition;
}



void event::mouse_hovered_window_callback(GLFWwindow* window, int hovered){
    if(!hovered){
        cursorPos = glm::vec2{-999, -999};
        CursorVelocity = glm::vec2{0, 0};
    }
}
