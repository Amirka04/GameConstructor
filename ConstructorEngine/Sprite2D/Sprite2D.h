#ifndef SPRITE2D_H
#define SPRITE2D_H

#include "window.h"
#include "TextureManager.h"
#include "Rectangle.hpp"



class Sprite2D : public Rectangle {
    public:
        Sprite2D(const char* path = nullptr, const glm::vec2& position = {0, 0}, const glm::vec2& size = {0, 0});
        virtual ~Sprite2D();
        
        // рисование
        void render() override;
        
        // установка текстуры
        void setTexture(const char* path);

        // Получение высоты и ширины текстуры
        glm::vec2 getTextureSize();
    private:
        TextureItem* Texture;
};



#endif