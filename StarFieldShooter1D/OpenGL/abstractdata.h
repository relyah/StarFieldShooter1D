#ifndef ABSTRACTDATA_H
#define ABSTRACTDATA_H

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library

namespace OpenGL {
class AbstractData {
public:
    AbstractData();
    ~AbstractData();

    virtual void Generate();
    virtual void Bind();

protected:
    GLuint vao;
};
}

#endif // ABSTRACTDATA_H
