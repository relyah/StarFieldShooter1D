#ifndef POSITION_H
#define POSITION_H

#include <iostream>

namespace Model {
class Position
{
public:
    Position();
    ~Position();

//    Position(Position& copy)
//    {
//        std::cout << "copy" << std::endl;
//        this->x = copy.x;
//        this->y = copy.y;
//    }

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

    void incX(float incX);
    void incY(float incY);

private:
    float x,y;
};
}
#endif // POSITION_H
