#include "dimensions.h"

namespace Model {
Dimensions::Dimensions()
{
}

Dimensions::~Dimensions() {

}

float Dimensions::getWidth()
{
    return width;
}

void Dimensions::setWidth(float value)
{
    width = value;
}
Position& Dimensions::getPosition()
{
    return position;
}

void Dimensions::setPosition(Position &value)
{
    position = value;
}
float Dimensions::getHeight()
{
    return height;
}

void Dimensions::setHeight(float value)
{
    height = value;
}



}
