#pragma once

#include "../Paddle.h"

class Ball;

class Enemy : public Paddle
{

private:
    float m_DeadZone = 50.0f;

public:
    using Paddle::Paddle;

    void Update(float deltaTime, const Ball& ball);

};