# cmakelists for Model

cmake_minimum_required(VERSION 2.8) #specify minimum version

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

include_directories("Player")

add_subdirectory(Player)

file (GLOB PlayerSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  Player/*.cpp)

file (GLOB BulletSources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
 Bullet/*.cpp)


add_library(PlayerLib
dimensions.cpp position.cpp  drawable.cpp ${PlayerSources} ${BulletSources})

#Player/playership.cpp Player/playerdraw.cpp Player/playerprogram.cpp Player/playerdata.cpp)

