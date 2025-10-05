#pragma once
#include <raylib.h>

void draw_grid();
void draw_bar(int, Color);

class TextBox
{
    public:
        TextBox(const char*, int, int);
        void draw();
    
    private:
        int _pos_x;
        int _pos_y;
        const char* _text;
};