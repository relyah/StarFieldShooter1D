#ifndef ABSTRACTPROGRAM_H
#define ABSTRACTPROGRAM_H

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library

#include "../Util/shader_utils.h"

#include "programmable.h"

namespace OpenGL {
class AbstractProgram : Programmable
{
public:
    AbstractProgram();

    virtual void Render() {
        glUseProgram(program);
    }

protected:
    GLuint program;
};
}

#endif // ABSTRACTPROGRAM_H
