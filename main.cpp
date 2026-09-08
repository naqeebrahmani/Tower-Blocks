#include <raylib.h>
#include "game.h"
#include "block.h"
#include "movingblock.h"

#include <iostream>




const int WIDTH = 600; const int HEIGHT = 1000;


int main(){
    InitWindow(WIDTH, HEIGHT, "game");
    Game game;

    while(!WindowShouldClose()){

        float deltatime = GetFrameTime();

        //adjusting camera//

        game.AdjustCamera(10.0, deltatime);

        ///////////////////

        BeginDrawing();
        BeginMode3D(game.camera);

        ClearBackground(WHITE);

        game.DrawPlacedBlocks();
        game.DrawMovingBlock(deltatime);

        /////////////////////
        DrawText(TextFormat("%08i", game.ReturnGameOver()), 100, 100, 20, Color {0, 0, 0, 255});
        DrawText(TextFormat("%08i", game.ReturnGameOver() ? 1 : 0), 100, 100, 100, BLACK);

        DrawText("test text", 100, 100, 20, BLACK);
        /////////////////////////////////
    

        EndMode3D();

        DrawText(TextFormat("%08i", game.ReturnGameOver()), 100, 50, 30, Color {0, 0, 0, 255});
        DrawText("test text", 100, 100, 20, BLACK);

        EndDrawing();


        //key detection stuff is below


        game.AddBlock();

        //////////////////////////////


    }



}