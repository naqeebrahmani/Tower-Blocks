#include <raylib.h>
#include <vector>

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

    void Draw(){
        DrawCube(position, size.x, size.y, size.z, colour);
        DrawCubeWires(position, size.x+0.05, size.y+0.05, size.z+0.05, BLACK);
    }

};

const Block defaultblock({0, 0, 0}, {155, 155, 155, 255});

Block testblock({0, 2, 0}, {155, 155, 155, 255});

struct Game{
    std::vector<Block> blocks = {defaultblock, testblock};
    

    void DrawBlocks(){
        for(Block block : blocks){
            block.Draw();
        }
    }

};

Game game;

int main(){
    InitWindow(WIDTH, HEIGHT, "Tower-Blocks");
    SetTargetFPS(60);

    Camera3D camera = Camera3D{{10, 10, 10}, 
                                {0, 0, 0}, 
                                {0, 1, 0},
                                45.0f,
                                CAMERA_ORTHOGRAPHIC};

    

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