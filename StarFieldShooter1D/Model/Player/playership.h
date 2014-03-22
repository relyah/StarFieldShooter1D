#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <vector>
#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "../Util/Logger.h"
#include "../OpenGL/InputManager.h"
#include "playerprogram.h"
#include "Bullet/bullet.h"

#include "drawable.h"

namespace Model {
class PlayerShip
{
public:
    PlayerShip(OpenGL::InputManager* inputManager,  PlayerProgram* program);
    ~PlayerShip();

    void SetDrawer(Drawable* drawer) {this->drawer = drawer;}

    void Render();

    std::vector<Bullet*>& getBullets() {return bullets;}

private:
    Drawable* drawer;
    PlayerProgram* program;
    OpenGL::InputManager* inputManager;
    log4cpp::Category* logger;
    std::vector<Bullet*> bullets;
};
}
#endif // PLAYERSHIP_H
