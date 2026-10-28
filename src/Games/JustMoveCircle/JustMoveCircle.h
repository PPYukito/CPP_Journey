#pragma once

#include "../../Core/Scene.h"

#include <raylib.h>

class JustMoveCircle : public Scene
{

private:
    Vector2 m_CirclePos {640, 360};
    float m_CircleSpeed = 300.0f;

public:
    void Initialize() override;
    void Finalize() override;
    void Update(float deltaTime) override;
    void Draw() override;

};