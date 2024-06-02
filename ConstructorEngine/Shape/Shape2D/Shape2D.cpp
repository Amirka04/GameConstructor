#include "Shape2D.h"



Shape2D::Shape2D(){
    transform.pos = glm::vec2(0.0f);
    transform.size = glm::vec2(1.0f);
    transform.scale = glm::vec2(1.0f);
    transform.angle = 0.0f;
    color = glm::vec3(1.0f);
}



// инициализация
void Shape2D::init(const std::vector<glm::fvec2>& nPtr){
    // т.к. мы не знаем что за фигура будет рисоваться, то будем просто принимать массив вершин для гибкости
    // а если присмотреться к рендеру, то обычно мы присуем полигон что позволяет нам рисовать любой примитив
    original = data = nPtr;
    VBO = BufferManager::create(&data.front(), sizeof(glm::vec2) * data.size());
}



// установка позиции ( проверено )
void Shape2D::setPosition(const glm::vec2& newPos){
    glm::vec2 offset = newPos - transform.pos;
    glm::mat4 translateMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(offset, 1.0f));
    for(glm::vec2& vertex : data)
        vertex = glm::vec2(translateMatrix * glm::vec4(vertex, 1.0f, 1.0f));
    transform.pos = newPos;
    BufferManager::updateData(VBO, sizeof(glm::vec2) * data.size(), &data.front());
}



// получение позиции ( проверено )
glm::fvec2 Shape2D::getPosition(){
    return transform.pos;
}



// установка масштаба
void Shape2D::setScale(const glm::fvec2& newScale){    
    glm::mat4 scaleModel = glm::scale(glm::mat4(1.0f), glm::vec3(newScale, 1.0f));
    glm::vec2 startPosition = transform.pos;
    setPosition(CenterViewport);

    for(glm::vec2 &vertex : data)
        vertex = glm::vec2(scaleModel * glm::vec4(vertex, 1.0f, 1.0f));

    setPosition(startPosition);
    transform.scale = newScale;

    BufferManager::updateData(VBO, sizeof(glm::vec2) * data.size(), &data.front());

}



// установка масштаб
glm::fvec2 Shape2D::getScale(){
    return transform.pos;
}



// установка размера в пикселях
void Shape2D::setSize(const glm::fvec2 &new_size){
    // установка нового масштаба
    this->setScale(new_size / transform.size);
    transform.size = new_size;
}



// получение размера в пикселях
glm::fvec2 Shape2D::getSize(){
    return transform.size;
}



// установка цвета
void Shape2D::setColor(const glm::fvec3& newColor){
    color = newColor;
}



// получение цвета
glm::fvec3 Shape2D::getColor(){
    return color;
}



// Установка поворота фигуры
void Shape2D::setRotate(float angle){
    // матрица вращения
    glm::mat4 rotateModel = glm::rotate(glm::mat4(1.0f), glm::radians(angle - transform.angle), glm::vec3(0.0f, 0.0f, 1.0f));
    glm::vec2 startPosition = transform.pos;
    setPosition(CenterViewport);
    for(glm::vec2& vert : data)
        vert = glm::vec2(rotateModel * glm::vec4(vert, 1.0f, 1.0f));
    setPosition(startPosition);
    transform.angle = angle;

    BufferManager::updateData(VBO, sizeof(glm::vec2) * data.size(), &data.front());
}


// получение поворота
float Shape2D::getRotate(){
    return transform.angle;
}


// установка и получение центра повотора
void Shape2D::setPosRotate(const glm::vec2& newPosRotate){
    // posRotate = glm::vec2(0.0f);
}

glm::vec2 Shape2D::getPosRotate(){ return glm::vec2(0.0f); }


// получение исходных координат каждой точки без трансформаций
std::vector<glm::vec2> Shape2D::getOriginalPointer(){ return original; }


// рендер
void Shape2D::render(){
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
        glVertexPointer(2, GL_FLOAT, 0, nullptr);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnableClientState(GL_VERTEX_ARRAY);
        glColor3f(color.r, color.g, color.b);
        glDrawArrays(GL_POLYGON, 0, data.size());
    glDisableClientState(GL_VERTEX_ARRAY);
}


Shape2D::~Shape2D(){
    // удаление из буффера
    BufferManager::del(VBO);
}



Shape2D* create_clone(Shape2D* original){
    Shape2D* clone = new Shape2D;
    clone->init(original->getOriginalPointer());
    clone->setPosition(original->getPosition());
    clone->setSize(original->getSize());
    clone->setColor(original->getColor());
    clone->setRotate(original->getRotate());
    clone->setPosRotate(original->getPosRotate());

    return clone;
}
