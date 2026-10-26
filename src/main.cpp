#include <raylib.h>

int main()
{
    InitWindow(1280, 720, "My First C++ Window");
    
    SetTargetFPS(60);

    #pragma region Game Loop
    // Game Loop
    while(WindowShouldClose() == false)
    {
        // 1. Even handling

        // 2. Update

        // 3. Draw
        BeginDrawing();
        EndDrawing();
    }
    #pragma endregion

    CloseWindow();

    return 0;
}