#pragma once
#include "Creature.h"
class Omnivore : public Creature
{
public:
	//Omnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
	Omnivore(int x, int y, IMovementStrategy* m);
	char getSymbol() override;
};

