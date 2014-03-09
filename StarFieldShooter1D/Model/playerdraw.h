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
    ~PlayerDraw();

    virtual void Render();

    void MoveLeft();
    void MoveRight();

private:
    PlayerProgram* program;
    PlayerData* data;
    PlayerShip* ship;
    float incX;

    Position position;
    bool isGenerateVertices;

    void MoveX(float inc);
    void GenerateVertices();

};

}
#endif // PLAYERDRAW_H
