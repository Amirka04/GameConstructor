#include "TextureManager.h"

// #define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::vector<TextureItem*> TextureManager::buffer;



TextureItem::TextureItem(){
    id = 0;
    uv = {
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 0},
    };
}



TextureItem* TextureManager::load(const char* path){
    TextureItem* texItem = new TextureItem;
    int n;
    unsigned char* data = stbi_load(path, &texItem->wigth, &texItem->height, &n, 0);
    
    if(data == nullptr){
        std::cerr << "TextureManager::load() error -> " << path << " image not found" << std::endl;
        return nullptr;
    }

    texItem->TextureName = path;

    glGenTextures(1, &texItem->id);
    
    glBindTexture(BIT_TEXTURE, texItem->id);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(BIT_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(BIT_TEXTURE, 0, GL_RGB, texItem->wigth, texItem->height, 0, (n == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(BIT_TEXTURE);
    glBindTexture(BIT_TEXTURE, 0);
    
    stbi_image_free(data);

    buffer.push_back(texItem);
    
    return texItem;
}


void TextureManager::reloadTexture(TextureItem* texItem){
    int n;
    unsigned char* data = stbi_load(texItem->TextureName.c_str(), &texItem->wigth, &texItem->height, &n, 0);
    
    if(data == nullptr){
        std::cerr << "TextureManager::load() error -> " << texItem->TextureName << " image not found" << std::endl;
    }

    glBindTexture(BIT_TEXTURE, texItem->id);
        glTexSubImage2D(BIT_TEXTURE, 0, 0, texItem->wigth, texItem->height, 0, (n == 4) ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(BIT_TEXTURE, 0);
    
    stbi_image_free(data);
}


void TextureManager::remove(TextureItem* texItem){
    if(std::count(buffer.begin(), buffer.end(), texItem)){
        glDeleteTextures(1, &texItem->id);
        buffer.erase( std::remove(buffer.begin(), buffer.end(), texItem), buffer.end() );
        delete texItem;
        texItem = nullptr;
    }
}



void TextureManager::finalization(){
    for(TextureItem* _iter : buffer)
        remove(_iter);
}