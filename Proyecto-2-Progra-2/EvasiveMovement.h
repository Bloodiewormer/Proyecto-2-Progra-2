#pragma once
#include "iMovementStrategy.h"
#include "Creature.h"
#include "Ecosystem.h"
#include "Resource.h"
#include <cmath>
class EvasiveMovement : public IMovementStrategy
{
    void move(Creature* creature) override;
};

