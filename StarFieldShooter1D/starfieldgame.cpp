#include "starfieldgame.h"

StarFieldGame::StarFieldGame()
{
    logger = Util::Logger::GetLogger();

    logger->info("Star Field Game starting...");
}

StarFieldGame::~StarFieldGame(){
    logger->info("Star Field Game ending...");
    logger = 0;
}

void StarFieldGame::Play() {

}
