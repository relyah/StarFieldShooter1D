#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "dimensions.h"

namespace Model {
class Drawable
{
public:
    Drawable();
    virtual ~Drawable() {}

    virtual void Render()=0;
    virtual void MoveLeft()=0;
    virtual void MoveRight()=0;

    Dimensions& getDimensions() {return dimensions;}

protected:
    Dimensions dimensions;
};
}
#endif // DRAWABLE_H
