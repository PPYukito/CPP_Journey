#include "Field.h"

#include <raylib.h>
#include "../../../Core/Config.h"

Field::Field(float lineWidth) : m_LineWidth{ lineWidth }
{

}

void Field::Draw()
{
    // in this case, change to draw rectangle would be better.
    DrawLine(Config::ScreenWidth / 2, 0, Config::ScreenWidth / 2, Config::ScreenHeight, WHITE);
}