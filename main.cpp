#include <raylib.h>
#include <vector>

const int WIDTH = 600;
const int HEIGHT = 1000;

const Color BGCOLOUR = {0xB5, 0x99, 0x75, 0xFF};

struct Block {
    Vector3 position;
    Vector3 size;
    Color colour;

    Block(Vector3 position, Vector3 size, Color colour){
        this->position = position;
        this->size = size;
        this->colour = colour;
    }

    void Draw(){
        DrawCube(position, size.x, size.y, size.z, colour);
        DrawCubeWires(position, size.x, size.y, size.z, BLACK);
    }

};

const Block defaultblock({0, 0, 0}, {10, 2, 10}, {155, 155, 155, 255});

struct Game{
    std::vector<Block> blocks = {defaultblock};
    

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