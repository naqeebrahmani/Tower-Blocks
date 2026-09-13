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

            if( ( (mbpos.x + lastplacedblockwidth) < (lastplacedblockpos.x + (lastplacedblockwidth*2) ) )
                && ( (mbpos.x - lastplacedblockwidth) > (lastplacedblockpos.x - (lastplacedblockwidth*2) ) ) ){

                runaddblockcode = true;

                }
                
            

            break;

        case Z:


            if( ( (mbpos.z + lastplacedblocklength) < (lastplacedblockpos.z + (lastplacedblocklength*2) ) )
                && ( (mbpos.z - lastplacedblocklength) > (lastplacedblockpos.z - (lastplacedblocklength*2) ) ) ){

                runaddblockcode = true;
                
                }

                
    

            break;

    }

    if(IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){

        if(runaddblockcode == true){

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

                //creating the newly placed block//
                

                Vector3 newlyplacedblockpos = lastplacedblockpos;
                newlyplacedblockpos.y += 2;
                float newlyplacedblockwidth = placedblocks[placedblocksint-2].ReturnWidth();
                float newlyplacedblocklength = placedblocks[placedblocksint-2].ReturnLength();
                Color tempcol = placedblocks[placedblocksint-2].ReturnColour();
                Color newlyplacedblockcol = Color{tempcol.r, tempcol.g, tempcol.b += 10, 255};
                

                //margin of error for perfect placement//
                float errorMarginPlusMinus =  0.5f;
                ////////////////////////////////////////

                switch (movingblock.ReturnAxis())
                {
                case X:{
                    
                    //if the block is "perfectly" alligned
                    if( (lastplacedblockpos.x - errorMarginPlusMinus < movingblock.ReturnPosition().x) && (movingblock.ReturnPosition().x < lastplacedblockpos.x + errorMarginPlusMinus) )
                    {
                    
                        Block newblock{newlyplacedblockpos,
                                newlyplacedblockwidth,
                                newlyplacedblocklength,
                                newlyplacedblockcol};
                                
                        placedblocks[placedblocksint - 1] = newblock;

                    }
                    ///////////////////////////////////////
                    else if( (movingblock.ReturnPosition().x + (lastplacedblockwidth/2) ) < (lastplacedblockpos.x +  (lastplacedblockwidth/2) ) ){
                        float lastPlacedBlockTopEdgeXPos = (lastplacedblockpos.x +  (lastplacedblockwidth/2) );

                        float difference = lastPlacedBlockTopEdgeXPos - (movingblock.ReturnPosition().x + (lastplacedblockwidth/2) );

                        newlyplacedblockwidth = lastplacedblockwidth - difference;

                        newlyplacedblockpos.x = lastPlacedBlockTopEdgeXPos - difference - newlyplacedblockwidth/2;

                        Block newblock{newlyplacedblockpos,
                                newlyplacedblockwidth,
                                newlyplacedblocklength,
                                newlyplacedblockcol};
                                
                        placedblocks[placedblocksint - 1] = newblock;


                    }
                                //          movingblock's bottom edge X pos             //   //          lastplacedblock's bottom edge X pos       //
                    else if( (movingblock.ReturnPosition().x - (lastplacedblockwidth/2) ) > (lastplacedblockpos.x -  (lastplacedblockwidth/2) ) ){
                        float lastPlacedBlockBottomEdgeXPos = (lastplacedblockpos.x - (lastplacedblockwidth/2) );

                        float difference = (movingblock.ReturnPosition().x - (lastplacedblockwidth/2)) - lastPlacedBlockBottomEdgeXPos;

                        newlyplacedblockwidth = lastplacedblockwidth - difference;

                        newlyplacedblockpos.x = lastPlacedBlockBottomEdgeXPos + difference + newlyplacedblockwidth/2;

                        Block newblock{newlyplacedblockpos,
                                newlyplacedblockwidth,
                                newlyplacedblocklength,
                                newlyplacedblockcol};
                                
                        placedblocks[placedblocksint - 1] = newblock;


                    }

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    break;

                    }
                
                case Z:{

                    //if the block is "perfectly" alligned
                    if((lastplacedblockpos.z - errorMarginPlusMinus < movingblock.ReturnPosition().z) && (movingblock.ReturnPosition().z < lastplacedblockpos.z + errorMarginPlusMinus))
                    {
                    
                        Block newblock{newlyplacedblockpos,
                                newlyplacedblockwidth,
                                newlyplacedblocklength,
                                newlyplacedblockcol};
                                
                        placedblocks[placedblocksint - 1] = newblock;

                    }
                    ///////////////////////////////////////
                    else if( (movingblock.ReturnPosition().z + (lastplacedblocklength/2) ) < (lastplacedblockpos.z +  (lastplacedblocklength/2) ) ){
                        float lastPlacedBlockTopEdgeZPos = (lastplacedblockpos.z +  (lastplacedblocklength/2) );

                        float difference = lastPlacedBlockTopEdgeZPos - (movingblock.ReturnPosition().z + (lastplacedblocklength/2) );

                        newlyplacedblocklength = lastplacedblocklength - difference;

                        newlyplacedblockpos.z = lastPlacedBlockTopEdgeZPos - difference - newlyplacedblocklength/2;

                        Block newblock{newlyplacedblockpos,
                                newlyplacedblockwidth,
                                newlyplacedblocklength,
                                newlyplacedblockcol};
                                
                        placedblocks[placedblocksint - 1] = newblock;


                    }
                                //          movingblock's bottom edge Z pos             //   //          lastplacedblock's bottom edge Z pos       //
                    else if( (movingblock.ReturnPosition().z - (lastplacedblocklength/2) ) > (lastplacedblockpos.z -  (lastplacedblocklength/2) ) ){
                        float lastPlacedBlockBottomEdgeZPos = (lastplacedblockpos.z - (lastplacedblocklength/2) );

                        float difference = (movingblock.ReturnPosition().z - (lastplacedblocklength/2)) - lastPlacedBlockBottomEdgeZPos;

                        newlyplacedblocklength = lastplacedblocklength - difference;

                        newlyplacedblockpos.z = lastPlacedBlockBottomEdgeZPos + difference + newlyplacedblocklength/2;

                        Block newblock{newlyplacedblockpos,
                                newlyplacedblockwidth,
                                newlyplacedblocklength,
                                newlyplacedblockcol};
                                
                        placedblocks[placedblocksint - 1] = newblock;


                    }

                    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    
                    break;
                        
                    }
                    
                }

                /*Block newblock{newlyplacedblockpos,
                        newlyplacedblockwidth,
                        newlyplacedblocklength,
                        newlyplacedblockcol};*/



                //////////////////////////////////
                
                //placedblocks[placedblocksint - 1] = newblock;

                this->movingblock = MovingBlock{{placedblocks[placedblocksint-1].ReturnPosition().x, placedblocks[placedblocksint-1].ReturnPosition().y + 2, placedblocks[placedblocksint-1].ReturnPosition().z},
                    placedblocks[placedblocksint-1].ReturnWidth(),
                    placedblocks[placedblocksint-1].ReturnLength(),
                    10, placedblocks[placedblocksint-1].ReturnColour()};



            }  
        else{
            gameover = true;
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

bool Game::ReturnGameOver(){
    return gameover;
}