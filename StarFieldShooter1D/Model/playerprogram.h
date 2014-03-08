#ifndef PLAYERPROGRAM_H
#define PLAYERPROGRAM_H

#include "../OpenGL/abstractprogram.h"

#include "../Util/Logger.h"

namespace Model {

class PlayerProgram : public OpenGL::AbstractProgram
{
public:
    PlayerProgram();
    ~PlayerProgram();

private:
    void Init();

    GLuint vs, fs;
    GLint attribute_coord2d;
    log4cpp::Category* logger;
};
}

#endif // PLAYERPROGRAM_H
