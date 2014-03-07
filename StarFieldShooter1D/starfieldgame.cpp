#include "starfieldgame.h"

StarFieldGame::StarFieldGame()
{
    logger = Util::Logger::GetLogger();

    logger->info("Star Field Game starting...");

    manager = new OpenGL::OpenGLManager(640,400);
    manager->Init();

    input = new OpenGL::InputManager();
    input->Init(manager);

    logger->info("Star Field Game started.");
}

StarFieldGame::~StarFieldGame(){
    logger->info("Star Field Game shutting down...");

    delete input;
    input = 0;
    delete manager;
    manager = 0;

    logger->info("Star Field Game shutdown.");
    logger = 0;
}

void StarFieldGame::Play() {


    logger->info("Star Field Game running...");

    bool isRunning = true;

    while (isRunning) {

        manager->BeginScene(0.1f,0.1f,0.1f,1.0f);
        manager->EndScene();

        input->PollEvents();
        isRunning = !input->IsEscapePressed();
        if (!isRunning) {
            manager->Shutdown();
        }
    }

    logger->info("Star Field Game stopped running.");
}
