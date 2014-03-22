#include "bullet.h"

namespace Model {

Bullet::Bullet(PlayerProgram *program) : program(program)
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float) * 2, &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(program->getAttribute_coord2d());

    glVertexAttribPointer(program->getAttribute_coord2d(), 2,
                          GL_FLOAT,
                          GL_FALSE, sizeof(float) * 2,  // stride
                          0);  // offset
}

void Bullet::Render()
{
    program->Render();
    glBindVertexArray(vao);

    vertices.clear();

    float widthX = 0.005f;
    float heightY = 0.005f;

    float x = position.getX();
    float y = position.getY();

    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float) * 2, &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(program->getAttribute_coord2d());

    glVertexAttribPointer(program->getAttribute_coord2d(), 2,
                          GL_FLOAT,
                          GL_FALSE, sizeof(float) * 2,  // stride
                          0);  // offset

    glDrawArrays(GL_TRIANGLES, 0, vertices.size());

    position.setY(position.getY() + 0.001f);
}
}
