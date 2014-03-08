#include "openglmanager.h"

OpenGL::OpenGLManager* OpenGL::OpenGLManager::manager = 0;

namespace OpenGL {
OpenGLManager::OpenGLManager(int screenWidth, int screenHeight)
{
    logger = Util::Logger::GetLogger();
    logger->info("OpenGLManager starting...");

    window = 0;
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;

    logger->info("OpenGLManager started.");
}

OpenGLManager::~OpenGLManager(){
    logger->info("OpenGLManager shutting down...");

    glfwDestroyWindow(window);
    glfwTerminate();

    window = 0;

    logger->info("OpenGLManager shutdown.");
    logger = 0;
}

void OpenGLManager::Init(){
    logger->info("OpenGLManager initialising OpenGL...");

    OpenGLManager::manager = this;

    glfwInit();

    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);

    window = glfwCreateWindow(screenWidth, screenHeight, "Shooter", NULL,
                              NULL);
    if (!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(glfw_error_callback);
    glfwSetWindowSizeCallback(window, glfw_onResize);
    glfwMakeContextCurrent(window);
    glewInit();

    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    //glEnable(GL_CULL_FACE); // cull face
    //glCullFace(GL_FRONT); // cull back face //GL_BACK
    //glFrontFace(GL_CCW); // GL_CCW for counter clock-wise //GL_CW clockwise

    glDebugMessageCallbackARB(gl_debug_callback, this);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);

    //Controlling the volume of debug output.
    GLuint unusedIds = 0;
    //glDebugMessageControlARB(enum source, enum type, enum severity, sizei count, const uint* ids, boolean enabled).
    glDebugMessageControlARB(GL_DONT_CARE,
                             GL_DONT_CARE,
                             GL_DONT_CARE, 0, &unusedIds, true);

    logger->info("OpenGLManager initialised OpenGL.");
}

void OpenGLManager::Shutdown() {
    logger->info("OpenGLManager shutdown requested.");
    glfwSetWindowShouldClose(window, 1);
}

void OpenGLManager::BeginScene(float r, float g, float b, float a) {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLManager::EndScene() {
    glfwSwapBuffers(window);
}

void OpenGLManager::OnWindowResize(GLFWwindow* window, int width, int height) {
    screenWidth = width;
    screenHeight = height;
    glViewport(0, 0, screenWidth, screenHeight);
    std::stringstream sstm;
    sstm << "Window Resize: Width: " << width << " Height:" << height;
    logger->info(sstm.str());
}

void OpenGLManager::OnError(int error, const char* description) {
    std::stringstream sstm;
    sstm << "Error: " << error << " " << description;
    logger->error(sstm.str());
}

void OpenGLManager::OnDebugMessage(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length,
                                   const GLchar* message) {
    std::stringstream sstm;
    sstm << "source: " << source << " Type " << type << " ID: " << id << " Severity: " << severity << " Length: "
         << length << " Message: " << message;
    logger->error(sstm.str());
}

}
