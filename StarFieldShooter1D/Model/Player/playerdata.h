#ifndef PLAYERDATA_H
#define PLAYERDATA_H

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <vector>
#include "../OpenGL/abstractdata.h"
#include "playerprogram.h"
#include "dimensions.h"

namespace Model {

struct VertexDataPlayer {
    glm::vec2 coord;
};

class PlayerData : public OpenGL::AbstractData
{
public:
    PlayerData(PlayerProgram* program);
    ~PlayerData();
    void GenerateVertices(Dimensions &dimensions);
    void LoadData();
    void Render();

private:
    PlayerProgram* program;
    GLuint vbo;
    std::vector<VertexDataPlayer> vertices;


};
}
#endif // PLAYERDATA_H
