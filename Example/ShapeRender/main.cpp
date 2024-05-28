#include "window.h"
#include "event.h"

#include "Shape2D/Shape2D.h"
#include "Rectangle/Rectangle.hpp"
#include "Triangle/Triangle.hpp"
#include "Circle/Circle.hpp"



int main(int args, char** argv){
    assert(window::initialization("RenderShape", 900, 900) == true);
    event::init();

    Circle *circle = new Circle(glm::vec2(0.0f, 0.0f), glm::vec2(1.0f, 1.0f));


    while(!window::isShouldCloseWindow()){
        window::clear(glm::vec4(0.5f));
        
        
        if(event::jKeyPressed(GLFW_KEY_Q))
            window::setShouldCloseWindow(true);
        

        window::swapBuffers();
        event::update();
    }


    event::free();
    window::finallyzation();
}