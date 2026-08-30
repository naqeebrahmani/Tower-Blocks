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
    //checking overlap

    bool runaddblockcode = false;

    //mb = movingblock
    int mbaxis = movingblock.ReturnAxis();
    int mbdirection = movingblock.ReturnDirection();

    Vector3 mbpos = movingblock.ReturnPosition();

    Vector3 lastplacedblockpos = placedblocks[placedblocksint-1].ReturnPosition();

    float lastplacedblockwidth = placedblocks[placedblocksint-1].ReturnWidth();

    float lastplacedblocklength = placedblocks[placedblocksint-1].ReturnLength();

    switch(mbaxis){
        case X:
            switch(mbdirection){

                case POSITIVE:
                    if(!(mbpos.x > (lastplacedblockpos.x + lastplacedblockwidth/2))){
                        runaddblockcode = true;
                    }

                    break;

                case NEGATIVE:
                    if(!(mbpos.x < (placedblocks[placedblocksint-1].ReturnPosition().x - lastplacedblockwidth/2))){
                        runaddblockcode = true;
                    }
                    
                    break;
            }

            break;

        case Z:
            switch(mbdirection){

                case POSITIVE:
                    if(!(mbpos.z > (lastplacedblockpos.z + lastplacedblocklength/2))){
                        runaddblockcode = true;
                    }

                    break;

                case NEGATIVE:
                    if(!(mbpos.z < (lastplacedblockpos .z - lastplacedblocklength/2))){
                        runaddblockcode = true;
                    }

                    break;
        
            }

            break;

    }

    if(runaddblockcode == true){

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

}


void Game::AdjustCamera(float speedpersecond, float deltatime){
    if(this->camera.position.y < ((this->placedblocksint-1)*2) + 10){
        this->camera.position.y += speedpersecond*deltatime;
    }
    if(this->camera.target.y < ((this->placedblocksint-1)*2)){
        this->camera.target.y += speedpersecond*deltatime;
    }

}