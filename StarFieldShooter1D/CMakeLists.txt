project(StarFieldShooter1D)
cmake_minimum_required(VERSION 2.8)

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

aux_source_directory(. SRC_LIST)

include_directories("${PROJECT_SOURCE_DIR}/Util")
include_directories("${PROJECT_SOURCE_DIR}/OpenGL")

add_subdirectory(Util)
add_subdirectory(OpenGL)

add_library(StarFieldGame starfieldgame.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})


target_link_libraries(${PROJECT_NAME} Logger log4cpp pthread StarFieldGame )

configure_file(log4cpp.properties log4cpp.properties COPYONLY)

