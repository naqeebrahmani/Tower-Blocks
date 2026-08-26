#include <raylib.h>
#include "game.h"
#include "block.h"
#include "movingblock.h"

#include <iostream>

Game game;



const int WIDTH = 600; const int HEIGHT = 1000;


int main(){
    InitWindow(WIDTH, HEIGHT, "game");

    while(!WindowShouldClose()){

        float deltatime = GetFrameTime();

        BeginDrawing();
        BeginMode3D(game.camera);

        ClearBackground(WHITE);

        game.DrawPlacedBlocks();
        game.DrawMovingBlock(deltatime);


        EndMode3D();
        EndDrawing();


        //key detection stuff is below


        game.AddBlock();

        //////////////////////////////



    }



}