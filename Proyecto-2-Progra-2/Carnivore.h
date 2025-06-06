#pragma once
#include "Creature.h"
class Carnivore : public Creature 
{
public:
	//Carnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
	Carnivore(int x, int y, IMovementStrategy* m);
	char getSymbol() override;
};

