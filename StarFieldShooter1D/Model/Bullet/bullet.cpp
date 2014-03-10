#include "bullet.h"

namespace Model {

Bullet::Bullet(OpenGL::AbstractProgram *program) : program(program)
{
}

void Bullet::Render()
{
    vertices.clear();

    float widthX = 0.5f;
    float heightY = 0.5f;

    float x = position.getX();
    float y = position.getY();

    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});

    program->Render();
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
}
