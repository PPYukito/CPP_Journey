#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

#include "PowerUps/SpeedUpPowerUp/SpeedUpPowerUp.h"

void PingpongBurstScene::Initialize()
{
    //m_CirclePos = Vector2{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };
    m_Ball = Ball{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };
    // Subscribe goal function
    m_Ball.OnGoal = [this](Goal goal) { OnGoal(goal); };

    SpawnPowerUp();

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
    // Hit play
    if (IsKeyDown(KEY_SPACE) && m_IsPlaying == false)
    {
        m_IsPlaying = true;
    }

    if (m_IsPlaying == true)
    {
        // Human control
        m_PlayerPaddle.Update(deltaTime);
        
        // Computer control
        m_Ball.Update(deltaTime);
        m_AIPlayer.Update(deltaTime, m_Ball);

        // Power Up check
        if (m_PowerUp && m_PowerUp->CheckHitBall(m_Ball))
        {
            m_PowerUp->Apply();
            m_PowerUp.reset();
        }

        // Bounce Ball off paddles
        m_Ball.BounceOffPaddle(m_PlayerPaddle.GetRect());
        m_Ball.BounceOffPaddle(m_AIPlayer.GetRect());
    }
}

void PingpongBurstScene::Draw()
{
    ClearBackground(BLACK);

    // Field
    m_Field.Draw();

    // Ball
    m_Ball.Draw();

    // PowerUps
    if (m_PowerUp != nullptr)
        m_PowerUp->Draw();

    // Player
    m_PlayerPaddle.Draw();

    // AI Player
    m_AIPlayer.Draw();

    // Score
    DrawScore();
}

void PingpongBurstScene::OnGoal(Goal goal)
{
    if (goal == Goal::Player)
        m_PlayerScore++;
    else if (goal == Goal::AIPlayer)
        m_AIScore++;

    // Pause the game;
    m_IsPlaying = false;

    // Reset
    m_Ball.Reset();
    m_PlayerPaddle.Reset();
    m_AIPlayer.Reset();
}

void PingpongBurstScene::DrawScore()
{
    DrawText(TextFormat("%i", m_PlayerScore), Config::ScreenWidth / 4 - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i", m_AIScore), (3 * (Config::ScreenWidth / 4)) - 20, 20, 80, WHITE);
}

void PingpongBurstScene::SpawnPowerUp()
{
    float x = (float)GetRandomValue(Config::ScreenWidth / 3, Config::ScreenWidth * 2 / 3);
    float y = (float)GetRandomValue(50, Config::ScreenHeight - 50);

    m_PowerUp = std::make_unique<SpeedUpPowerUp>(Vector2{ x, y });
}
