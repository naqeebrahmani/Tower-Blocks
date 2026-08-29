#pragma once

#include <raylib.h>

#include "block.h"
#include "movingblock.h"


class Game{
    public:

    Camera3D camera;

    private:

    Block *placedblocks;

    Block *tempplacedblocks;

    int placedblocksint = 1;

    bool addblock = false;

    MovingBlock movingblock{{0, 2, 0}, 10, 10, 10, {67, 67, 255, 255}};


    public:

    Game();

    void DrawPlacedBlocks();

    void DrawMovingBlock(float dt);

    void AddBlock();

    void AdjustCamera(float speedpersecond, float deltatime);

    

};