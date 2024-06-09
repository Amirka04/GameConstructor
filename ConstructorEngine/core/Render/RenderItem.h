#ifndef RENDERITEM_H
#define RENDERITEM_H

#include <iostream>
#include <stdint.h>


class RenderItem
{
public:
    RenderItem();
    virtual ~RenderItem();

    // показать объект
    void show();

    // скрыть объект
    void hide();

    virtual void render() = 0;

    int64_t* BufferIndex;   // каждый элемент знает о своём местоположении
};

#endif