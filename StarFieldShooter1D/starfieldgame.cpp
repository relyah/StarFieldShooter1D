#include "starfieldgame.h"

StarFieldGame::StarFieldGame()
{
    logger = Util::Logger::GetLogger();

    logger->info("Star Field Game starting...");

    manager = new OpenGL::OpenGLManager(640,400);
    manager->Init();

    input = new OpenGL::InputManager();
    input->Init(manager);

    logic = new Game::GameLogic();

    playerProgram = new Model::PlayerProgram();
    player = new Model::PlayerShip(input, playerProgram);
    playerData = new Model::PlayerData(playerProgram);
    playerDraw = new Model::PlayerDraw(playerProgram,playerData,player);

    logger->info("Star Field Game started.");
}

StarFieldGame::~StarFieldGame(){
    logger->info("Star Field Game shutting down...");

    delete input;
    input = NULL;

    delete manager;
    manager = NULL;


    delete playerDraw;
    playerDraw=NULL;

    delete playerData;
    playerData=NULL;

    delete playerProgram;
    playerProgram=NULL;

    delete player;
    player = NULL;

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

        player->Process();
        player->Render();

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
