// header file window
#include "window.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


GLFWwindow *window::win = nullptr;
GLFWimage window::icon[1];
glm::ivec2 window::windowSize;
glm::ivec2 window::windowPos;
glm::vec2 window::offsetScale = {1, 1};



bool window::initialization(const std::string& title, int w, int h) {
  	// Инициализация glfw
	if (!glfwInit()) {
		std::cerr << "Не получилось инициализировать системы glfw" << std::endl;
		finallyzation();
		return false;
  	}


	window::win = glfwCreateWindow(w, h, title.c_str(), nullptr, nullptr);
	if (window::win == nullptr) {
		std::cerr << "Не получилось создать окно" << std::endl;
		finallyzation();
		return false;
	}


	glfwGetWindowPos(window::win, &windowPos.x, &windowPos.y);
	glfwGetWindowSize(window::win, &windowSize.x, &windowSize.y);

	glfwMakeContextCurrent(window::win);


	if (!gladLoadGL()){
		std::cerr << "Не получилось инициализировать glad" << std::endl;
		return false;
	}
	offsetScale = (w > h) ? glm::vec2( (float)h / (float)w, 1 ) : glm::vec2(1, (float)w / (float)h);


	const GLubyte * renderer = glGetString(GL_RENDERER); // получить строку для рендеринга 
	const GLubyte* version = glGetString(GL_VERSION); // версия в виде строки 
	printf ("Render: %s\n", renderer);
	printf ("OpenGL version: %s\n", version);

	// set viewport
	// glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, windowSize.x, windowSize.y);
	// glMatrixMode(GL_MODELVIEW);

	std::cout << "\nCreate main window:\n";
	std::cout << "\tWindow title:" << title << std::endl;
	std::cout << "\tWindow size: (" << windowSize.x << ", " << windowSize.y << ")" << std::endl;
	std::cout << "\tWindow pos: (" << windowPos.x << ", " << windowPos.y << ")" << std::endl;
	std::cout << "\toffset scale: (" << offsetScale.x << ", " << offsetScale.y << ")" << std::endl;
	

	return true;
}



void window::clear(const glm::vec4 &color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}


void window::setShouldCloseWindow(bool flag) {
  	glfwSetWindowShouldClose(window::win, flag);
}



void window::swapBuffers() { glfwSwapBuffers(window::win); }



bool window::isShouldCloseWindow() {
  	return glfwWindowShouldClose(window::win);
}



glm::ivec2 window::getWindowSize() { return window::windowSize; }



void window::setWindowSize(const glm::ivec2 &winSize) {
	window::windowSize = winSize;
	glViewport(0, 0, (GLsizei)windowSize.x, (GLsizei)windowSize.y);
}



glm::ivec2 window::getWindowPos() { 
	glfwGetWindowPos(window::win, &windowPos.x, &windowPos.y);
	return windowPos;
}



void window::setWindowPos(const glm::ivec2& winPos){
	windowPos = winPos;
	glfwSetWindowPos(window::win, windowPos.x, windowPos.y);
}



void window::setIcon(const std::string &iconSource){
	icon->pixels = stbi_load(iconSource.c_str(), &icon->width, &icon->height, 0, 4);

	if(icon->pixels == nullptr){
		std::cout << "Icon not found" << std::endl;
		return;
	}
	glfwSetWindowIcon(window::win, 1, icon);
	
	stbi_image_free(icon->pixels);
}


glm::vec2 window::getOffsideScale(){ return offsetScale; }


GLFWwindow* window::getMainWindow(){ return win; }


void window::finallyzation() {
	std::cout << "Очистка системы окна..." << std::endl;
	glfwTerminate();
}