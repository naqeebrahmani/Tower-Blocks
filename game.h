#pragma once

#include <raylib.h>

#include "block.h"


class Game{
    public:
    
    Camera3D camera;

    private:

    Block *placedblocks;

    int placedblocksint = 1;

    bool addblock = false;


    public:

    Game();

    void DrawPlacedBlocks();

    void AddBlock();

    

};