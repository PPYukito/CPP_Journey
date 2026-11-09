#pragma once

#include "../../Core/Scene.h"

#include <raylib.h>
#include "Field/Field.h"
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

    // Player parameters
    static constexpr float k_PaddleSpeed = 300.0f;
    static constexpr float k_PaddleWidth = 20.0f;
    static constexpr float k_PaddleHeight = 100.0f;

    static constexpr float k_PlayerPosX = 80.0f;

    // Players
    Player  m_PlayerPaddle;
    Enemy   m_AIPlayer;

public:
    void Initialize() override;
    void Finalize() override;
    void Update(float deltaTime) override;
    void Draw() override;

};