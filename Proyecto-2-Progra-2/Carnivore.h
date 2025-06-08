#pragma once
#include "Creature.h"
#include "RandomMovement.h"
#include "CarnivoreFeeding.h"
class Carnivore : public Creature 
{
public:

	Carnivore(int x, int y);
	Carnivore(Position pos);
	char getSymbol() override;
};

