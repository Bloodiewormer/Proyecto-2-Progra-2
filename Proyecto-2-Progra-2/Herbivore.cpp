#include "Herbivore.h"

//Herbivore::Herbivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
//    : Creature(pos, m, f, r, energy) {}

Herbivore::Herbivore(int x, int y):Creature(x, y) 
{
	this->movement = new RandomMovement();
	this->feeding = new HerbivoreFeeding();
	//this->reproductionStrategy = new HerbivoreReproductionStrategy();
	this->energy = 100; // Initial energy for herbivores
}

Herbivore::Herbivore(Position pos) :Creature(pos) 
{
	this->movement = new RandomMovement();
	this->feeding = new HerbivoreFeeding();
	//this->reproductionStrategy = new HerbivoreReproductionStrategy();
	this->energy = 100; // Initial energy for herbivores
}

char Herbivore::getSymbol()
{
	return 'H';	
}

