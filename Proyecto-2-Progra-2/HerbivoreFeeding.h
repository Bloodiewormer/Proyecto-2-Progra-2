#pragma once
#include"IFeedingStrategy.h"
#include"Grid.h"
#include"Creature.h"
#include"Resource.h"

class HerbivoreFeeding : public IFeedingStrategy {
private:
    Grid* grid;

public:
    HerbivoreFeeding(Grid* grid);
    void feed(Creature* creature) override;
};

