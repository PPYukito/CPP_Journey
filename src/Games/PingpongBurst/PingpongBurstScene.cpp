#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

void PingpongBurstScene::Initialize()
{
    m_CirclePos = Vector2{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };

    float startHeight = (Config::ScreenHeight / 2.0f) - (k_PaddleHeight / 2.0f);
    m_PlayerPosY = startHeight;
    m_AIPlayerPosY = startHeight;

    m_PlayerSpeed = k_PaddleSpeed;
    m_AIPlayerSpeed = k_PaddleSpeed;

    m_PlayerHeight = k_PaddleHeight;
    m_AIPlayerHeight = k_PaddleHeight;
}

void PingpongBurstScene::Finalize()
{

}

void PingpongBurstScene::Update(float deltaTime)
{
    #pragma region Player Controller
    if (IsKeyDown(KEY_W))
    {
        m_PlayerPosY -= m_PlayerSpeed * deltaTime;
    }
    if (IsKeyDown(KEY_S))
    {
        m_PlayerPosY += m_PlayerSpeed * deltaTime;
    }
    #pragma endregion

    LimitInScreen();
}

void PingpongBurstScene::Draw()
{
    ClearBackground(BLACK);

    // Player
    DrawRectangle(k_PlayerPosX, m_PlayerPosY, k_PaddleWidth, m_PlayerHeight, WHITE);

    // Ball
    DrawCircleV(m_CirclePos, m_CircleRadius, WHITE);

    // AI Player
    DrawRectangle(Config::ScreenWidth - k_PaddleWidth - k_PlayerPosX, m_AIPlayerPosY, k_PaddleWidth, m_AIPlayerHeight, WHITE);
}

void PingpongBurstScene::LimitInScreen()
{
    // Check for Player
    if ( m_PlayerPosY < 0)
        m_PlayerPosY = 0;
    else if (m_PlayerPosY > Config::ScreenHeight - m_PlayerHeight)
        m_PlayerPosY = Config::ScreenHeight - m_PlayerHeight;
}