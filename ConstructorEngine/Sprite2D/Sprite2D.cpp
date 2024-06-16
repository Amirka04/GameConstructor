#include "Sprite2D.h"


Sprite2D::Sprite2D(const char* path, const glm::vec2& position, const glm::vec2& size){
    if(path != nullptr){
        Texture = TextureManager::load(path);
        setSize(size);
        setPosition(position);
        setColor(WHITE);
    }
}


Sprite2D::~Sprite2D(){
    TextureManager::remove(Texture);
    Renderer::remove(this);
}


// рендер
void Sprite2D::render(){
    glEnable(BIT_TEXTURE);
    glBindTexture(BIT_TEXTURE, Texture->id);

    // загрузка спрайта и координат отображения на фигуре
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, &Texture->uv.front());
    glDisableClientState(GL_VERTEX_ARRAY);

    Rectangle::render();
}


void Sprite2D::setTexture(const char* path){
    TextureManager::reloadTexture(Texture, path);
}


glm::vec2 Sprite2D::getTextureSize(){ return glm::vec2(Texture->width, Texture->height); }