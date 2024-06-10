#include "window.h"
#include "event.h"
#include "Renderer.h"
#include "BufferManager.h"

#include "Rectangle/Rectangle.hpp"





int main(int args, char** argv){
    assert(window::initialization("RenderShape", 900, 900) == true);
    Renderer::initialization();
    event::init();
    window::setIcon("sorticon.png");

    
    Rectangle shape(glm::vec2(0.4f, 0.0f), glm::vec2(0.1f));
    shape.setColor(GREEN);

    Rectangle shape2(glm::vec2(-0.4f, 0.0f), glm::vec2(0.3f));
    shape2.setColor(BLUE);

    Rectangle s = shape;
    shape = shape2;
    shape2 = s;



    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(0.5f));

        // рендер
        Renderer::render();

        // проверка на выход
        if(event::jKeyPressed(GLFW_KEY_Q))
            window::setShouldCloseWindow(true);
            
        window::swapBuffers();
        event::update();
    }
    
    // очистка всех ресурсов
    BufferManager::finallization();
    Renderer::finalization();
    event::free();
    window::finallyzation();
}
