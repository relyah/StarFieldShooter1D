#include "openglmanager.h"

namespace OpenGL {
OpenGLManager::OpenGLManager(int screenWidth, int screenHeight)
{
    logger = Util::Logger::GetLogger();
    logger->info("Starting OpenGLManager...");
    window = 0;
    this->screenHeight = screenHeight;
    this->screenWidth = screenWidth;
}

OpenGLManager::~OpenGLManager(){
    logger->info("Shutting down OpenGLManager...");

        logger->info("Shutdown OpenGLManager.");
    logger = 0;
}
}
