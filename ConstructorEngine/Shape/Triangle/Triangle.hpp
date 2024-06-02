#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP


#include "Shape2D.h"


class Triangle : public Shape2D
{
public:
	Triangle(const glm::vec2& position = {0, 0}, const glm::vec2& size = {1, 1});
	virtual ~Triangle();
};


#endif // TRIANGLE_HPP