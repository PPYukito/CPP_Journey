#pragma once

#include <raylib.h>

class Paddle
{

private:
    Vector2 m_StartPosition {};

    void LimitWithinScreen();

protected:
    Rectangle m_Rect {};
    float m_Speed = 0;

    void Move(float posY);

public:
    Paddle() = default;
    Paddle(float posX, float posY, float width, float height, float speed);

    Rectangle GetRect() const { return m_Rect; }
    
    void Draw();
    virtual void Reset();

};