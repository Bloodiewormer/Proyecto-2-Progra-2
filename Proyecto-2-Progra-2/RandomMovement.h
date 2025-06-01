#pragma once
#include <cstdlib>
#include "IMovementStrategy.h"

class RandomMovement : public IMovementStrategy {
public:
	RandomMovement() = default;
    Position move(const Position& current) override;
};

