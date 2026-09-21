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
        
        if (!game.ReturnGameOver()){
            while(!game.ReturnGameOver()){

                float deltatime = GetFrameTime();

                //adjusting camera//

                game.AdjustCamera(10.0, deltatime);

                ///////////////////

                BeginDrawing();
                BeginMode3D(game.camera);

                ClearBackground(WHITE);

                game.DrawPlacedBlocks();
                game.DrawMovingBlock(deltatime);
            

                EndMode3D();

                //DrawText(TextFormat(" Game Over: %01i", game.ReturnGameOver()), 100, 50, 30, Color {0, 0, 0, 255});
                DrawText("Score:", 250, 100, 30, BLACK);
                DrawText(TextFormat("%i", game.ReturnScore()), 285, 130, 30, GRAY);

                EndDrawing();


                //key detection stuff is below


                game.AddBlock();

                //////////////////////////////
            }
        }
        else{

            BeginDrawing();
            BeginMode3D(game.camera);

            ClearBackground(WHITE);

            game.DrawPlacedBlocks();

            EndMode3D();

            //dRAWING the score//
            DrawText("Score:", 250, 100, 30, BLACK);
            DrawText(TextFormat("%i", game.ReturnScore()), 285, 130, 30, GRAY);
            /////////////////////

            EndDrawing();



        }


    }



}