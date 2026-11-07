#include "Enemy.h"

#include "../../../../Core/Config.h"

void Enemy::Update(float deltaTime)
{
    float posY = m_Rect.y;



    Move(posY);
}