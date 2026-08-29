#pragma once
#include <raylib.h>

enum Axis{
    X,
    Z
};

enum Direction{
    POSITIVE,
    NEGATIVE
};



class MovingBlock{
    private:
        Vector3 position;
        float width;
        float height = 2.0;
        float length;

        int direction = GetRandomValue(POSITIVE, NEGATIVE);
        int axis = GetRandomValue(X, Z);

        float speedpersecond;

        Color colour;

    public:

        MovingBlock(Vector3 position, float width, float length, float speed, Color colour);

        void DrawAndMove(float dt);

        Vector3 ReturnPosition();

        Color ReturnColour();


};