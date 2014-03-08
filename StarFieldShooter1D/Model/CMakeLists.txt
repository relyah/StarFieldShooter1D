# cmakelists for Model

cmake_minimum_required(VERSION 2.8) #specify minimum version

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_library(Position position.cpp)
add_library(Drawable drawable.cpp)
add_library(PlayerShip playership.cpp)
add_library(PlayerDraw playerdraw.cpp)
add_library(PlayerProgram playerprogram.cpp)
add_library(PlayerData playerdata.cpp)

