#ifndef OPENGLMANAGER_H
#define OPENGLMANAGER_H

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>	// TODO Auto-generated destructor stub

#include "../Util/Logger.h"

namespace OpenGL {
class OpenGLManager
{
public:
    OpenGLManager(int screenWidth, int screenHeight);
    ~OpenGLManager();

private:
    GLFWwindow* window;
    int screenWidth;
    int screenHeight;
    log4cpp::Category* logger;
};
}

#endif // OPENGLMANAGER_H
