#pragma once

#include "../../Core/Scene.h"

#include <raylib.h>

class PingpongBurstScene : public Scene
{

private:
    Vector2 circlePos  {};
    float circleRadius = 20.0f;
    float circleSpeed = 300.0f;

public:
    void Initialize() override;
    void Finalize() override;
    void Update(float deltaTime) override;
    void Draw() override;

};