#include <raylib.h>
#include "game.h"

#include <iostream>



Game::Game(){
    this->camera = Camera3D{{10, 10, 10}, {0, 0, 0}, {0, 1, 0}, 45.0, CAMERA_ORTHOGRAPHIC};

    this->placedblocks = new Block[1];

    placedblocks[0] = Block{{0, 0, 0}, 10, 10, {100, 200, 167, 255}};

};

void Game::DrawPlacedBlocks(){
    for(int i = 0; i < (sizeof(placedblocks)/sizeof(Block)); i++){
        placedblocks[i].DrawBlock();
    }
}