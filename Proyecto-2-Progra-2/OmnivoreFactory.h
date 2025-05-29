#pragma once
#include "CreatureFactory.h"
#include "Omnivore.h"

class OmnivoreFactory : public CreatureFactory {
public:
    Creature* createCreature() const override {
        return new Omnivore();
    }
};