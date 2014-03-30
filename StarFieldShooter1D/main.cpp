//main file for the game
#include <iostream>

#include "starfieldgame.h"

using namespace std;

int main()
{
    cout << "Starting game..." << endl;

    StarFieldGame* game = new StarFieldGame();
    game->Play();

    delete game;

    cout << "Game ended." << endl;
    return 0;
}

