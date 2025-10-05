#include <raylib.h>
#include "func.hpp"


int main(void)
{
    InitWindow(400, 400, "GOST");
    TextBox holeTextBox("Hole", 150, 150);
    //TextBox sahftTextBox("Shaft", 0, 0);

    while (!WindowShouldClose())
    {
        // double buffer
        BeginDrawing();
            ClearBackground(RAYWHITE);
            draw_bar(15, RED);

            holeTextBox.draw();
            // sahftTextBox.draw();
            //draw_grid();
            
        EndDrawing();
        
    }

    CloseWindow();

    return 0;
}

