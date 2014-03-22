#ifndef STARFIELDGAME_H
#define STARFIELDGAME_H

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "Util/Logger.h"
#include "OpenGL/openglmanager.h"
#include "OpenGL/InputManager.h"


#include "Game/gamelogic.h"

class StarFieldGame
{
public:
    StarFieldGame();
    ~StarFieldGame();

    void Play();

private:

    OpenGL::OpenGLManager* manager;
    OpenGL::InputManager* input;

    Game::GameLogic* logic;



    log4cpp::Category* logger;
};

#endif // STARFIELDGAME_H
