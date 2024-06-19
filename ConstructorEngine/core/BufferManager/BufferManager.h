#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H


#include "window.h"


class BufferManager
{
public:
    static GLuint* create(const void *data, std::size_t _TypeSize );
    static void updateData(GLuint* VBO, std::size_t size, const void* data);
    static void del(GLuint*& VBO);
    static void finallization();
private:
    static std::vector<GLuint*> buffer;
};


#endif
