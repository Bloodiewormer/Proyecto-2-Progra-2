#pragma once
#include"IFeedingStrategy.h"
#include"Grid.h"
#include"Creature.h"
class CarnivoreFeeding : public IFeedingStrategy{
private:
    Grid* grid;

public:
    CarnivoreFeeding(Grid* grid);
    void feed(Creature* creature) override;
};

