#pragma once

#include <raylib.h>

class Ball;

class PowerUp
{

private:
    Vector2 m_Position {};
    float m_Radius = 25.0f;
    Color m_Color {};

public:
    PowerUp(Vector2 position, Color color);
    virtual ~PowerUp() = default; 

    virtual void Draw();

    virtual void Apply() = 0;
    bool CheckHitBall(const Ball& ball);

};