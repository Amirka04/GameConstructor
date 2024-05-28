#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "Shape2D.h"



class Circle : public Shape2D
{
public:
	Circle(const glm::vec2& position = {0, 0}, const glm::vec2& size = {0, 0});
	virtual ~Circle();

	void setDetalization(int cntVertex);

protected:
	const int cntVertex = 20;
};


#endif // CIRCLE_HPP