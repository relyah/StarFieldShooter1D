#ifndef PLAYERPROGRAM_H
#define PLAYERPROGRAM_H

#include "../OpenGL/abstractprogram.h"

#include "../Util/Logger.h"
#include "../Util/shader_utils.h"

namespace Model {

class PlayerProgram : public OpenGL::AbstractProgram
{
public:
    PlayerProgram();
    ~PlayerProgram();

    //virtual void Render();

    GLint getAttribute_coord2d() const;

private:
    void Init();

    GLuint vs, fs;
    GLint attribute_coord2d;
    log4cpp::Category* logger;
};
}

#endif // PLAYERPROGRAM_H
