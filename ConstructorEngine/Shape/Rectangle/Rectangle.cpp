#include "Rectangle.hpp"



Rectangle::Rectangle(const glm::fvec2& d_position, const glm::fvec2& d_size)
{
    init(
        std::vector<glm::fvec2>{
            {1, 1},
            {1, -1},
            {-1, -1},
            {-1, 1}
        }
    );

    setPosition(d_position);
    setSize(d_size);
}



Rectangle::~Rectangle(){   
}