#pragma once

#include <raylib.h>
#include <functional>
#include "../../../Core/Config.h"

enum class Goal
{
    None,
    Player,
    AIPlayer
};

class Ball
{

private:
    // Ball details
    Vector2 m_Position {};
    Vector2 m_Velocity { 1, 1 };
    float m_Radius = 20.0f;
    float m_Speed = 400.0f;
    Color m_Color = YELLOW;

    // Walls Details
    float m_TopLimit = m_Radius;
    float m_RightLimit = Config::ScreenWidth - m_Radius;
    float m_BottomLimit = Config::ScreenHeight - m_Radius;
    float m_LeftLimit = m_Radius;

    void MoveBall(float deltaTime);
    void CheckWalls();
    void BounceOffWalls(float limitedValue, bool xAxis);

public:
    Ball() = default;
    Ball(float posX, float posY);

    Vector2 GetPosition()   const { return m_Position; }
    Vector2 GetVelocity()   const { return m_Velocity; }
    float GetRadius()       const { return m_Radius; }

    void Update(float deltaTime);
    void Draw();

    void BounceOffPaddle(const Rectangle& paddle);
    std::function<void(Goal)> OnGoal;
    void Reset();

};