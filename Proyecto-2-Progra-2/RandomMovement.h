#pragma once
#include <cstdlib>
#include "IMovementStrategy.h"

class RandomMovement : public IMovementStrategy {
public:
    Position move(const Position& current) override;
};

