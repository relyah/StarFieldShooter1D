# cmakelists for util

cmake_minimum_required(VERSION 2.8) #specify minimum version

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_library(Logger Logger.cpp)
add_library(shader_utils shader_utils.cpp)
