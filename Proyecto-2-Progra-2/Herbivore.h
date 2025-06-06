#pragma once 
#include "Creature.h"
class Herbivore : public Creature
{
public:
	//Herbivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
	Herbivore(int x, int y, IMovementStrategy* m);
	char getSymbol() override;
};

