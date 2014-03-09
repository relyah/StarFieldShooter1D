#include "playerdraw.h"

namespace Model {


PlayerDraw::PlayerDraw(PlayerProgram* program, PlayerData* data, PlayerShip* ship) :
    program(program),
    data(data),
    ship(ship),
    incX(0.05f)
{
    position.setX(0.0f);
    position.setY(-0.8f);

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
        isGenerateVertices = false;
        GenerateVertices();
    }
    data->Render();
}


void PlayerDraw::MoveLeft() {
    MoveX(-incX);
}

void PlayerDraw::MoveRight() {
    MoveX(incX);
}

void PlayerDraw::MoveX(float inc)
{
    position.incX(inc);
    isGenerateVertices = true;
}

void PlayerDraw::GenerateVertices()
{
    data->GenerateVertices(position);
    data->LoadData();
}
}
