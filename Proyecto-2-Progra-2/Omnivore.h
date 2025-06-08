#pragma once
#include "Creature.h"
#include "RandomMovement.h"
#include "HerbivoreFeeding.h"
#include "CarnivoreFeeding.h"
#include "MatingReproduction.h"
class Omnivore : public Creature
{
public:
	//Omnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
	Omnivore(int x, int y);
	Omnivore(Position pos);
	char getSymbol() const override;
	void update() override;

	//draw the creature on the console
	void draw() const override;

};

