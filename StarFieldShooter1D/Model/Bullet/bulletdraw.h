#ifndef BULLETDRAW_H
#define BULLETDRAW_H

#include <vector>

#define GLM_MESSAGES
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include "../Player/playerprogram.h"
#include "../position.h"
#include "bullet.h"

namespace  Model
{

struct VertexDataBullet {
    glm::vec2 coord;
};

class BulletDraw
{
public:
    BulletDraw(PlayerProgram* program);
    ~BulletDraw();

    void Render(std::vector<Bullet*>& bullets);

private:
    bool IsVisible(Bullet* bullet);
    void Render(Bullet* bullet);

    PlayerProgram* program;
    GLuint vao;
    GLuint vbo;
    std::vector<VertexDataBullet> vertices;
};

}
#endif // BULLETDRAW_H
