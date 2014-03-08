# cmakelists for OpenGL

cmake_minimum_required(VERSION 2.8) #specify minimum version

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_library(OpenGLLib openglmanager.cpp InputManager.cpp abstractprogram.cpp abstractdata.cpp)
