#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "window.h"


// константы для более удобного обращение к ним
const int BIT_TEXTURE = GL_TEXTURE_2D;


// Теxture2D будет просто индексом
using Texture2D = GLuint;


struct TextureCoord{
    static std::vector<glm::vec2> coord;
};

class TextureManager{
    public:
        static Texture2D* load(const char* path);
        static void remove(Texture2D* pTexture);
        static void finalization();
    private:
        // будет хранить в себе адреса всех текстур
        static std::vector<Texture2D*> buffer;
};


#endif