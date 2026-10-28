#include "PingpongBurstScene.h"

#include "../../Core/Config.h"

void PingpongBurstScene::Initialize()
{
    circlePos = Vector2 {Config::ScreenWidth / 2, Config::ScreenHeight / 2};
}

void PingpongBurstScene::Finalize()
{

}

void PingpongBurstScene::Update(float deltaTime)
{

}

void PingpongBurstScene::Draw()
{
    DrawCircleV(circlePos, circleRadius, WHITE);
}