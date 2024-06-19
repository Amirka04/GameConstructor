#include "TextureManager.h"


#include "stb_image.h"


// инициализация нужных нам элементов, например текстурные координаты
Texture::Texture(){
    id = 0;
    defaultUV = uv = {
        {0, 0},
        {0, 1},
        {1, 1},
        {1, 0},
    };
}


// подключение текстуры
void Texture::bind(){
    glEnable(BIT_TEXTURE);
    glBindTexture(BIT_TEXTURE, id);

    // загрузка спрайта и координат отображения на фигуре
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
        glTexCoordPointer(2, GL_FLOAT, 0, &uv.front());
    glDisableClientState(GL_VERTEX_ARRAY);
}


// отключение текстуры
void Texture::unbind(){
    glBindTexture(BIT_TEXTURE, 0);
}

// установка координат для uv текстуры, это потребуется
void Texture::setUV(std::vector<glm::vec2> newUV){
    uv = newUV;
}


std::map<std::string, int64_t> TextureManager::TextureCount;
std::map<std::string, Texture2D> TextureManager::TextureID;



void TextureManager::load(Texture& texture, const std::string& path){
    int n;
    unsigned char* data = stbi_load(path.c_str(), &texture.width, &texture.height, &n, 0);
    
    if(!data)
        std::cerr << "TextureManager::load -> Error not found image file: " << path << std::endl;

    if(std::count_if(TextureID.begin(), TextureID.end(), [path](std::pair<std::string, Texture2D> data){ return data.first == path; }) == 0) {
        TextureID[path] = 0;
        glGenTextures(1, &TextureID[path]);
        glBindTexture(BIT_TEXTURE, TextureID[path]);
            glTexParameteri(BIT_TEXTURE, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(BIT_TEXTURE, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(BIT_TEXTURE, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
            glTexParameteri(BIT_TEXTURE, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexImage2D(BIT_TEXTURE, 0, GL_RGBA, texture.width, texture.height, 0, n == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
        glBindTexture(BIT_TEXTURE, 0);
    }
    ++TextureCount[path];

    texture.id = TextureID[path];
    texture.TextureName = path;
}



void TextureManager::remove(Texture& texture){
    if (std::count_if(TextureID.begin(), TextureID.end(), [texture](std::pair<std::string, Texture2D> data){ return data.first == texture.TextureName; })){
        texture.id = 0;

        for(auto i : TextureCount)
            std::cout << i.first << " -> " << i.second << std::endl;
        
        std::cout << --TextureCount[texture.TextureName] << std::endl;

        if( --TextureCount[texture.TextureName] == 0 ){
            glDeleteTextures(1, &TextureID[texture.TextureName]);
            TextureCount.erase(texture.TextureName);
            TextureID.erase(texture.TextureName);
        }
    }
}



void TextureManager::reloadTexture(Texture& texture, const std::string& path){
    if (std::count_if(TextureID.begin(), TextureID.end(), [texture](std::pair<std::string, Texture2D> data){ return data.first == texture.TextureName; }) == 0){
        load(texture, path);
        return;
    }
    
    remove(texture);
    load(texture, path);
}


void TextureManager::finalization(){
    for(auto iter : TextureID)
        glDeleteTextures(1, &iter.second);

    TextureID.clear();
    TextureCount.clear();
}