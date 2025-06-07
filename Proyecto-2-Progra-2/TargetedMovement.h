#pragma once
#include "iMovementStrategy.h"
#include "Creature.h"
#include "Ecosystem.h"
#include <cmath>

class TargetedMovement : public IMovementStrategy {
public:
    void move(Creature* creature) override;
};