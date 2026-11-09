#include "Ball.h"

#include <raymath.h>

Ball::Ball(float posX, float posY) : m_Position { posX, posY }
{
    m_Velocity = Vector2Normalize(m_Velocity);
}

void Ball::Update(float deltaTime)
{
    if (m_IsPlaying)
    {
        Vector2 direction;
        direction.x = m_Position.x + m_Velocity.x * m_Speed * deltaTime;
        direction.y = m_Position.y + m_Velocity.y * m_Speed * deltaTime;
        m_Position = direction;
    }
}

void Ball::Draw()
{
    DrawCircleV(m_Position, m_Radius, WHITE);
}

void Ball::PlayOff()
{
    m_IsPlaying = true;
}