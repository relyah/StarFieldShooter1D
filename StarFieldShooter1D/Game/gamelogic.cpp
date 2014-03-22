#include "gamelogic.h"

namespace Game {

GameLogic::GameLogic(OpenGL::InputManager* input) : inputManager(input)
{
    playerProgram = new Model::PlayerProgram();
    player = new Model::PlayerShip(input, playerProgram);
    playerData = new Model::PlayerData(playerProgram);
    playerDraw = new Model::PlayerDraw(playerProgram,playerData,player);

}

GameLogic::~GameLogic()
{
    inputManager =NULL;

    delete playerDraw;
    playerDraw=NULL;

    delete playerData;
    playerData=NULL;

    delete playerProgram;
    playerProgram=NULL;

    delete player;
    player = NULL;
}

void GameLogic::Process()
{
    ProcessPlayer();
    ProcessPlayerBullets();

    player->Render();

}

void GameLogic::ProcessPlayer()
{
    if (inputManager->IsLeftPressed())
    {
        playerDraw->MoveLeft();
    } else if (inputManager->IsRightPressed())
    {
        playerDraw->MoveRight();
    }
}
void GameLogic::ProcessPlayerBullets()
{
    if (inputManager->IsSpacebarPressed())
    {
        //shoot
        Model::Bullet* b = new Model::Bullet(playerProgram);
        Model::Position bpos(playerDraw->getDimensions().getPosition());
        bpos.incY(+0.1f);
        b->setPosition(bpos);
        player->getBullets().push_back(b); //draw bullets
    }
}

}
