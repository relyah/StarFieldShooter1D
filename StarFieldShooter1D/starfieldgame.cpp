#include "starfieldgame.h"

StarFieldGame::StarFieldGame()
{
    logger = Util::Logger::GetLogger();

    logger->info("Star Field Game starting...");
    //some comment
}

StarFieldGame::~StarFieldGame(){
    logger->info("Star Field Game ending...");
    logger = 0;
}

void StarFieldGame::Play() {

}
