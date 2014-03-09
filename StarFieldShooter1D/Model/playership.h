#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "../Util/Logger.h"
#include "../OpenGL/InputManager.h"

#include "drawable.h"

namespace Model {
class PlayerShip
{
public:
    PlayerShip(OpenGL::InputManager* inputManager);
    ~PlayerShip();

    void SetDrawer(Drawable* drawer) {this->drawer = drawer;}

    void Render();

    void Process();

private:
    Drawable* drawer;
    OpenGL::InputManager* inputManager;
    log4cpp::Category* logger;
};
}
#endif // PLAYERSHIP_H
