#include "Enemy.h"

#include "../../../../Core/Config.h"
#include "../../Ball/Ball.h"

void Enemy::Update(float deltaTime, const Ball& ball)
{   
    bool isBallComing = ball.GetVelocity().x > 0;

    // Ball just turned toward us -> choose a new aim spot
    if (isBallComing && !m_IsBallComing)
    {
        float maxOffset = m_Rect.height / 2;   // Paddle limit
        m_AimOffset = (float)GetRandomValue((int)-maxOffset, (int)maxOffset);
    }

    // Assign this value for checking in the next frame
    // to prevent enemy from jittering up and down.
    m_IsBallComing = isBallComing;

    if (!isBallComing)
        return;

    float targetY = ball.GetPosition().y + m_AimOffset;

    // Only react once the ball is past the reaction line
    float reactionLineX = Config::ScreenWidth * m_ReactionPoint;
    if (ball.GetPosition().x < reactionLineX)
        return;

    MoveToward(deltaTime, targetY);
}

void Enemy::MoveToward(float deltaTime, float targetY)
{
    float posY = m_Rect.y;
    float paddleCenter = m_Rect.y + m_Rect.height / 2;

    if (targetY < paddleCenter - m_DeadZone)
    {
        posY -= m_Speed * deltaTime;   // target is above -> go up
    }
    else if (targetY > paddleCenter + m_DeadZone)
    {
        posY += m_Speed * deltaTime;   // target is below -> go down
    }

    Move(posY);
}