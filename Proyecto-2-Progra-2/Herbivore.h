#pragma once 
#include "Creature.h"
#include "RandomMovement.h"
#include "EvasiveMovement.h"
#include "HerbivoreFeeding.h"
#include "MatingReproduction.h"

class Herbivore : public Creature
{
public:
	Herbivore(int x, int y);
	Herbivore(Position pos);
	void upgrade() override;
	char getSymbol() const override;
	void draw() const override;
};
