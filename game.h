#pragma once

#include <raylib.h>

#include "block.h"


class Game{
    public:
    
    Camera3D camera;

    private:

    Block *placedblocks;


    public:

    Game();

    void DrawPlacedBlocks();

    

};