#include "../raylib.h"

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenHeigt = 450;
    const int screenWidth = 800;
    InitWindow(screenWidth, screenHeigt, "Windows");
    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawText("Congrats! You created your first window", 190, 200, 20,
                 LIGHTGRAY);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}