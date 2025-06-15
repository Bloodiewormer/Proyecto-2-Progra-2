#pragma once
#include "Creature.h"
#include "RandomMovement.h"
#include "HerbivoreFeeding.h"
#include "CarnivoreFeeding.h"
#include "MatingReproduction.h"
class Omnivore : public Creature
{
public:
	Omnivore(int x, int y);
	Omnivore(Position pos);
	char getSymbol() const override;
	void upgrade() override;
	void draw() const override;
};