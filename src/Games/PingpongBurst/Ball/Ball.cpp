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
        BounceOffWalls(m_BottomLimit, false);                        
    }
    // Top
    else if (m_Position.y < m_TopLimit)
    {
        BounceOffWalls(m_TopLimit, false);
    }

    // Right
    if (m_Position.x > m_RightLimit)
    {
        //BounceOffWalls(m_RightLimit, true);
        if (!OnGoal)
            return;

        OnGoal(Goal::Player);
    }
    // Left
    else if (m_Position.x < m_LeftLimit)
    {
        //BounceOffWalls(m_LeftLimit, true);
        if (!OnGoal)
            return;

        OnGoal(Goal::AIPlayer);
    }
}

void Ball::BounceOffWalls(float limitedValue, bool xAxis)
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
    if (!CheckCollisionCircleRec(m_Position, m_Radius, paddle))
        return;

    // Ball's direction, based on paddle's x center position
    float paddleCenterX = paddle.x + paddle.width / 2;
    float side = (m_Position.x < paddleCenterX) ? -1.0f : 1.0f;

    // Already moving away? Then it bounced last frame -> don't flip again
    if (m_Velocity.x * side > 0)
        return;

    // Check hit position in -1 to +1 range from paddle's center Y point;
    float paddleCenterY = paddle.y + paddle.height / 2;
    float offset = (m_Position.y - paddleCenterY) / (paddle.height / 2);
    // The ball has radius. So it can hit paddle's edges and check = true;
    // The value could be more than 1.0 or less than -1.0
    // So we need to clamp within -1.0, 1.0 range;
    offset = Clamp(offset, -1.0f, 1.0f);

    // Turn that into an angle (center = straight, edge = steep)
    float maxAngle = 60.0f * DEG2RAD;
    float angle = offset * maxAngle;

    // New direction: x goes away from the paddle, y comes from the angle
    m_Velocity.x = cosf(angle) * side;
    m_Velocity.y = sinf(angle);
}

void Ball::Reset()
{
    m_Position = Vector2{ Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f };
    m_Velocity = Vector2Normalize(Vector2{ 1, 1 });
}