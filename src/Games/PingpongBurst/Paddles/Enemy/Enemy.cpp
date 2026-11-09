#include "Enemy.h"

#include "../../../../Core/Config.h"
#include "../../Ball/Ball.h"

void Enemy::Update(float deltaTime, const Ball& ball)
{   
    // If the move is not moving torwards ai enemy, the enemy doesn't move;
    if (ball.GetVelocity().x <= 0)
        return;

    float posY = m_Rect.y;

    float paddleCenter = m_Rect.y + m_Rect.height / 2;
    float ballY = ball.GetPosition().y;

    if (ballY < paddleCenter - m_DeadZone)
    {
        posY -= m_Speed * deltaTime;   // ball is above → go up
    }
    else if (ballY > paddleCenter + m_DeadZone)
    {
        posY += m_Speed * deltaTime;   // ball is below → go down
    }

    Move(posY);
}