#include <raylib.h>

enum Axis{
    X,
    Y
};

enum Direction{
    LEFT,
    RIGHT
};


class MovingBlock{
    private:
        Vector3 position;
        float width;
        float height = 2.0;
        float length;

        int direction = GetRandomValue(LEFT, RIGHT);
        int axis = GetRandomValue(X, Y);

        float xcord;
        float zcord;

        Color colour;




};