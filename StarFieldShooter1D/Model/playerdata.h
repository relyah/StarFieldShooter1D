#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#include <vector>
#include "../OpenGL/abstractdata.h"
#include "playerprogram.h"

namespace Model {

struct VertexData {
    glm::vec2 coord;
};

class PlayerData : public OpenGL::AbstractData
{
public:
    PlayerData(PlayerProgram* program);
    void GenerateVertices();
    void LoadData();
    void Render();

private:
    PlayerProgram* program;
    GLuint vbo;
    std::vector<VertexData> vertices;


};
}
#endif // PLAYERDATA_H
