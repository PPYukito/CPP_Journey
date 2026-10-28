#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

void PingpongBurstScene::Initialize()
{
    circlePos = Vector2{ Config::ScreenWidth / 2, Config::ScreenHeight / 2 };
}

void PingpongBurstScene::Finalize()
{

}

void PingpongBurstScene::Update(float deltaTime)
{

}

void PingpongBurstScene::Draw()
{
    DrawRectangle(80, 100, 20, 100, WHITE);
    DrawCircleV(circlePos, circleRadius, WHITE);
}