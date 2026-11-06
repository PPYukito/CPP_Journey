#pragma once

#include "../../Core/Scene.h"

#include <raylib.h>
#include "Paddles/Paddle.h"

class PingpongBurstScene : public Scene
{

private:
    Vector2 m_CirclePos  {};
    float m_CircleRadius = 20.0f;
    float m_CircleSpeed = 300.0f;

    static constexpr float k_PaddleSpeed = 300.0f;
    static constexpr float k_PaddleWidth = 20.0f;
    static constexpr float k_PaddleHeight = 100.0f;

    static constexpr float k_PlayerPosX = 80.0f;

    Paddle Player;
    Paddle AIPlayer;

public:
    void Initialize() override;
    void Finalize() override;
    void Update(float deltaTime) override;
    void Draw() override;

};