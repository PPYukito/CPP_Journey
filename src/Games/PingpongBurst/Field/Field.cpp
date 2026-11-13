#include "Field.h"

#include "../../../Core/Config.h"

Field::Field(float lineWidth) : m_LineWidth{ lineWidth }
{

}

void Field::Draw()
{
    // in this case, change to draw rectangle would be better.
    DrawRectangle(0, 0, Config::ScreenWidth / 2, Config::ScreenHeight, m_DarkGreen);
    DrawRectangle(Config::ScreenWidth / 2, 0, Config::ScreenWidth / 2, Config::ScreenHeight, m_Green);
    DrawCircle(Config::ScreenWidth / 2, Config::ScreenHeight / 2, 140, m_LightGreen);
    DrawLine(Config::ScreenWidth / 2, 0, Config::ScreenWidth / 2, Config::ScreenHeight, WHITE);
}