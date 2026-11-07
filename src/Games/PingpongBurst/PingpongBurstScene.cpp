#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

void PingpongBurstScene::Initialize()
{
    m_CirclePos = Vector2{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };

    float startHeight = (Config::ScreenHeight / 2.0f) - (k_PaddleHeight / 2.0f);
    PlayerPaddle = Player(k_PlayerPosX, startHeight, k_PaddleWidth, k_PaddleHeight, k_PaddleSpeed);

    float aiPlayerPosX = Config::ScreenWidth - k_PaddleWidth - k_PlayerPosX;
    AIPlayer = Enemy(aiPlayerPosX, startHeight, k_PaddleWidth, k_PaddleHeight, k_PaddleSpeed);
}

void PingpongBurstScene::Finalize()
{

}

void PingpongBurstScene::Update(float deltaTime)
{
    PlayerPaddle.Update(deltaTime);
    AIPlayer.Update(deltaTime);
}

void PingpongBurstScene::Draw()
{
    ClearBackground(BLACK);

    // Player
    PlayerPaddle.Draw();

    // Ball
    DrawCircleV(m_CirclePos, m_CircleRadius, WHITE);

    // AI Player
    AIPlayer.Draw();
}

