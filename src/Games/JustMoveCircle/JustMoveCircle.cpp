#include "JustMoveCircle.h"

#include <raymath.h>

void JustMoveCircle::Initialize()
{
    m_CirclePos = { GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f };
}

void JustMoveCircle::Finalize()
{
    
}

void JustMoveCircle::Update(float deltaTime)
{
    Vector2 travelDir{};

    // 1. Event handling

    // 2. Update
    if (IsKeyDown(KEY_W))
    {
        travelDir.y -= 1;
    }
    if (IsKeyDown(KEY_A))
    {
        travelDir.x -= 1;
    }
    if (IsKeyDown(KEY_S))
    {
        travelDir.y += 1;
    }
    if (IsKeyDown(KEY_D))
    {
        travelDir.x += 1;
    }

    travelDir = Vector2Normalize(travelDir);
    m_CirclePos.x += travelDir.x * m_CircleSpeed * deltaTime;
    m_CirclePos.y += travelDir.y * m_CircleSpeed * deltaTime;
}

void JustMoveCircle::Draw()
{
    ClearBackground(WHITE);

    // Position => The position will be the center of the circle.
    DrawCircleV(m_CirclePos, 50.0f, GREEN);
}
