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
    isMovingLeft(false),
    isMovingRight(false),
    isBusyMoving(false),
    currentMoveX(0.0f),
    alreadyMovedX(0.0f)
{
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
    if (isBusyMoving) return;
    isBusyMoving = true;
    isGenerateVertices = true;
    alreadyMovedX=0.0f;
    currentMoveX = -incStepX;
}

void PlayerDraw::MoveRight() {
    if (isBusyMoving) return;
    isBusyMoving = true;
    isGenerateVertices = true;
    alreadyMovedX=0.0f;
    currentMoveX = incStepX;
}

void PlayerDraw::MoveX()
{
    if (fabs(currentMoveX)+alreadyMovedX>incX) {
        isBusyMoving = false;
        isGenerateVertices = false;
    }

    float newMinX = dimensions.getPosition().getX()+currentMoveX;
    float newMaxX = newMinX+dimensions.getWidth();
    if (newMinX<minX || newMaxX > maxX)
    {
        isBusyMoving = false;
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
