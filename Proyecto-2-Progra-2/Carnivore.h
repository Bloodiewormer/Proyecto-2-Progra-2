#pragma once
#include "Creature.h"
class Carnivore : public Creature 
{
public:
	Carnivore(int x, int y, IMovementStrategy* m);
	char getSymbol() override;
};

