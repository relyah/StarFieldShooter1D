#ifndef PLAYERDRAW_H
#define PLAYERDRAW_H

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

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

    bool isGenerateVertices;

    void MoveX();
    void GenerateVertices();

};

}
#endif // PLAYERDRAW_H
