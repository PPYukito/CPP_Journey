#pragma once

#include <raylib.h>

class Ball
{

private:
    // Ball details
    Vector2 m_Position {};
    Vector2 m_Velocity { 1, 1 };
    float m_Radius = 20.0f;
    float m_Speed = 200.0f;

    bool m_IsPlaying = false;

public:
    Ball() = default;
    Ball(float posX, float posY);

    bool IsPlaying() const { return m_IsPlaying; }

    void Update(float deltaTime);
    void Draw();

    void PlayOff();

};