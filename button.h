#pragma once


class Button{
    private:
        float x;
        float y;
        float width;
        float height;
        std::string text;
        bool visible;
        bool pressed = false;

    public:
        Button(float x, float y, float width, float height, std::string text, bool visible);

        void displayAndPressCheck();

        void MakeVisible();

        void MakeInVisible();

        void UnPress();

        bool Pressed();

};