#pragma once
#include "Creature.h"
#include "RandomMovement.h"
#include "CarnivoreFeeding.h"
class Carnivore : public Creature 
{
public:
	Carnivore(int x, int y, IMovementStrategy* m, IFeedingStrategy* f);
	char getSymbol() override;
};

