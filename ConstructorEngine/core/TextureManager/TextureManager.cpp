#include "TextureManager.h"

// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::vector<Texture2D*> TextureManager::buffer;

std::vector<glm::vec2> TextureCoord::coord = {{0,0}, {0,1}, {1,1}, {1,0}};


Texture2D* TextureManager::load(const char* path){
    Texture2D* texture = new Texture2D{0};

    int width, height, n;
    unsigned char* data = stbi_load(path, &width, &height, &n, 0);
    
    if(data == nullptr){
        std::cerr << "TextureManager::load() error ->" << path << "image not found" << std::endl;
        return nullptr;
    }

    glGenTextures(1, texture);
    
    glBindTexture(BIT_TEXTURE, *texture);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexImage2D(BIT_TEXTURE, 0, GL_RGB, width, height, 0, (n == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(BIT_TEXTURE, 0);
    
    stbi_image_free(data);

    buffer.push_back(texture);
    
    return texture;
}


void TextureManager::remove(Texture2D* pTexture){
    glDeleteTextures(1, pTexture);
    buffer.erase( std::remove(buffer.begin(), buffer.end(), pTexture), buffer.end() );
    *pTexture = 0;
    delete pTexture;
}

void TextureManager::finalization(){
    for(Texture2D* _iter : buffer)
        remove(_iter);
}