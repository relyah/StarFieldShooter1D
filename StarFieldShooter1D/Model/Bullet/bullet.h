#ifndef BULLET_H
#define BULLET_H

#include "../position.h"

namespace Model
{

class Bullet
{
public:
    Bullet();

    void setPosition(Position p) {
        position.setX(p.getX());
        position.setY(p.getY());
    }

    Position& getPosition() {
        return position;
    }

private:
    Position position;

};
}
#endif // BULLET_H
