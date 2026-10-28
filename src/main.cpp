#include <raylib.h>
#include <memory>

#include "Core/Config.h"

#include "Games/JustMoveCircle/JustMoveCircle.h"
#include "Games/PingpongBurst/PingpongBurstScene.h"

int main()
{
    // Set up window
    InitWindow(Config::ScreenWidth, Config::ScreenHeight, Config::WindowTitle);
    SetTargetFPS(Config::TargetFPS);

    // Create scene
    std::unique_ptr<Scene> currentScene = std::make_unique<PingpongBurstScene>();
    currentScene->Initialize();

    #pragma region Game Loop
    // Game Loop
    while(WindowShouldClose() == false)
    {
        // Update
        currentScene->Update(GetFrameTime());

        // Draw
        #pragma region Drawing
        BeginDrawing();

            currentScene->Draw();

        EndDrawing();
        #pragma endregion
    }
    #pragma endregion

    // Clear data
    currentScene->Finalize();
    CloseWindow();

    // end
    return 0;
}