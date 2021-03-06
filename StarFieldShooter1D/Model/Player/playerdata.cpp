#include "playerdata.h"

namespace Model {


PlayerData::PlayerData(PlayerProgram *program) : program(program)
{
    Generate();
}
PlayerData::~PlayerData()
{
    program = NULL;
}

void PlayerData::GenerateVertices(Dimensions &dimensions)
{
    float widthX = dimensions.getWidth()/2.0f;
    float heightY = dimensions.getHeight()/2.0f;
    float x= dimensions.getPosition().getX();
    float y=dimensions.getPosition().getY();

    vertices.clear();

    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,heightY+y)});
    vertices.push_back({glm::vec2(-widthX+x,-heightY+y)});
    vertices.push_back({glm::vec2(widthX+x,heightY+y)});
}

void PlayerData::LoadData()
{
    Bind();

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float) * 2, &vertices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(program->getAttribute_coord2d());

    glVertexAttribPointer(program->getAttribute_coord2d(), 2,
                          GL_FLOAT,
                          GL_FALSE, sizeof(float) * 2,  // stride
                          0);  // offset
}

void PlayerData::Render()
{
    program->Render();
    Bind();
    glDrawArrays(GL_TRIANGLES, 0, vertices.size());
}
}
