#include "Circle.hpp"

Circle::Circle(const glm::vec2& position, const glm::vec2& size)
{
    float deltaAngle = glm::radians(360.0f / this->cntVertex);

    std::vector<glm::vec2> pointer;

    for(int i = 0; i < this->cntVertex; ++i){
        pointer.push_back( glm::vec2(
                glm::cos(i * deltaAngle),
                glm::sin(i * deltaAngle) 
        ));
    }

    init(pointer);

    setPosition(position);
    setSize(size);
}


Circle::~Circle(){
    
}


// void Circle::setDetalization(int cntVertex){
//     this->cntVertex = cntVertex;
    
//     float deltaAngle = glm::radians(360.0f / this->cntVertex);

//     std::vector<glm::vec2> pointer;

//     for(int i = 0; i < this->cntVertex; ++i){
//         pointer.push_back( glm::vec2(
//                 glm::cos(i * deltaAngle),
//                 glm::sin(i * deltaAngle) 
//         ));
//     }

//     init(pointer);

//     setPosition(posShape);
//     setScale(glm::vec2(0.3, 0.3));
// }