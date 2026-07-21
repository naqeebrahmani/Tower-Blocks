#include <raylib.h>

const int WIDTH = 600;
const int HEIGHT = 1000;

const Color BGCOLOUR = {0xB5, 0x99, 0x75, 0xFF};

struct Block {
    Vector3 position;
    Vector3 size = {10, 2, 10};
    Color colour;

    Block(Vector3 position, Color colour){
        this->position = position;
        this->colour = colour;
    }
    Block(){
        return;
    }

    void Draw(){
        DrawCube(position, size.x, size.y, size.z, colour);
        DrawCubeWires(position, size.x+0.05, size.y+0.05, size.z+0.05, BLACK);
    }

};

const Block defaultblock({0, 0, 0}, {155, 155, 155, 255});

Block testblock({0, 2, 0}, {155, 155, 155, 255});

struct Game{
    int totalplacedblocks = 1;
    int totalplacedblocksinarray = 1;
    Block *placedblocks;
    Block *tempplacedblocks;

    void InitPlacedBlocksArray(){
        placedblocks = new Block[1];
        placedblocks[0] = defaultblock;
    }

    void UpdatePlacedBlocks(){
        if(totalplacedblocks > totalplacedblocksinarray){
            tempplacedblocks = new Block[totalplacedblocks];
            //temporary will be changed later on//
            Block newblock = Block({0, (2*((float)totalplacedblocks-1)), 0}, {155, 155, 155, 255});

            tempplacedblocks[(totalplacedblocks - 1)] = newblock;

            for(int i = 0; i < (totalplacedblocks -1); i++){
                tempplacedblocks[i] = placedblocks[i];
            }
            delete[] placedblocks;

            placedblocks = new Block[totalplacedblocks];

            for(int i = 0; i < totalplacedblocks; i++){
                placedblocks[i] = tempplacedblocks[i];
            }

            delete[] tempplacedblocks;

            totalplacedblocksinarray = totalplacedblocks;

        }

    }

    

    void DrawBlocks(){
        for(int i = 0; i < (totalplacedblocks); i++){
            (placedblocks[i]).Draw();
        }
    }

};

Game game;

Camera3D camera = Camera3D{{10, 10, 10}, 
                                {0, 0, 0}, 
                                {0, 1, 0},
                                45.0f,
                                CAMERA_ORTHOGRAPHIC};

int main(){
    InitWindow(WIDTH, HEIGHT, "Tower-Blocks");
    SetTargetFPS(60);


    

    while(!WindowShouldClose()){


        BeginDrawing();
        ClearBackground(BGCOLOUR);

        BeginMode3D(camera);

        game.DrawBlocks();


        EndMode3D();


        EndDrawing();

    }





    
    CloseWindow();
    return 0;
}