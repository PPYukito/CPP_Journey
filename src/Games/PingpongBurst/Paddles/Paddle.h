#pragma once

#include <raylib.h>

class Paddle
{

private:
    Rectangle m_Rect {};
    float m_Speed = 0;

public:
    Paddle() = default;
    Paddle(float width, float height, float posX, float posY);

};