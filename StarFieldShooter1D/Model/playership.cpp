#include "playership.h"

namespace Model {
PlayerShip::PlayerShip(OpenGL::InputManager* inputManager) :
    inputManager(inputManager),
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


}
}
