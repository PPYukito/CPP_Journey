#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

void PingpongBurstScene::Initialize()
{
    //m_CirclePos = Vector2{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };
    m_Ball = Ball{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };

    float startHeight = (Config::ScreenHeight / 2.0f) - (k_PaddleHeight / 2.0f);
    m_PlayerPaddle = Player(k_PlayerPosX, startHeight, k_PaddleWidth, k_PaddleHeight, k_PaddleSpeed);

    float aiPlayerPosX = Config::ScreenWidth - k_PlayerPosX - k_PaddleWidth;
    m_AIPlayer = Enemy(aiPlayerPosX, startHeight, k_PaddleWidth, k_PaddleHeight, k_PaddleSpeed);
}

void PingpongBurstScene::Finalize()
{

}

void PingpongBurstScene::Update(float deltaTime)
{
    if (IsKeyDown(KEY_SPACE))
    {
        if (m_Ball.IsPlaying() == false)
            m_Ball.PlayOff();
    }

    m_Ball.Update(deltaTime);

    m_PlayerPaddle.Update(deltaTime);
    m_AIPlayer.Update(deltaTime);
}

void PingpongBurstScene::Draw()
{
    ClearBackground(BLACK);

    // Field
    m_Field.Draw();

    // Ball
    m_Ball.Draw();

    // Player
    m_PlayerPaddle.Draw();

    // AI Player
    m_AIPlayer.Draw();
}

