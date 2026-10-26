#include <cstdlib>
#include <raylib.h>
#include "game.h"


const int WIDTH = 600; const int HEIGHT = 1000;


int main(){

    InitWindow(WIDTH, HEIGHT, "game");

    while(!WindowShouldClose()){

        Game game;
        
        while (!game.ReturnGameOver()){

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

            if(WindowShouldClose()){
                exit(0);
            }

            //////////////////////////////
            
        }
        while(game.ReturnGameOver()){

            BeginDrawing();
            BeginMode3D(game.camera);

            ClearBackground(WHITE);

            game.DrawPlacedBlocks();

            EndMode3D();

            //Drawing the score//
            DrawText("Score:", 250, 100, 30, BLACK);
            DrawText(TextFormat("%i", game.ReturnScore()), 285, 130, 30, GRAY);
            /////////////////////

            //Restart text//
            float textwidth = MeasureText("Press Enter to retry...", 25); //284
            
            DrawText("Press Enter to retry...", (600-284)/2, 670, 25, BLACK);

            ///////////////

            EndDrawing();

            if(IsKeyPressed(KEY_ENTER)){
                game.SetGameOver(false);
            }

            if(WindowShouldClose()){
                exit(0);
            }

        }


    }



}