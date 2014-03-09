#ifndef DIMENSIONS_H
#define DIMENSIONS_H

#include "position.h"

namespace Model {
class Dimensions
{
public:
    Dimensions();
    ~Dimensions();

    Position& getPosition();
    void setPosition(Position &value);

    float getWidth();
    void setWidth(float value);

    float getHeight();
    void setHeight(float value);

private:
    Position position;
    float width;
    float height;

};
}
#endif // DIMENSIONS_H
