#include "Ball.h"

#include <raymath.h>
#include "../../../Core/Config.h"

Ball::Ball(float posX, float posY) : m_Position { posX, posY }
{
    m_Velocity = Vector2Normalize(m_Velocity);
}

void Ball::MoveBall(float deltaTime)
{
    // Moving
    Vector2 direction;
    direction.x = m_Position.x + m_Velocity.x * m_Speed * deltaTime;
    direction.y = m_Position.y + m_Velocity.y * m_Speed * deltaTime;
    m_Position = direction;
}

void Ball::BounceOffWalls()
{
    // Bottom
    if (m_Position.y + m_Radius >= Config::ScreenHeight)
    {
        m_Position.y = Config::ScreenHeight - m_Radius;   // push back inside
        m_Velocity.y *= -1;
    }
    // Top
    else if (m_Position.y - m_Radius <= 0)
    {
        m_Position.y = m_Radius;                          // push back inside
        m_Velocity.y *= -1;
    }

    // Right
    if (m_Position.x + m_Radius >= Config::ScreenWidth)
    {
        m_Position.x = Config::ScreenWidth - m_Radius;   // push back inside
        m_Velocity.x *= -1;
    }
    // Left
    else if (m_Position.x - m_Radius <= 0)
    {
        m_Position.x = m_Radius;                          // push back inside
        m_Velocity.x *= -1;
    }
}

void Ball::Update(float deltaTime)
{
    if (m_IsPlaying == false)
        return;

    MoveBall(deltaTime);
    BounceOffWalls();
}

void Ball::Draw()
{
    DrawCircleV(m_Position, m_Radius, WHITE);
}

void Ball::SetPlay(bool play)
{
    m_IsPlaying = play;
}