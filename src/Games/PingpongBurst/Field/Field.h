#pragma once

#include <raylib.h>

class Field
{

private:
    float m_LineWidth = 0;
    Color m_Green = Color{ 38, 185, 154, 255 };
    Color m_LightGreen = Color{ 129, 204, 184, 255 };
    Color m_DarkGreen = Color{ 20, 160, 133, 255 };

public:
    Field(float lineWidth);
    void Draw();

};