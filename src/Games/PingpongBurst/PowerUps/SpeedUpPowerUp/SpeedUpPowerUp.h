#pragma once

#include "../PowerUp.h"

class SpeedUpPowerUp : public PowerUp
{

public:
    SpeedUpPowerUp(Vector2 position);
    ~SpeedUpPowerUp() override = default;

    void Apply() override;

};