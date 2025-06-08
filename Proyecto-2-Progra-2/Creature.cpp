#include "Creature.h"

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

Creature::Creature(Position p) : Entity(p.x, p.y), age(0) {
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

