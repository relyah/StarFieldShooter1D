#include "starfieldgame.h"

StarFieldGame::StarFieldGame()
{
    logger = Util::Logger::GetLogger();

    logger->info("Star Field Game starting...");

    manager = new OpenGL::OpenGLManager(640,400);
    manager->Init();

    input = new OpenGL::InputManager();
    input->Init(manager);

    logic = new Game::GameLogic(input);

    logger->info("Star Field Game started.");
}

StarFieldGame::~StarFieldGame(){
    logger->info("Star Field Game shutting down...");

    delete input;
    input = NULL;

    delete manager;
    manager = NULL;


    delete logic;
    logic=NULL;


    logger->info("Star Field Game shutdown.");
    logger = 0;
}

void StarFieldGame::Play() {


    logger->info("Star Field Game running...");

    bool isRunning = true;

    while (isRunning) {

        manager->BeginScene(0.1f,0.1f,0.1f,1.0f);

        logic->Process();

        manager->EndScene();

        input->PollEvents();
        isRunning = !input->IsEscapePressed();
        if (!isRunning) {
            manager->Shutdown();
        }
    }

    logger->info("Star Field Game stopped running.");
}
