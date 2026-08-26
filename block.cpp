    #include "block.h"


    Block::Block(){
                return;
            }

    Block::Block(Vector3 position, float width, float length, Color colour){
        this->position = position;
        this->width = width;
        this->length = length;
        this->colour = colour;
    }

    void Block::DrawBlock(){
        DrawCube(this->position, this->width, this->height, this->length, {this->colour});
        DrawCubeWires(this->position, this->width, this->height, this->length, BLACK);
    }


    Vector3 Block::ReturnPosition(){
        return this->position;
    }

    float Block::ReturnWidth(){
        return this->width;
    }

    float Block::ReturnHeight(){
        return this->height; //should always be 2
    }

    float Block::ReturnLength(){
        return this->length;
    }