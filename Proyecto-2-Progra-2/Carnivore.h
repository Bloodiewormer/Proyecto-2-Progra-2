#pragma once
#include "Creature.h"
class Carnivore : public Creature 
{
public:
	Carnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);

};

