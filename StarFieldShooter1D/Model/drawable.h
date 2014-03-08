#ifndef DRAWABLE_H
#define DRAWABLE_H

namespace Model {
class Drawable
{
public:
    Drawable();
    virtual ~Drawable() {}

    virtual void Render()=0;
};
}
#endif // DRAWABLE_H
