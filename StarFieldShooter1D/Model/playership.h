#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "../Util/Logger.h"
#include "../OpenGL/InputManager.h"

class PlayerShip
{
public:
    PlayerShip(OpenGL::InputManager* inputManager);
    ~PlayerShip();

    void Draw();

    void Process();

private:
    OpenGL::InputManager* inputManager;
    log4cpp::Category* logger;
};

#endif // PLAYERSHIP_H
