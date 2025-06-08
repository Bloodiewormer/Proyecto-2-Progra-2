#pragma once 
#include "Creature.h"
#include "RandomMovement.h"
#include "HerbivoreFeeding.h"
#include "MatingReproduction.h"

class Herbivore : public Creature
{
public:
	Herbivore(int x, int y);
	Herbivore(Position pos);
	char getSymbol() const override;
	void draw() const override;
};
