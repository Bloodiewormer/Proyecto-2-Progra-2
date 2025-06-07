#pragma once
#include "IFeedingStrategy.h"
#include "Creature.h"
#include "Ecosystem.h"
#include "Resource.h"

class OmnivoreFeeding : public IFeedingStrategy {
public:
    void feed(Creature* creature) override; 
};

