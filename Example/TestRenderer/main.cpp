#include "window.h"
#include "event.h"
#include "BufferManager.h"
#include "Renderer.h"

#include "Rectangle/Rectangle.hpp"



int main(int args, char** argv){
    assert(window::initialization("RenderShape", 900, 900) == true);
    Renderer::initialization();
    event::init();
    window::setIcon("source/GameConstructorIcon.png");


    Rectangle *shape = new Rectangle(glm::vec2(-0.2), glm::vec2(0.25f));
    shape->setColor(glm::vec3(BLACK));

    Rectangle *shape2 = new Rectangle(glm::vec2(0.2), glm::vec2(0.25f));
    shape2->setColor(GREEN);

    
    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(0.5f));
        
        Renderer::render();

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
