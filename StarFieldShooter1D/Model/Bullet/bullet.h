#ifndef BULLET_H
#define BULLET_H

#include "../position.h"
#include "../../OpenGL/abstractprogram.h"
#include <vector>

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

namespace Model
{
struct VertexDataBullet {
    glm::vec2 coord;
};

class Bullet
{
public:
    Bullet(OpenGL::AbstractProgram* program);

    void Render();

    void setPosition(Position p) {
        position.setX(p.getX());
        position.setY(p.getY());
    }

private:
    OpenGL::AbstractProgram* program;
    Position position;
    std::vector<VertexDataBullet> vertices;
};
}
#endif // BULLET_H
