#include "abstractdata.h"

namespace OpenGL{

AbstractData::AbstractData() :vao(-1) {}


AbstractData::~AbstractData()
{
    if (vao!=-1)
    {
        glDeleteVertexArrays(1,&vao);
    }
}

void AbstractData::Generate() {
    glGenVertexArrays(1, &vao);
}

void AbstractData::Bind() {
    if (vao!=-1) {
        glBindVertexArray(vao);
    }
}

}
