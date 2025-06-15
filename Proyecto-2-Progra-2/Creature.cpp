#include "Creature.h"
#include <cstring>

//destructor
Creature::~Creature() {
    delete movement;
    delete feeding; 
	delete reproduction; // Clean up reproduction strategy if it exists
}


Creature::Creature(int x, int y) :Entity(x, y), age(0) {
    movement = nullptr; // Initialize movement strategy to nullptr
    feeding = nullptr; // Initialize feeding strategy to nullptr
	reproduction = nullptr; // Initialize reproduction strategy to nullptr
    seasonBoost = 0; // Default season boost
    climateBoost = 0; // Default climate boost
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(Position p) : Entity(p.x, p.y) {
    movement = nullptr; // Initialize movement strategy to nullptr
    feeding = nullptr; // Initialize feeding strategy to nullptr
	reproduction = nullptr; // Initialize reproduction strategy to nullptr
	seasonBoost = 0; // Default season boost
	climateBoost = 0; // Default climate boost
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(const Creature& other) : Entity(other.position.x, other.position.y, other.energy), age(other.age) {
    movement = other.movement; // shallow copy for simplicity  
    feeding = other.feeding; // shallow copy for simplicity  
	reproduction = other.reproduction; // shallow copy for simplicity
    energy = other.energy; // Ensure energy is copied  
    age = other.age; // Initialize age explicitly  
	seasonBoost = other.seasonBoost; // Copy season boost
	climateBoost = other.climateBoost; // Copy climate boost
}


Creature& Creature::operator=(const Creature& other)
{
    if (this != &other) {
        position = other.position;
        energy = other.energy;
		

        // Delete existing strategies to avoid memory leaks
        delete movement;
        delete feeding;
		delete reproduction; 

        // Deep copy: clone strategies if they exist, else set to nullptr
        
		//to be implemented if strategies support cloning
        //movement = other.movement ? other.movement->clone() : nullptr;
        //feeding = other.feeding ? other.feeding->clone() : nullptr;

        age = other.age;
    }
    return *this;
}



void Creature::upgrade() {

    age++;
	int probablityBoost = 0;
	probablityBoost = seasonBoost + climateBoost; // Combine boosts from season and climate
    if (movement) {
        movement->move(this); // Move the creature using its movement strategy
	}


    if( energy <= 80) {
        if (rand() % 100 < 50 + probablityBoost) { // 50% chance to feed, boosted by season and climate
            if (feeding) feeding->feed(this); // Feed if energy is low
        }
	}


    if (energy >= 70&& age >= 5) {
		// random deision to reproduce
        if (rand() % 100 < 5 + probablityBoost) { // 5% chance to reproduce
            if (reproduction) reproduction->reproduce(this); // Reproduce if energy is sufficient or age is high
        }
	}
    energy--;
   


}

void Creature::setMovementStrategy(IMovementStrategy* m)
{
    movement = m;
}

void Creature::setFeedingStrategy(IFeedingStrategy* f)
{
    feeding = f;
}

void Creature::setReproductionStrategy(IReproductionStrategy* r)
{
	reproduction = r;
}

int Creature::getAge() const {
    return age;
}

void Creature::onSeasonChange(const std::string& newSeason) {
    // Ejemplo: ajusta el boost según la estación
    if (newSeason == "Primavera") seasonBoost = 5;
    else if (newSeason == "Verano") seasonBoost = 3;
    else if (newSeason == "Otoño") seasonBoost = 3;
    else if (newSeason == "Invierno") seasonBoost = -2;
    else seasonBoost = 0;
}

void Creature::onClimateChange(const std::string& newClimate) {
    // Ejemplo: ajusta el boost según el clima
    if (newClimate == "Soleado") climateBoost = 5;
    else if (newClimate == "Lluvioso") climateBoost = 2;
    else if (newClimate == "Nublado") climateBoost = 3;
    else climateBoost = 0;
}

int Creature::getSeasonBoost() const{
    return seasonBoost;
}

int Creature::getClimateBoost() const{
    return seasonBoost;
}

