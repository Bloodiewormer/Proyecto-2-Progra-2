#pragma once

#include "IMovementStrategy.h"
#include "Creature.h"
#include "Ecosystem.h"

class RandomMovement : public IMovementStrategy {
public:
    void move(Creature* creature) override;
};

