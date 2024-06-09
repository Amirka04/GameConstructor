#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdint.h>

#include "RenderItem.h"


/*
    Renderer - класс с статическими методами и переменными
    Он нужен для отображения и хранения элементов на экране 
*/
class Renderer
{
public:

    static void initialization();
    static void finalization();

    // Добавление элемента в buffer
    static void add(RenderItem* rend_item);
    
    // Удаление элемента из buffer
    static void remove(RenderItem* rend_item);
    
    // render - статический метод отвечающий за отрисовку всех элементов что находятся в buffer и RBI
    static void render();

    // метод делает отображаемый объект невидимым
    static void MoveToHide(RenderItem* rend_item);

    // метод делаем отображаемый объект видимым
    static void MoveToShow(RenderItem* rend_item);

private:
    static std::vector<RenderItem*> buffer;     // адреса всех объектов которые могут как либо отображаться на экране
    static std::vector<int64_t*> AllBufferIndex;   // адреса всех индексов объектов
    static std::vector<int64_t*> ShowedIndexBuffer; // адреса на индексы которые будут отображены на экране
};


#endif