#pragma once
#include"IReproductionStrategy.h"
#include "Grid.h"
#include "Creature.h"
class MatingReproduction : public IReproductionStrategy{
private:
	Grid* grid;
public:
	MatingReproduction(Grid* grid);
	void reproduce(Creature* creature) override;
};

