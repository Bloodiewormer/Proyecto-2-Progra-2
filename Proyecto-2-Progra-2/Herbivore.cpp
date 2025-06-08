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

char Herbivore::getSymbol() const
{
	return 'H';	
}

//draw the herbivore on the console

void Herbivore::draw() const
{

	//first the type of creature
	std::cout << "Herbivore at (" << position.x << ", " << position.y << ")" << std::endl;
	//then the energy bar
	const int barWidth = 10;
	int filled = (energy * barWidth) / 100;
	int empty = barWidth - filled;
	std::cout << "Energy: ";
	for (int i = 0; i < filled; ++i) std::cout << "#";
	for (int i = 0; i < empty; ++i) std::cout << "*";
	std::cout << " " << energy << "/100" << std::endl;


	
}


