#pragma once
#include "Creature.h"
class Carnivore : public Creature 
{
public:

	Carnivore(int x, int y, IMovementStrategy* m, IFeedingStrategy* f);
	char getSymbol() override;
};

