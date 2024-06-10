#include "window.h"
#include "event.h"
#include "BufferManager.h"
#include "Renderer.h"

#include "Rectangle/Rectangle.hpp"



void swapPos(Rectangle& shape, Rectangle& shape2){
    glm::vec2 tmp = shape.getPosition();
    shape.setPosition(shape2.getPosition());
    shape2.setPosition(tmp);
}




int main(int args, char** argv){
    assert(window::initialization("RenderShape", 900, 900) == true);
    Renderer::initialization();
    event::init();
    window::setIcon("source/GameConstructorIcon.png");


    Rectangle shape(glm::vec2(0.0f, 0.0f), glm::vec2(0.1f));
    shape.setColor(glm::vec3(BLUE));


    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(0.5f));            

        Renderer::render();

        if(event::jKeyPressed(GLFW_KEY_S))
        shape.show();
        if(event::jKeyPressed(GLFW_KEY_H))
            shape.hide();

        if(event::jKeyPressed(GLFW_KEY_Q))
            window::setShouldCloseWindow(true);
            
        window::swapBuffers();
        event::update();
    }
    
    // очистка всех ресурсов движка
    BufferManager::finallization();
    Renderer::finalization();
    event::free();
    window::finallyzation();
}
