#ifndef SHAPE_HPP
#define SHAPE_HPP


#include "window.h"
#include "BufferManager.h"
#include "Renderer.h"

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"


// базовые цвета для удобной передачи их в функцию
constexpr glm::vec4 BLACK = glm::vec4(0, 0, 0, 255.0f) / 255.0f;
constexpr glm::vec4 WHITE = glm::vec4(255.0f, 255.0f, 255.0f, 255.0f) / 255.0f;
constexpr glm::vec4 RED = glm::vec4(255.0f, 0, 0, 255.0f) / 255.0f;
constexpr glm::vec4 GREEN = glm::vec4(0, 255.0f, 0, 255.0f) / 255.0f;
constexpr glm::vec4 BLUE = glm::vec4(0, 0, 255.0f, 255.0f) / 255.0f;

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

class Shape2D : public RenderItem
{
public:
	Shape2D();
  	
	// инициализация, сюда передаётся массив вершил состоящая из вещественных чисел
	// благодаря этому нам не нужно через наследование создавать новые классы для отображения примитивов
	void init(const std::vector<glm::vec2>& nPtr);

	// Установка позиции на любую область экрана, УЧИТЫВАЕТСЯ СЕРЕДИНА ФИГУРЫ
	virtual void setPosition(const glm::vec2& newPos);
	virtual glm::fvec2 getPosition();

	// масштаб, увеличение фигуры В n раз
	virtual void setScale(const glm::vec2& newScale);
	virtual glm::fvec2 getScale();

	// установка и получения размера, под капотом находит масштаб по формуле ( newSize / Size )
	// установка размера на n значение
	virtual void setSize(const glm::vec2& newSize);
	virtual glm::fvec2 getSize();

	// установка и получение цвета
	virtual void setColor(const glm::vec4& newColor);
	virtual glm::vec4 getColor();

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
	virtual void render() override;

	// деструктор, в дальнейшем будет удалять VBO и EBO по индексу
	virtual ~Shape2D();

protected:
	GLuint getVBO();
	std::vector<glm::vec2> getDrawArray();

private:
	GLuint *VBO;								// VBO (Vertex Buffer Object)
	std::vector<glm::vec2> original;      		// начальные координаты фигуры без трансформации 
	std::vector<glm::vec2> data;		// массив вершин

protected:
	Transform transform;                  		// общая информация о фигуре
  	glm::vec4 color;                      		// цвет
	
};


Shape2D* create_clone(Shape2D* original);


#endif // SHAPE_HPP
