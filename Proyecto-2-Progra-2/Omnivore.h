#pragma once
#include "Creature.h"
#include "HerbivoreFeeding.h"
#include "CarnivoreFeeding.h"
class Omnivore : public Creature
{
public:
	//Omnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
	Omnivore(int x, int y, IMovementStrategy* m, IFeedingStrategy* f);
	char getSymbol() override;
	void update() override;


};

