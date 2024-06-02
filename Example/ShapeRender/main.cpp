#include "window.h"
#include "event.h"
#include "BufferManager.h"

#include "Shape2D/Shape2D.h"
#include "Rectangle/Rectangle.hpp"
#include "Triangle/Triangle.hpp"
#include "Circle/Circle.hpp"



int main(int args, char** argv){
    assert(window::initialization("RenderShape", 900, 900) == true);
    event::init();

    Rectangle *shape = new Rectangle(glm::vec2(0.0f, 0.0f), glm::vec2(0.5f));
    shape->setColor(glm::vec3(GREEN));

    int i = 0;

    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(0.5f));
        
        shape->setRotate( ++i % 360 );
        shape->render();
                

        if(event::jKeyPressed(GLFW_KEY_Q))
            window::setShouldCloseWindow(true);
            
        window::swapBuffers();
        event::update();
    }

    // очистка всех ресурсов
    BufferManager::finallization();
    event::free();
    window::finallyzation();
}