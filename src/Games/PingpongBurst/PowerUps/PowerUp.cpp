#include "PowerUp.h"

#include "../../../Core/Config.h"

#include "../Ball/Ball.h"

PowerUp::PowerUp(Vector2 position, Color color) : m_Position { position }, m_Color { color }
{

}

void PowerUp::Draw()
{
    DrawCircle(m_Position.x, m_Position.y, m_Radius, m_Color);
}

bool PowerUp::CheckHitBall(const Ball& ball)
{
    return CheckCollisionCircles(m_Position, m_Radius, ball.GetPosition(), ball.GetRadius());
}
