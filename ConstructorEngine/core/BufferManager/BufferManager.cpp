#include "BufferManager.h"


std::vector<GLuint*> BufferManager::buffer;



GLuint* BufferManager::create(const void* data, std::size_t size) {
	GLuint* VBO = new GLuint{0};
	glGenBuffers(1, VBO);

	// создание вертекста буффера вершин
    glBindBuffer(GL_ARRAY_BUFFER, *VBO);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
		buffer.push_back(VBO);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

	return VBO;
}



void BufferManager::updateData(GLuint* VBO, std::size_t size, const void* data){
	glBindBuffer(GL_ARRAY_BUFFER, *VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}



void BufferManager::del(GLuint* VBO){
	if( std::count(buffer.begin(), buffer.end(), VBO) != 0 ){
		// сначало удалим из Буффера памяти видеокарты
		glDeleteBuffers(1, VBO);
		// потом удалим данных из массива
		buffer.erase( std::remove(buffer.begin(), buffer.end(), VBO), buffer.end() );

		delete VBO;
	}
}



void BufferManager::finallization(){
	for( GLuint* _iterItem : buffer )
		del(_iterItem);
}