cmake_minimum_required(VERSION 3.23)

project(TowerBlock)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(game)

target_sources(game
PRIVATE block.cpp game.cpp main.cpp movingblock.cpp)

add_library(raylib IMPORTED STATIC)

include_directories(C:/Libraries/raylib/raylib/src)

set_property(TARGET raylib PROPERTY
            IMPORTED_LOCATION "C:/Libraries/raylib/raylib/build/raylib/libraylib.a")

target_link_libraries(game
PRIVATE raylib opengl32 gdi32 winmm)