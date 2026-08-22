#include <raylib.h>
#include "game.h"
#include "block.h"

#include <iostream>

Game game;



const int WIDTH = 600; const int HEIGHT = 1000;


int main(){
    InitWindow(WIDTH, HEIGHT, "game");

    while(!WindowShouldClose()){

        BeginDrawing();
        BeginMode3D(game.camera);

        ClearBackground(WHITE);

        game.DrawPlacedBlocks();


        EndMode3D();
        EndDrawing();



    }



}