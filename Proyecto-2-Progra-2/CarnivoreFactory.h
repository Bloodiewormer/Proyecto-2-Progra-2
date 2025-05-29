#pragma once
#include "CreatureFactory.h"
#include "Carnivore.h"

class CarnivoreFactory : public CreatureFactory {
public:
    Creature* createCreature() const override {
        return new Carnivore();
    }
};