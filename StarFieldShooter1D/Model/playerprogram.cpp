#include "playerprogram.h"

namespace Model {
PlayerProgram::PlayerProgram()
{
    logger = Util::Logger::GetLogger();
    Init();
}

PlayerProgram::~PlayerProgram() {
    logger->info("Player program shutting down...");

    glUseProgram(0);

    glDetachShader(program, vs);
    glDetachShader(program, fs);

    glDeleteShader(fs);
    glDeleteShader(vs);

    glDeleteProgram(program);

    program = -1;
    vs = -1;
    fs = -1;

    logger->info("Player Program shutdown.");
    logger = 0;
}

void PlayerProgram::Init() {
    program = create_program("piece.glsl", "piece.glsl", vs, fs);
    if (program == 0)
        return;

    attribute_coord2d = get_attrib(program, "vertex_position");

}

}
