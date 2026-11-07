#include "Player.h"

void Player::Update(float deltaTime)
{
    float posY = m_Rect.y;

    #pragma region Player Controller
    if (IsKeyDown(KEY_W))
    {
        posY -= m_Speed * deltaTime;
    }
    if (IsKeyDown(KEY_S))
    {
        posY += m_Speed * deltaTime;
    }
    #pragma endregion

    Move(posY);
}