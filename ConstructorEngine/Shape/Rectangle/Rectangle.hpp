#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "Shape2D.h"



class Rectangle : public Shape2D
{
public:
	Rectangle(const glm::fvec2& position = {0, 0}, const glm::fvec2& size = {1, 1});
	virtual ~Rectangle();
};



#endif // RECTANGLE_HPP