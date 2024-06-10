#include "Renderer.h"


std::vector<RenderItem*> Renderer::buffer;
std::vector<RenderItem*> Renderer::render_buffer;





void Renderer::initialization(){
}


// очистка ресурсов
void Renderer::finalization(){
    buffer.clear();
    render_buffer.clear();
}


// добавление в рендер
void Renderer::add(RenderItem* rend_item){
    buffer.push_back(rend_item);
    render_buffer.push_back(rend_item);
}


// удаление из рендера
void Renderer::remove(RenderItem* rend_item){
    buffer.erase( std::remove(buffer.begin(), buffer.end(), rend_item), buffer.end() );
    render_buffer.erase( std::remove(render_buffer.begin(), render_buffer.end(), rend_item), render_buffer.end() );
}


// рендер
void Renderer::render(){
    for(RenderItem* i : render_buffer)
        if(i != nullptr)
            i->render();
}


// отображение
void Renderer::MoveToShow(RenderItem* rend_item) {
    int index = std::distance(buffer.begin(), std::find(buffer.begin(), buffer.end(), rend_item));
    render_buffer[index] = rend_item;    
}


void Renderer::MoveToHide(RenderItem* rend_item) {
    int index = std::distance(buffer.begin(), std::find(buffer.begin(), buffer.end(), rend_item));
    render_buffer[index] = nullptr;
}