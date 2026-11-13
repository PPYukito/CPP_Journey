#pragma once

#include "../Paddle.h"

class Ball;

class Enemy : public Paddle
{

private:
    float m_DeadZone = 5.0f;
    float m_AimOffset = 0.0f;
    float m_ReactionPoint = 0.5f;   // 0.5 = midfield, 0.7 = later (easier)
    bool m_IsBallComing = false;

    void MoveToward(float deltaTime, float targetY);

public:
    using Paddle::Paddle;

    void Update(float deltaTime, const Ball& ball);

};