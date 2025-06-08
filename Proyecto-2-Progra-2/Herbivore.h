#pragma once 
#include "Creature.h"
#include "RandomMovement.h"
#include "HerbivoreFeeding.h"

class Herbivore : public Creature
{
public:
	//Herbivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
	Herbivore(int x, int y);
	Herbivore(Position pos);
	char getSymbol() const override;
	void draw() const override;
};
