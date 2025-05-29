#pragma once
#include "Creature.h"

class CreatureFactory {
public:
    virtual ~CreatureFactory() = default;
    virtual Creature* createCreature() const = 0;
};