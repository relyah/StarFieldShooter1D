#ifndef PROGRAMMABLE_H
#define PROGRAMMABLE_H

namespace OpenGL {
class Programmable {
public:
    virtual void Render()=0;
    virtual ~Programmable() {}
};
}
#endif // PROGRAMMABLE_H
