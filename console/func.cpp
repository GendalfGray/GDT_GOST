#include <iostream>
#include <raylib.h>
#include "func.hpp"

void draw_grid(){
    
    DrawLine(50, 10, 50, 390, BLUE);    // vertical
    DrawLine(50, 200, 390, 200, BLUE);  // horizontal
    DrawText("0", 35, 190, 20, BLACK);  // zero mark
}

void draw_bar(int _height, Color _color){
    DrawRectangle(25, 200, 50, _height, _color);
}

TextBox::TextBox(const char* text, int pos_x, int pos_y)
{
    _pos_x = pos_x;
    _pos_y = pos_y;
    _text = text;
};

void TextBox::draw()
{
    DrawText(_text, _pos_x, _pos_y, 20, BLACK);
    DrawRectangleLines(_pos_x, _pos_y+25, 50, 50, BLACK);
};