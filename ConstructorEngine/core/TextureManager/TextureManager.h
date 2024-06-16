#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "window.h"


// константы для более удобного обращение к ним
const int BIT_TEXTURE = GL_TEXTURE_2D;


// Теxture2D будет просто индексом
using Texture2D = GLuint;


class TextureItem{
    public:
        std::vector<glm::vec2> uv;
        Texture2D id;
        int width, height;
        std::string TextureName;
        
        TextureItem();
};



class TextureManager{
    public:
        static TextureItem* load(const char* path);
        static void remove(TextureItem* _texItem);
        static void reloadTexture(TextureItem* _texItem, const char* path);
        static void finalization();
    private:
        // будет хранить в себе адреса всех текстур
        static std::vector<TextureItem*> buffer;
};


#endif