#include "Sprite2D.h"


Sprite2D::Sprite2D(const char* path, const glm::vec2& position, const glm::vec2& size){
    TextureManager::load(texture, path);
    setSize(size);
    setPosition(position);
    setColor(WHITE);
}


Sprite2D::~Sprite2D(){
    TextureManager::remove(texture);
}


// рендер
void Sprite2D::render(){
    texture.bind();
    Rectangle::render();
}


void Sprite2D::setTexture(const char* path){
    TextureManager::reloadTexture(texture, path);
}