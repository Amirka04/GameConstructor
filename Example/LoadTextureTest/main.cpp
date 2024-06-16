#include "window.h"
#include "event.h"
#include "BufferManager.h"
#include "Renderer.h"
#include "TextureManager.h"


#include "Sprite2D.h"



int main(int args, char** argv){
    assert(window::initialization("Testing load texture", 900, 900) == true);
    window::setIcon("source/GameConstructorIcon.png");
    event::init();
    Renderer::initialization();


    Sprite2D sprite_test("background.jpg", glm::vec2(0, 0), glm::vec2(1.0f, 1.0f));
    

    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(0.5f));

        Renderer::render();
        

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
}
