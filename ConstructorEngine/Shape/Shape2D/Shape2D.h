#ifndef SHAPE_HPP
#define SHAPE_HPP


#include "window.h"
#include "BufferManager.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


// базовые цвета для удобной передачи их в функцию
const glm::fvec3 BLACK = glm::fvec3(0, 0, 0) / 255.0f;
const glm::fvec3 WHITE = glm::fvec3(255.0f, 255.0f, 255.0f) / 255.0f;
const glm::fvec3 RED = glm::fvec3(255.0f, 0, 0) / 255.0f;
const glm::fvec3 GREEN = glm::fvec3(0, 255.0f, 0) / 255.0f;
const glm::fvec3 BLUE = glm::fvec3(0, 0, 255.0f) / 255.0f;


const glm::vec2 CenterViewport{0.0f};


struct Transform{
	glm::vec2 pos;
	glm::vec2 size;
	glm::vec2 scale;
	float angle;
};


/*
	Shape2D - базовый класс для рисования, манипулирования любыми примитивами
	Для рисования нужно объязательно инициализировать массив вершин, центр и размер определяться автоматически
	Рисование осуществляется с помощью ключа opengl, GL_POLYGON, по этому, можно передать неограниченное ( для вашей оперативной памяти ) данные
*/

class Shape2D
{
public:
	Shape2D();
  	
	// инициализация, сюда передаётся массив вершил состоящая из вещественных чисел
	// благодаря этому нам не нужно через наследование создавать новые классы для отображения примитивов
	void init(const std::vector<glm::fvec2>& nPtr);

	// Установка позиции на любую область экрана, УЧИТЫВАЕТСЯ СЕРЕДИНА ФИГУРЫ
	virtual void setPosition(const glm::fvec2& newPos);
	virtual glm::fvec2 getPosition();

	// масштаб, увеличение фигуры В n раз
	virtual void setScale(const glm::fvec2& newScale);
	virtual glm::fvec2 getScale();

	// установка и получения размера, под капотом находит масштаб по формуле ( newSize / Size )
	// установка размера на n значение
	virtual void setSize(const glm::fvec2& newSize);
	virtual glm::fvec2 getSize();

	// установка и получение цвета
	virtual void setColor(const glm::fvec3& newColor);
	virtual glm::fvec3 getColor();

	// установка и получение цвета
	virtual void setRotate(float angle);
	virtual float getRotate();

	// установка и получение центра поворота
	virtual void setPosRotate(const glm::vec2& newPosRotate);
	virtual glm::vec2 getPosRotate();

	// получение начальных координат всех точек
	std::vector<glm::vec2> getOriginalPointer();

	// рендер, по сути рендеру всё равно что рисовать, т.к. мы рисуем с помощью ключевого слова GL_POLYGON, которая отображает фигуру с не ограниченным
	// кол-вом точек
	virtual void render();

	// деструктор, в дальнейшем будет удалять VBO и EBO по индексу
	virtual ~Shape2D();


private:
	GLuint *VBO;								// VBO (Vertex Buffer Object)
	std::vector<glm::vec2> original;      		// начальные координаты фигуры без трансформации 
	std::vector<glm::vec2> data;		// массив вершин

protected:
	Transform transform;                  		// общая информация о фигуре
  	glm::vec3 color;                      		// цвет
};


Shape2D* create_clone(Shape2D* original);


#endif // SHAPE_HPP
