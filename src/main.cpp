#include <raylib.h>
#include <raymath.h>

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "My First C++ Window");

    SetTargetFPS(60);

    Vector2 circlePos{ screenWidth / 2.0f, screenHeight / 2.0f };
    
    float circleSpeed = 300.0f;

    #pragma region Game Loop
    // Game Loop
    while(WindowShouldClose() == false)
    {
        Vector2 travelDir{};

        // 1. Event handling

        // 2. Update
        if (IsKeyDown(KEY_W))
        {
            travelDir.y -= 1;
        }
        if (IsKeyDown(KEY_A))
        {
            travelDir.x -= 1;
        }
        if (IsKeyDown(KEY_S))
        {
            travelDir.y += 1;
        }
        if (IsKeyDown(KEY_D))
        {
            travelDir.x += 1;
        }

        travelDir = Vector2Normalize(travelDir);
        circlePos.x += travelDir.x * circleSpeed * GetFrameTime();
        circlePos.y += travelDir.y * circleSpeed * GetFrameTime();

        #pragma region Drawing
        // 3. Draw
        BeginDrawing();

            ClearBackground(WHITE);

            // Position => The position will be the center of the circle.
            DrawCircleV(Vector2{circlePos.x, circlePos.y}, 50.0f, GREEN);

        EndDrawing();
        #pragma endregion
    }
    #pragma endregion

    CloseWindow();

    return 0;
}