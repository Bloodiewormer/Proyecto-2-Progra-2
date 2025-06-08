#include "Carnivore.h"

//Carnivore::Carnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
//    : Creature(pos, m, f, r, energy) {}

Carnivore::Carnivore(int x, int y):Creature(x, y)
{
	this->movement = new RandomMovement();
	this->feeding = new CarnivoreFeeding();
	//this->reproductionStrategy = new CarnivoreReproductionStrategy();
	this->energy = 100; // Initial energy for carnivores
}

Carnivore::Carnivore(Position pos) : Creature(pos.x, pos.y)
{
	this->movement = new RandomMovement();
	this->feeding = new CarnivoreFeeding();
	//this->reproductionStrategy = new CarnivoreReproductionStrategy();
	this->energy = 100; // Initial energy for carnivores
	this->position = pos;
}

char Carnivore::getSymbol()
{
	return 'C';
}
