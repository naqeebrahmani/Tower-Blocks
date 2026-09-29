#include "button.h"

#include <raylib.h>
#include <iostream>


Button::Button(float x, float y, float width, float height, std::string text, bool visible){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->text = text;
    this->visible = visible;
}

void Button::displayAndPressCheck(){
    if(visible){
        if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x, y, width, height}) && IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
            DrawRectangle(x, y, width - 5, height - 5, GREY);
            DrawText(text.c_str(), x + 5, y + 5, 20, BLACK);
        }
        else{
        DrawRectangle(x, y, width, height, GREY);
        DrawText(text.c_str(), x + 10, y + 10, 20, BLACK);
        }

        if(CheckCollisionPointRec(GetMousePosition(), Rectangle{x, y, width, height}) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)){
            if(pressed){
                pressed = false;
            }
            else{
            pressed = true;
            }
        }

    }

}

void Button::MakeVisible(){
    visible = true;
}
void Button::MakeInVisible(){
    visible = false;
}

        void UnPress(){
            pressed = false;
        }

        bool Pressed(){
            return pressed;
        }



};