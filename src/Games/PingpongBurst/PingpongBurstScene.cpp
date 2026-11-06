#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

void PingpongBurstScene::Initialize()
{
    m_CirclePos = Vector2{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };

    float startHeight = (Config::ScreenHeight / 2.0f) - (k_PaddleHeight / 2.0f);
    Player = Paddle(k_PlayerPosX, startHeight, k_PaddleWidth, k_PaddleHeight, k_PaddleSpeed);

    float aiPlayerPosX = Config::ScreenWidth - k_PaddleWidth - k_PlayerPosX;
    AIPlayer = Paddle(aiPlayerPosX, startHeight, k_PaddleWidth, k_PaddleHeight, k_PaddleSpeed);
}

void PingpongBurstScene::Finalize()
{

}

void PingpongBurstScene::Update(float deltaTime)
{
    Player.Move(deltaTime);
}

void PingpongBurstScene::Draw()
{
    ClearBackground(BLACK);

    // Player
    Player.Draw();

    // Ball
    DrawCircleV(m_CirclePos, m_CircleRadius, WHITE);

    // AI Player
    AIPlayer.Draw();
}

