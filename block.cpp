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