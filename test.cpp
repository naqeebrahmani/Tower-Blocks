#include <raylib.h>
#include "game.h"

Game game;

const int WIDTH = 600; const int HEIGHT = 1000;


int main(){
    InitWindow(WIDTH, HEIGHT, "game");

    while(!WindowShouldClose()){


        BeginDrawing();
        BeginMode3D(game.camera);

        ClearBackground(WHITE);

        DrawCube({0, 0, 0}, 10, 2, 10, BLACK);


        EndMode3D();
        EndDrawing();



    }



}