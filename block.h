#pragma once

#include <raylib.h>

class Block{
    private:
    
        Vector3 position;
        float width;
        float height = 2.0;
        float length;

        Color colour;

    
    public:

        Block();

        Block(Vector3 position, float width, float length, Color colour);

        void DrawBlock();
};