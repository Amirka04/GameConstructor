#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "window.h"


// константы для более удобного обращение к ним
const int BIT_TEXTURE = GL_TEXTURE_2D;


// Теxture2D будет просто индексом
using Texture2D = GLuint;


class Texture{
    public:
        Texture();
        void bind();
        void unbind();
        void setUV(std::vector<glm::vec2> newUV);
    
        Texture2D id;
        int width, height;
        std::string TextureName;
    
    protected:
        std::vector<glm::vec2> uv;
        std::vector<glm::vec2> defaultUV;
};



class TextureManager{
    public:
        static void load(Texture& texture, const std::string& path);
        static void remove(Texture& texture);
        static void reloadTexture(Texture& texture_texItem, const std::string& path);
        static void finalization();
    private:
        // первая хеш-таблица содержит в себе:
        // ключ - строка, у нас это будет путь до текстуры или его имя
        // значение кол-во
        static std::map<std::string, int64_t> TextureCount;
        // во второй хеш-таблице тоже самое, но в качестве значения будет использоваться id текстуры для OpenGL
        static std::map<std::string, Texture2D> TextureID;
};



#endif