#include "Carnivore.h"


Carnivore::Carnivore(int x, int y) :Creature(x, y)
{
	this->movement = new RandomMovement();
	this->feeding = new CarnivoreFeeding();
	this->reproduction = new MatingReproduction();
	this->energy = 100; // Initial energy for carnivores
}

Carnivore::Carnivore(Position pos) : Creature(pos.x, pos.y)
{
	this->movement = new RandomMovement();
	this->feeding = new CarnivoreFeeding();
	this->reproduction = new MatingReproduction();
	this->energy = 100; // Initial energy for carnivores
	this->position = pos;
}

char Carnivore::getSymbol() const
{
	return 'C';
}

void Carnivore::draw() const
{
	//first the type of creature
	std::cout << "Carnivore at (" << position.x << ", " << position.y << ")" << std::endl;
	//then the energy bar
	const int barWidth = 10;
	int filled = (energy * barWidth) / 100;
	int empty = barWidth - filled;
	std::cout << "Energy: ";
	for (int i = 0; i < filled; ++i) std::cout << "#";
	for (int i = 0; i < empty; ++i) std::cout << "*";
	std::cout << " " << energy << "/100" << std::endl;
}