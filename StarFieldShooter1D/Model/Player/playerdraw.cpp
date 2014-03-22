#include "playerdraw.h"

namespace Model {


PlayerDraw::PlayerDraw(PlayerProgram* program, PlayerData* data, PlayerShip* ship) :
    program(program),
    data(data),
    ship(ship),
    incX(0.15f),
    incStepX(0.001f),
    minX(-1.0f),
    maxX(1.0f),
    isBusyMovingLeft(false),
    isBusyMovingRight(false),
    isBusyMoving(false),
    currentMoveX(0.0f),
    alreadyMovedX(0.0f)
{
    logger = Util::Logger::GetLogger();

    Position position;
    position.setX(0.0f);
    position.setY(-0.8f);

    dimensions.setPosition(position);
    dimensions.setHeight(0.05f);
    dimensions.setWidth(0.05f);

    ship->SetDrawer(this);
    isGenerateVertices = true;
}

PlayerDraw::~PlayerDraw() {
    program= NULL;
    data=NULL;
    ship=NULL;
    logger = 0;
}

void PlayerDraw::Render() {
    if (isGenerateVertices)
    {
        if (isBusyMoving)
        {
            MoveX();
        } else
        {
            isGenerateVertices = false;
        }
        GenerateVertices();
    }
    data->Render();

}


void PlayerDraw::MoveLeft() {
    //if (isBusyMovingLeft) return;
    isBusyMoving = isBusyMovingLeft = true;
    isGenerateVertices = true;
    alreadyMovedX=0.0f;
    currentMoveX = -incStepX;
}

void PlayerDraw::MoveRight() {
    //if (isBusyMovingRight) return;
    isBusyMoving = isBusyMovingRight = true;
    isGenerateVertices = true;
    alreadyMovedX=0.0f;
    currentMoveX = incStepX;
}

void PlayerDraw::MoveX()
{
    if (fabs(currentMoveX)+alreadyMovedX>incX) {
        isBusyMoving = isBusyMovingLeft = isBusyMovingRight = false;
        isGenerateVertices = false;
    }

    float newX = dimensions.getPosition().getX()+currentMoveX;
    float width = dimensions.getWidth()/2.0f;
    float newMaxX = newX+width;
    float newMinX = newX - width;

    if (newMinX <= minX || newMaxX > maxX)
    {
        isBusyMoving = isBusyMovingLeft = isBusyMovingRight = false;
        return;
    }
    dimensions.getPosition().incX(currentMoveX);
    alreadyMovedX += fabs(currentMoveX);
    isGenerateVertices = true;
}

void PlayerDraw::GenerateVertices()
{
    data->GenerateVertices(dimensions);
    data->LoadData();
}
}
