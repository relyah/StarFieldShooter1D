#include "position.h"
namespace  Model {


Position::Position() : x(0.0f), y(0.0f)
{
}

Position::~Position() {}

float Position::getY() const
{
    return y;
}

void Position::setY(float value)
{
    y = value;
}

float Position::getX() const
{
    return x;
}

void Position::setX(float value)
{
    x = value;
}

void Position::incX(float incX) {x += incX;}
void Position::incY(float incY) {y+=incY;}

}
