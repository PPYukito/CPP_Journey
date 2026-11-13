#pragma once

#include "../../Core/Scene.h"

#include <memory>

#include "Field/Field.h"
#include "PowerUps/PowerUp.h"
#include "Ball/Ball.h"
#include "Paddles/Player/Player.h"
#include "Paddles/Enemy/Enemy.h"

class PingpongBurstScene : public Scene
{

private:
    // Field parameter
    static constexpr float k_LineWidth = 6.0f;

    // Field details
    Field m_Field { k_LineWidth };

    // Ball
    Ball m_Ball;

    // Power Ups
    std::unique_ptr<PowerUp> m_PowerUp = nullptr;

    // Player parameters
    static constexpr float k_PaddleSpeed = 300.0f;
    static constexpr float k_PaddleWidth = 20.0f;
    static constexpr float k_PaddleHeight = 100.0f;

    static constexpr float k_PlayerPosX = 80.0f;

    // Players
    Player  m_PlayerPaddle;
    Enemy   m_AIPlayer;

    int m_PlayerScore = 0;
    int m_AIScore = 0;

    void OnGoal(Goal goal);
    void DrawScore();
    void SpawnPowerUp();

public:
    void Initialize() override;
    void Finalize() override;
    void Update(float deltaTime) override;
    void Draw() override;

};