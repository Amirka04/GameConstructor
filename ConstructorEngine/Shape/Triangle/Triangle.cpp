#include "Triangle.hpp"

Triangle::Triangle(const glm::vec2& d_position, const glm::vec2& d_size)
{
    init(
        std::vector<glm::vec2>{
            {0,  1},
            {1, -1},
            {-1,-1}
        }
    );

    setPosition(d_position);
    setSize(d_size);
}



Triangle::~Triangle(){

}