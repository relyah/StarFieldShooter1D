#ifndef OPENGLMANAGER_H
#define OPENGLMANAGER_H

#include <GL/glew.h> // include GLEW and new version of GL on Windows
#include <GLFW/glfw3.h> // GLFW helper library


#include "../Util/Logger.h"

namespace OpenGL {
class OpenGLManager
{
public:
    OpenGLManager(int screenWidth, int screenHeight);
    ~OpenGLManager();

    void Init();
    void Shutdown();

    void BeginScene(float r, float g, float b, float a);
    void EndScene();

    GLFWwindow* GetWindow() {return window;}

private:
    void OnWindowResize(GLFWwindow* window, int width, int height);
    void OnError(int error, const char* description);
    void OnDebugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message);

    GLFWwindow* window;
    int screenWidth;
    int screenHeight;
    log4cpp::Category* logger;

    //static code for event handling --------------------------------
    static void glfw_onResize(GLFWwindow* window, int w, int h) {
        manager->OnWindowResize(window, w, h);
    }

    static void glfw_error_callback(int error, const char* description) {
        manager->OnError(error, description);
    }

    static void APIENTRY gl_debug_callback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
            const GLchar* message, GLvoid* userParam) {
        reinterpret_cast<OpenGLManager *>(userParam)->OnDebugMessage(source, type, id, severity, length, message);
    }

    static OpenGL::OpenGLManager* manager;
    //---------------------------------------------------------------
};
}

#endif // OPENGLMANAGER_H
