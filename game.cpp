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

        for(int i = 0; i < (placedblocksint); i++){
            tempplacedblocks[i] = placedblocks[i];
        }

        delete[] placedblocks;
        
        placedblocksint ++;

        placedblocks = new Block[this->placedblocksint];

        for(int i = 0; i < (placedblocksint - 1); i++){
            placedblocks[i] = tempplacedblocks[i];
        }
        
        delete[] tempplacedblocks;
 
        Block newblock{movingblock.ReturnPosition(),
                placedblocks[placedblocksint-2].ReturnWidth(),
                placedblocks[placedblocksint-2].ReturnLength(),
                {movingblock.ReturnColour()}};
        
        placedblocks[placedblocksint - 1] = newblock;

        this->movingblock = MovingBlock{{placedblocks[placedblocksint-1].ReturnPosition().x, placedblocks[placedblocksint-1].ReturnPosition().y + 2, placedblocks[placedblocksint-1].ReturnPosition().z},
             placedblocks[placedblocksint-1].ReturnWidth(),
             placedblocks[placedblocksint-1].ReturnLength(),
             10, placedblocks[placedblocksint-1].ReturnColour()};

    }
}


void Game::AdjustCamera(float speedpersecond, float deltatime){
    if(this->camera.position.y < ((this->placedblocksint-1)*2) + 10){
        this->camera.position.y += speedpersecond*deltatime;
    }
    if(this->camera.target.y < ((this->placedblocksint-1)*2)){
        this->camera.target.y += speedpersecond*deltatime;
    }

}