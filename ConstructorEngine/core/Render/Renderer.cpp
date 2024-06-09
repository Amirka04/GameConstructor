#include "Renderer.h"


std::vector<RenderItem*> Renderer::buffer;
std::vector<int64_t*> Renderer::AllBufferIndex;
std::vector<int64_t*> Renderer::ShowedIndexBuffer;


void Renderer::initialization(){
}


// очистка ресурсов
void Renderer::finalization(){
    buffer.clear();
    ShowedIndexBuffer.clear();
    for(int i = 0; i < AllBufferIndex.size(); ++i)
        delete AllBufferIndex[i];
    AllBufferIndex.clear();
}


// добавление в рендер
void Renderer::add(RenderItem* rend_item){
    if(std::count(buffer.begin(), buffer.end(), rend_item) == 0) {
        buffer.push_back(rend_item);

        int64_t* i = new int64_t(static_cast<int64_t>(AllBufferIndex.size()));
        AllBufferIndex.push_back(i);
        ShowedIndexBuffer.push_back(i);

        rend_item->BufferIndex = AllBufferIndex[ AllBufferIndex.size() - 1 ];
    }
}


// удаление из рендера
void Renderer::remove(RenderItem* rend_item){
    // 1. удаляем из буффера
    buffer.erase( std::remove(buffer.begin(), buffer.end(), rend_item), buffer.end() );
    // 2. удаляем из массива отрисовка его же адрес
    ShowedIndexBuffer.erase( std::remove(ShowedIndexBuffer.begin(), ShowedIndexBuffer.end(), rend_item->BufferIndex), ShowedIndexBuffer.end() );

    // Находим позицию элемента и проходимся по всем начиная с удаляемого элемента уменьшая их на единицу
    for(int i = *rend_item->BufferIndex + 1; i < AllBufferIndex.size(); ++i){
        int64_t* ptr = AllBufferIndex[i];
        --(*ptr);
    }
    delete AllBufferIndex[*rend_item->BufferIndex];
    AllBufferIndex.erase( std::remove(AllBufferIndex.begin(), AllBufferIndex.end(), rend_item->BufferIndex), AllBufferIndex.end() );
}


// рендер
void Renderer::render(){
    for( int i = 0; i < ShowedIndexBuffer.size(); ++i)
        if(ShowedIndexBuffer[i] != nullptr)
            buffer[ *(ShowedIndexBuffer[i]) ]->render();
}


// отображение
void Renderer::MoveToShow(RenderItem* rend_item) {
    ShowedIndexBuffer[*rend_item->BufferIndex] = rend_item->BufferIndex;
}


void Renderer::MoveToHide(RenderItem* rend_item) {
    ShowedIndexBuffer[*rend_item->BufferIndex] = nullptr;
}