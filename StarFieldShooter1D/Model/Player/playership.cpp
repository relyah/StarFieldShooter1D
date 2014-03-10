#include "playership.h"

namespace Model {
PlayerShip::PlayerShip(OpenGL::InputManager* inputManager,PlayerProgram* program) :
    inputManager(inputManager),
    program(program),
    drawer(NULL)
{
    logger = Util::Logger::GetLogger();

    logger->info("PlayerShip starting...");
}

PlayerShip::~PlayerShip()
{
    logger->info("PlayerShip shutting down...");
    inputManager = NULL;
    drawer=NULL;

    if (bullets.size()>0)
    {
        for (std::vector<Bullet*>::iterator it = bullets.begin() ; it != bullets.end(); ++it) {
            delete *it;
        }
    }

    logger->info("PlayerShip shutdown.");
    logger=NULL;
}

void PlayerShip::Render()
{
    if (drawer!=NULL)
    {
        drawer->Render();
    }
}

void PlayerShip::Process()
{
    if (inputManager->IsLeftPressed())
    {
        drawer->MoveLeft();
    } else if (inputManager->IsRightPressed())
    {
        drawer->MoveRight();
    }

    if (inputManager->IsSpacebarPressed())
    {
        //shoot
        Bullet* b = new Bullet(program);
        Position bpos(drawer->getDimensions().getPosition());
        bpos.incY(+0.1f);
        b->setPosition(bpos);
        bullets.push_back(b);
    }
}
}
