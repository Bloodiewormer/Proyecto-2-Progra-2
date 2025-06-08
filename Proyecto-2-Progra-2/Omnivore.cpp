#include "Omnivore.h"



Omnivore::Omnivore(int x, int y):Creature(x, y) {
	this->movement = new RandomMovement();
	this->feeding = new HerbivoreFeeding(); // Default feeding strategy for omnivores	
	this->reproduction = new MatingReproduction();
	this->energy = 100; // Initial energy for carnivores

}

Omnivore::Omnivore(Position pos):Creature(pos) {
	this->movement = new RandomMovement();
	this->feeding = new HerbivoreFeeding(); // Default feeding strategy for omnivores	
	this->reproduction = new MatingReproduction();
	this->energy = 100; // Initial energy for carnivores
}

char Omnivore::getSymbol() const
{
	return 'O';
}

void Omnivore::update()
{
	// Call the base class update method
	Creature::update();
	// Additional logic specific to Omnivore can be added here
	
	// si es menore de 30 de energia se cambia la estrategia de alimentacion a carnivoro
	// si esta entre 30 y 60 de forma aleatoria
	//si es mayor a 60 se cambia a herbivoro
	if (energy < 30) {
		setFeedingStrategy(new CarnivoreFeeding());
	} else if (energy >= 30 && energy <= 60) {
		if (rand() % 2 == 0) {
			setFeedingStrategy(new CarnivoreFeeding());
		} else {
			setFeedingStrategy(new HerbivoreFeeding());
		}
	} else {
		setFeedingStrategy(new HerbivoreFeeding());
	}

}


	//draw();

void Omnivore::draw() const
{
	//first the type of creature
	std::cout << "Omnivore at (" << position.x << ", " << position.y << ")" << std::endl;
	//then the energy bar
	const int barWidth = 10;
	int filled = (energy * barWidth) / 100;
	int empty = barWidth - filled;
	std::cout << "Energy: ";
	for (int i = 0; i < filled; ++i) std::cout << "#";
	for (int i = 0; i < empty; ++i) std::cout << "*";
	std::cout << " " << energy << "/100" << std::endl;

	if (dynamic_cast<const CarnivoreFeeding*>(feeding)) std::cout<< " Feeding Strategy: Carnivore" << std::endl;
	else if (dynamic_cast<const HerbivoreFeeding*>(feeding)) std::cout<< " Feeding Strategy: Herbivore" << std::endl;
	else std::cout << " Feeding Strategy: Unknown" << std::endl;
	
}




