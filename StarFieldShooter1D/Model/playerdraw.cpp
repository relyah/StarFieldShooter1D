#include "playerdraw.h"

namespace Model {


PlayerDraw::PlayerDraw(PlayerProgram* program, PlayerData* data, PlayerShip* ship) : program(program), data(data), ship(ship)
{
    ship->SetDrawer(this);
    data->GenerateVertices();
    data->LoadData();
}

void PlayerDraw::Render() {
data->Render();
}

}
