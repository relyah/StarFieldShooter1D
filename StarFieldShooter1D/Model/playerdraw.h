#ifndef PLAYERDRAW_H
#define PLAYERDRAW_H

#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>

#include "../Util/Logger.h"

#include "playerprogram.h"
#include "playership.h"
#include "playerdata.h"
#include "drawable.h"
#include "dimensions.h"
#include <math.h>

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
    float incStepX;
    float minX;
    float maxX;
    float isBusyMovingLeft;
    float isBusyMovingRight;
    float isBusyMoving;
    float currentMoveX;
    float alreadyMovedX;
    log4cpp::Category* logger;

    Dimensions dimensions;
    bool isGenerateVertices;

    void MoveX();
    void GenerateVertices();

};

}
#endif // PLAYERDRAW_H
