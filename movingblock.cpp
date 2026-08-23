#include <raylib.h>
#include "movingblock.h"


MovingBlock::MovingBlock(Vector3 position, float width, float length, Color colour){
    this->position = position;
    this->width = width;
    this->height = 2;
    this->length = length;


    this->colour = colour;
}

void MovingBlock::DrawAndMove(float dt){

    switch(this->axis){
        case X:
            switch(this->direction){
                case POSITIVE:
                    this->position.x += this->speedpersecond * dt;
                case NEGATIVE:
                    this->position.x -= this->speedpersecond * dt;
            }

            if(this->direction == POSITIVE && this->position.x >= 7.5){
                this->direction = NEGATIVE;
            }
            else if(this->direction == NEGATIVE && this->position.x <= 7.5){
                this->direction = POSITIVE;
            }
        case Z:
            switch(this->direction){
                case POSITIVE:
                    this->position.z += this->speedpersecond * dt;
                case NEGATIVE:
                    this->position.z -= this->speedpersecond * dt;
            }

            if(this->direction == POSITIVE && this->position.z >= 7.5){
                this->direction = NEGATIVE;
            }
            else if(this->direction == NEGATIVE && this->position.z <= 7.5){
                this->direction = POSITIVE;
            }
    }


    DrawCube(this->position, this->width, this->height, this->length, this->colour);
    DrawCubeWires(this->position, this->width, this->height, this->length, BLACK);
    
}



Vector3 MovingBlock::ReturnPosition(){
        return this->position;
    }