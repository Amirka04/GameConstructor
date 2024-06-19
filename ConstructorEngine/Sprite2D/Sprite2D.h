#ifndef SPRITE2D_H
#define SPRITE2D_H

#include "window.h"
#include "TextureManager.h"
#include "Rectangle.hpp"



class Sprite2D : public Rectangle {
    public:
        Sprite2D(const char* path, const glm::vec2& position = {0, 0}, const glm::vec2& size = {0, 0});
        virtual ~Sprite2D();
        
        // рисование
        void render() override;
        
        // установка текстуры
        void setTexture(const char* path);
        
    private:
        Texture texture;
};



#endif