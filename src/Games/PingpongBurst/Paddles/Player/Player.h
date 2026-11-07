#pragma once

#include "../Paddle.h"

class Player : public Paddle
{

public:
    using Paddle::Paddle;
    void Update(float deltatime);

};