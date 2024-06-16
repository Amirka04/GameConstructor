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


void Sprite2D::render(){    
    glBindBuffer(GL_ARRAY_BUFFER, getVBO());
        glVertexPointer(2, GL_FLOAT, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnable(BIT_TEXTURE);
    glBindTexture(BIT_TEXTURE, Texture->id);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glColor3f(color.r, color.g, color.b);
        glTexCoordPointer(2, GL_FLOAT, 0, &Texture->uv.front());
        glDrawArrays(GL_POLYGON, 0, getDrawArray().size());
    glDisableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}