#include "Renderer.h"

#include "RenderItem.h"


RenderItem::RenderItem(){
    Renderer::add(this);
}


RenderItem::~RenderItem(){
    Renderer::remove(this);
}


void RenderItem::show(){
    Renderer::MoveToShow(this);
}


void RenderItem::hide(){
    Renderer::MoveToHide(this);
}