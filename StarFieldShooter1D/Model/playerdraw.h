#ifndef PLAYERDRAW_H
#define PLAYERDRAW_H

#include "playerprogram.h"
#include "playership.h"
#include "playerdata.h"
#include "drawable.h"

namespace Model{

class PlayerDraw : public Drawable
{
public:
    PlayerDraw(PlayerProgram* program, PlayerData* data, PlayerShip* ship);

    virtual void Render();

private:
    PlayerProgram* program;
    PlayerData* data;
    PlayerShip* ship;

};

}
#endif // PLAYERDRAW_H
