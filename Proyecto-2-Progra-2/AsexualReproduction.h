#pragma once
#include"IReproductionStrategy.h"
#include "Grid.h"
#include "Creature.h"
class AsexualReproduction : public IReproductionStrategy{
private:
    Grid* grid;

public:
    AsexualReproduction(Grid* grid);
    void reproduce(Creature* creature) override;
};

