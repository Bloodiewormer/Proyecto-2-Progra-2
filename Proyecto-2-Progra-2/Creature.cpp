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
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(Position p) : Entity(p.x, p.y) {
    movement = nullptr; // Initialize movement strategy to nullptr
    feeding = nullptr; // Initialize feeding strategy to nullptr
	reproduction = nullptr; // Initialize reproduction strategy to nullptr
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(const Creature& other) : Entity(other.position.x, other.position.y, other.energy), age(other.age) {
    movement = other.movement; // shallow copy for simplicity  
    feeding = other.feeding; // shallow copy for simplicity  
	reproduction = other.reproduction; // shallow copy for simplicity
    energy = other.energy; // Ensure energy is copied  
    age = other.age; // Initialize age explicitly  
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



void Creature::update() {
    if (movement) movement->move(this);
    if (feeding) feeding->feed(this);
	if (reproduction) reproduction->reproduce(this);    
    energy--;
    //if(season =="summer") energy--; // Example condition for energy consumption
    age++;

    /*
    reproduction->reproduce(this);*/
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

void Creature::onSeasonChange(const char* newSeason){
	if (strcmp(newSeason, "primavera") == 0) seasonBoost = 10;//strcmp means string compare, returns 0 if equal
    else if (strcmp(newSeason, "verano") == 0) seasonBoost = 5;
    else if (strcmp(newSeason, "otonnio") == 0) seasonBoost = 3;
    else if (strcmp(newSeason, "invierno") == 0) seasonBoost = -5;
    else seasonBoost = 0;
}

void Creature::onClimateChange(const char* newClimate){
    if (strcmp(newClimate, "soleado") == 0) climateBoost = 5;
    else if (strcmp(newClimate, "lluvioso") == 0) climateBoost = 3;
    else if (strcmp(newClimate, "nuboso") == 0) climateBoost = 1;
    else if (strcmp(newClimate, "seco") == 0) climateBoost = -3;
    else climateBoost = 0;
}

int Creature::getSeasonBoost() const{
    return seasonBoost;
}

int Creature::getClimateBoost() const{
    return seasonBoost;
}

