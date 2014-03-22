#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "../Model/Player/playership.h"
#include "../Model/Player/playerprogram.h"
#include "../Model/Player/playerdata.h"
#include "../Model/Player/playerdraw.h"
#include "../Model/Bullet/bullet.h"
#include "../Model/Bullet/bulletdraw.h"

#include "../OpenGL/InputManager.h"

namespace Game {

class GameLogic
{
public:
    GameLogic(OpenGL::InputManager* inputManager);
    ~GameLogic();

    void Process();

private:
    void ProcessPlayer();
    void ProcessPlayerBullets();

    OpenGL::InputManager* inputManager;

    Model::PlayerShip* player;
    Model::PlayerProgram* playerProgram;
    Model::PlayerData* playerData;
    Model::PlayerDraw* playerDraw;

    Model::BulletDraw* bulletDraw;
};

}

#endif // GAMELOGIC_H
