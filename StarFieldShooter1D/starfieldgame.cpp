#include "starfieldgame.h"

StarFieldGame::StarFieldGame()
{
    logger = Util::Logger::GetLogger();

    logger->info("Star Field Game starting...");

    manager = new OpenGL::OpenGLManager(640,400);
    manager->Init();

       logger->info("Star Field Game started.");
}

StarFieldGame::~StarFieldGame(){
    logger->info("Star Field Game shutting down...");

    delete manager;
    manager = 0;

    logger->info("Star Field Game shutdown.");
    logger = 0;
}

void StarFieldGame::Play() {
    manager->BeginScene(0.1f,0.1f,0.1f,1.0f);
    manager->EndScene();
}
