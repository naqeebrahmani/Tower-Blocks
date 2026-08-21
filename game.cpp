#include <raylib.h>
#include "game.h"
#include <iostream>


Game::Game(){
    this->camera = Camera3D{{10, 10, 10}, {0, 0, 0}, {0, 1, 0}, 45.0, CAMERA_ORTHOGRAPHIC};
};
