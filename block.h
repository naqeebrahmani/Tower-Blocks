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

        Vector3 ReturnPosition();

        float ReturnWidth();

        float ReturnHeight(); //will always return 2 but i think i should have it because i have one for width and one for length

        float ReturnLength();

        Color ReturnColour();



};