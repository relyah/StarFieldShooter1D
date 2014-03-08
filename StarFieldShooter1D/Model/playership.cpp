#include "playership.h"

PlayerShip::PlayerShip(OpenGL::InputManager* inputManager) : inputManager(inputManager)
{
    logger = Util::Logger::GetLogger();

    logger->info("PlayerShip starting...");
}

PlayerShip::~PlayerShip()
{
    logger->info("PlayerShip shutting down...");
    logger->info("PlayerShip shutdown.");
}

void PlayerShip::Draw()
{

}

void PlayerShip::Process()
{

}
