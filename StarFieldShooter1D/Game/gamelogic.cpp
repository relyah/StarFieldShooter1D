#include "gamelogic.h"

namespace Game {

GameLogic::GameLogic(OpenGL::InputManager* input) : inputManager(input)
{
    playerProgram = new Model::PlayerProgram();
    player = new Model::PlayerShip(input, playerProgram);
    playerData = new Model::PlayerData(playerProgram);
    playerDraw = new Model::PlayerDraw(playerProgram,playerData,player);
    bulletDraw = new Model::BulletDraw(playerProgram);
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

    delete bulletDraw;
    bulletDraw = NULL;
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
        Model::Bullet* b = new Model::Bullet();
        Model::Position bpos(playerDraw->getDimensions().getPosition());
        bpos.incY(+0.1f);
        b->setPosition(bpos);
        player->getBullets().push_back(b); //draw bullets
    }

    std::vector<Model::Bullet*> bullets = player->getBullets();

    std::cout << "bullets address(1): " << &bullets << std::endl;
    for (std::vector<Model::Bullet*>::iterator it = bullets.begin() ; it != bullets.end(); ++it) {
        std::cout << (*it)->getPosition().getY() << std::endl;
        //(*it)->getPosition().setY(0.0f);
        std::cout << &(*it) << " "<< (*it)->getPosition().getY() << std::endl;
    }

    bulletDraw->Render(bullets);

    for (std::vector<Model::Bullet*>::iterator it = bullets.begin() ; it != bullets.end(); ++it) {
        //(*it)->getPosition().setY(-0.5f);
        std::cout << &(*it) << " "<< (*it)->getPosition().getY() << std::endl;
    }
}

}
