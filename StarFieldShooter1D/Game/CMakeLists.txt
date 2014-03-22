# cmakelists for game logic
cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
-std=c++11
	)

add_library(GameLib gamelogic.cpp)

