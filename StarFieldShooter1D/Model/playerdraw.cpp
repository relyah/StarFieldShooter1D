#include "playerdraw.h"

namespace Model {


PlayerDraw::PlayerDraw(PlayerProgram* program, PlayerData* data, PlayerShip* ship) : program(program), data(data), ship(ship)
{
    ship->SetDrawer(this);
    data->GenerateVertices();
    data->LoadData();
}

PlayerDraw::~PlayerDraw() {
    program= NULL;
    data=NULL;
    ship=NULL;
}

void PlayerDraw::Render() {
    data->Render();
}

}
