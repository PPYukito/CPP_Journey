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
    static constexpr float k_OriginalSpeed = 450.0f;

    float m_EffectDuration = 0.0f;
    float m_ElapsedTime = 0.0f;
    bool m_EffectIsApplying = false;

    // Ball details
    Vector2 m_Position {};
    Vector2 m_Velocity { 1, 1 };
    float m_Radius = 20.0f;
    float m_Speed = k_OriginalSpeed;
    Color m_Color = Color{ 243, 213, 91, 255 };

    // Walls Details
    float m_TopLimit = m_Radius;
    float m_RightLimit = Config::ScreenWidth - m_Radius;
    float m_BottomLimit = Config::ScreenHeight - m_Radius;
    float m_LeftLimit = m_Radius;

    void MoveBall(float deltaTime);
    void CheckWalls();
    void BounceOffWalls(float limitedValue, bool xAxis);
    void ApplyEffect(float deltaTime);
    void EffectOff();

public:
    Ball() = default;
    Ball(float posX, float posY);

    std::function<void(Goal)> OnGoal;

    Vector2 GetPosition()   const { return m_Position; }
    Vector2 GetVelocity()   const { return m_Velocity; }
    float GetRadius()       const { return m_Radius; }

    void Update(float deltaTime);
    void Draw();

    void BounceOffPaddle(const Rectangle& paddle);
    void ApplySpeed(float speed, float duration);
    void Reset();

};