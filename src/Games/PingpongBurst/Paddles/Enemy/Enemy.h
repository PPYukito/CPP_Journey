#pragma once

#include "../Paddle.h"

class Enemy : public Paddle
{

public:
    using Paddle::Paddle;
    void Update(float deltaTime);

};