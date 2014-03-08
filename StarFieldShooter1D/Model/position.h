#ifndef POSITION_H
#define POSITION_H

namespace Model {
class Position
{
public:
    Position();
    ~Position();

    float getX() const;
    void setX(float value);

    float getY() const;
    void setY(float value);

private:
    float x,y;
};
}
#endif // POSITION_H
