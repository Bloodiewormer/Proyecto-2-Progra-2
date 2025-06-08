#pragma once
#include "Creature.h"
#include "RandomMovement.h"
#include "CarnivoreFeeding.h"
#include "MatingReproduction.h"
class Carnivore : public Creature
{
public:

	Carnivore(int x, int y);
	Carnivore(Position pos);
	char getSymbol() const override;

	void draw() const override;
};