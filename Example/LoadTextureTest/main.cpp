#include "window.h"
#include "event.h"
#include "BufferManager.h"
#include "Renderer.h"
#include "TextureManager.h"

#include "Rectangle.hpp"
#include "Sprite2D.h"


const glm::vec2 UP = {0, 1};
const glm::vec2 DOWN = {0, -1};
const glm::vec2 LEFT = {-1, 0};
const glm::vec2 RIGHT = {1, 0};


#ifdef WIN32
    #define MainFunc int WinMain()
#else
    #define MainFunc int main()
#endif


MainFunc {
    assert(window::initialization("Testing load texture", 1000, 1000) == true);
    window::setIcon("source/GameConstructorIcon.png");
    event::init();
    Renderer::initialization();


    Sprite2D background("source/Space.png", glm::vec2(0, 0), glm::vec2(1.0f, 1.0f));
    Sprite2D background2("source/Space.png", glm::vec2(0, 1.0f), glm::vec2(1.0f, 1.0f));

    Sprite2D ship("source/ship.png", glm::vec2(0.0f, 0.0f), glm::vec2(0.15f));
    float speed = 0.02f;


    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(1.0f));

        Renderer::render();


        if(event::KeyPressed(GLFW_KEY_W))
            ship.setPosition( ship.getPosition() + UP * speed );
        if(event::KeyPressed(GLFW_KEY_S))
            ship.setPosition( ship.getPosition() + DOWN * speed );
        if(event::KeyPressed(GLFW_KEY_D))
            ship.setPosition( ship.getPosition() + RIGHT * speed );
        if(event::KeyPressed(GLFW_KEY_A))
            ship.setPosition( ship.getPosition() + LEFT * speed );
        
        ship.setPosition( glm::clamp(ship.getPosition(), glm::vec2(-1.0f) + ship.getSize(), glm::vec2(1.0f) - ship.getSize()) );

        

        if(event::jKeyPressed(GLFW_KEY_Q))
            window::setShouldCloseWindow(true);
            
        window::swapBuffers();
        event::update();
    }

    // очистка всех ресурсов движка
    TextureManager::finalization();
    Renderer::finalization();
    BufferManager::finallization();
    event::free();
    window::finallyzation();

    return 0;
}