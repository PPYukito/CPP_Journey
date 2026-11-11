#include "Ball.h"

#include <raymath.h>


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

void Ball::CheckWalls()
{
    // Bottom
    if (m_Position.y > m_BottomLimit)
    {
        BounceBack(m_BottomLimit, false);                        
    }
    // Top
    else if (m_Position.y < m_TopLimit)
    {
        BounceBack(m_TopLimit, false);
    }

    // Right
    if (m_Position.x > m_RightLimit)
    {
        BounceBack(m_RightLimit, true);
    }
    // Left
    else if (m_Position.x < m_LeftLimit)
    {
        BounceBack(m_LeftLimit, true);
    }
}

void Ball::BounceBack(float limitedValue, bool xAxis)
{
    float overlap = (xAxis ? m_Position.x : m_Position.y) - limitedValue;
    float backVector = overlap / (xAxis ? m_Velocity.x : m_Velocity.y);

    m_Position.x -= m_Velocity.x * backVector;       // step back along the path...
    m_Position.y -= m_Velocity.y * backVector;       
    
    (xAxis ? m_Velocity.x : m_Velocity.y) *= -1;
}

void Ball::Update(float deltaTime)
{
    MoveBall(deltaTime);
    CheckWalls();
}

void Ball::Draw()
{
    DrawCircleV(m_Position, m_Radius, m_Color);
}

void Ball::BounceOffPaddle(const Rectangle& paddle)
{
    if (CheckCollisionCircleRec(m_Position, m_Radius, paddle))
        m_Velocity.x *= -1;
}