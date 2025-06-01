#pragma once
#include"IFeedingStrategy.h"
#include"Grid.h"
#include"Creature.h"
class OmnivoreFeeding : public IFeedingStrategy{
private:
    Grid* grid;

public:
    OmnivoreFeeding(Grid* grid);
    void feed(Creature* creature) override;
};

