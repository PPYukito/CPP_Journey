#pragma once

#include <raylib.h>

class Paddle
{

private:
    Rectangle m_Rect {};
    //float m_Height;
    float m_Speed = 0;

    void LimitInScreen();
    
public:
    Paddle() = default;
    Paddle(float posX, float posY, float width, float height, float speed);
    
    void Move(float deltaTime);
    void Draw();

};