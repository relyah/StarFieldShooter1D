#include "bulletdraw.h"

namespace Model
{
BulletDraw::BulletDraw(PlayerProgram *program) : program(program)
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

BulletDraw::~BulletDraw()
{

}

void BulletDraw::Render(std::vector<Bullet*> bullets)
{
    if (bullets.size()>0)
    {
        program->Render();
        glBindVertexArray(vao);
        vertices.clear();

        for (std::vector<Model::Bullet*>::iterator it = bullets.begin() ; it != bullets.end(); ++it) {
            Render(**it);
        }


        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float) * 2, &vertices[0], GL_STATIC_DRAW);

        glEnableVertexAttribArray(program->getAttribute_coord2d());

        glVertexAttribPointer(program->getAttribute_coord2d(), 2,
                              GL_FLOAT,
                              GL_FALSE, sizeof(float) * 2,  // stride
                              0);  // offset

        glDrawArrays(GL_TRIANGLES, 0, vertices.size());
    }
}

void BulletDraw::Render(Bullet& bullet)
{


    float widthX = 0.005f;
    float heightY = 0.005f;

    Position pos =  bullet.getPosition();
    float x =pos.getX();
    float y = pos.getY();

    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});

    bullet.getPosition().setY(pos.getY() + 0.001f);
}
}
