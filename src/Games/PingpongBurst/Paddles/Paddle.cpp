#include "Paddle.h"

#include "../../../Core/Config.h"

Paddle::Paddle(float posX, float posY, float width, float height, float speed) : m_StartPosition { posX, posY }, m_Rect{ posX, posY, width, height }, m_Speed{ speed }
{

}

void Paddle::Move(float posY)
{
    m_Rect.y = posY;

    LimitWithinScreen();
}

void Paddle::LimitWithinScreen()
{
    if ( m_Rect.y < 0)
        m_Rect.y = 0;
    else if (m_Rect.y > Config::ScreenHeight - m_Rect.height)
        m_Rect.y = Config::ScreenHeight - m_Rect.height;
}

void Paddle::Draw()
{
    DrawRectangle(m_Rect.x, m_Rect.y, m_Rect.width, m_Rect.height, WHITE);
    //DrawRectangleRec(m_Rect, WHITE);
}

void Paddle::Reset()
{
    m_Rect.y = m_StartPosition.y;
}