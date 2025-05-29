#pragma once
#include "CreatureFactory.h"
#include "Herbivore.h"

class HerbivoreFactory : public CreatureFactory {
public:
    Creature* createCreature() const override {
        return new Herbivore();
    }
};