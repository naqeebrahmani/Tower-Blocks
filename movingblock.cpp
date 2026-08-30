#include <raylib.h>
#include "movingblock.h"


MovingBlock::MovingBlock(Vector3 position, float width, float length, float speed, Color colour){
    this->position = position;
    this->width = width;
    this->height = 2;
    this->length = length;

    this->speedpersecond = speed;

    this->colour = colour;
}

void MovingBlock::DrawAndMove(float dt){

    switch(this->axis){
        case X:
            switch(this->direction){
                case POSITIVE:
                    this->position.x += this->speedpersecond * dt;
                    break;
                case NEGATIVE:
                    this->position.x -= this->speedpersecond * dt;
                    break;
            }

            if(this->direction == POSITIVE && this->position.x >= 12){
                this->direction = NEGATIVE;
            }
            else if(this->direction == NEGATIVE && this->position.x <= -12){
                this->direction = POSITIVE;
            }

            break;

        case Z:
            switch(this->direction){
                case POSITIVE:
                    this->position.z += this->speedpersecond * dt;
                    break;
                case NEGATIVE:
                    this->position.z -= this->speedpersecond * dt;
                    break;
            }

            if(this->direction == POSITIVE && this->position.z >= 12){
                this->direction = NEGATIVE;
            }
            else if(this->direction == NEGATIVE && this->position.z <= -12){
                this->direction = POSITIVE;
            }

            break;
    }


    DrawCube(this->position, this->width, this->height, this->length, this->colour);
    DrawCubeWires(this->position, this->width, this->height, this->length, BLACK);

    
    
}



Vector3 MovingBlock::ReturnPosition(){
        return this->position;
    }

Color MovingBlock::ReturnColour(){
    return this->colour;
}

int MovingBlock::ReturnDirection(){
    return this->direction;
}

int MovingBlock::ReturnAxis(){
    return this->axis;
}