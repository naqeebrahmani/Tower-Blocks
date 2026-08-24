#include <raylib.h>
#include "game.h"
#include "movingblock.h"

#include <iostream>



Game::Game(){
    this->camera = Camera3D{{10, 10, 10}, {0, 0, 0}, {0, 1, 0}, 45.0, CAMERA_ORTHOGRAPHIC};

    this->placedblocks = new Block[this->placedblocksint];

    placedblocks[0] = Block{{0, 0, 0}, 10, 10, {100, 200, 167, 255}};

    

};

void Game::DrawPlacedBlocks(){
    for(int i = 0; i < placedblocksint; i++){
        placedblocks[i].DrawBlock();
    }
}

void Game::DrawMovingBlock(float dt){
    movingblock.DrawAndMove(dt);
}

void Game::AddBlock(){
    if(IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        this->tempplacedblocks = new Block[this->placedblocksint];

        for(int i = 0; i < (placedblocksint -1); i++){
            tempplacedblocks[i] = placedblocks[i];
        }

        delete[] placedblocks;
        
        placedblocksint ++;

        placedblocks = new Block[this->placedblocksint];

        for(int i = 0; i < (placedblocksint - 2); i++){
            placedblocks[i] = tempplacedblocks[i];
        }

        //continue here... 




    }
}