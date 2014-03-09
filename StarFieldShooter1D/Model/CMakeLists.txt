# cmakelists for Model

cmake_minimum_required(VERSION 2.8) #specify minimum version

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

add_library(PlayerLib
dimensions.cpp position.cpp  drawable.cpp playership.cpp playerdraw.cpp playerprogram.cpp playerdata.cpp)

