#include "Creature.h"

//Creature::Creature(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
//    : Entity(pos, energy), movement(m), feeding(f), reproduction(r), age(0) {
//}



Creature::Creature(int x, int y):Entity(x, y), age(0) {
	movement = nullptr; // Initialize movement strategy to nullptr
	feeding = nullptr; // Initialize feeding strategy to nullptr
    energy = 100; // Default energy value
	age = 0; // Default age value
}

Creature::Creature(Position p): Entity(p.x, p.y), age(0) {
    movement = nullptr; // Initialize movement strategy to nullptr
    feeding = nullptr; // Initialize feeding strategy to nullptr
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(const Creature& other) : Entity(other.position.x, other.position.y, other.energy), age(other.age) {  
    movement = other.movement; // shallow copy for simplicity  
    feeding = other.feeding; // shallow copy for simplicity  
    energy = other.energy; // Ensure energy is copied  
    age = other.age; // Initialize age explicitly  
}

Creature& Creature::operator=(const Creature& other)
{
    if (this != &other) {
        position = other.position;
        energy = other.energy;
        movement = other.movement;
		feeding = other.feeding; // shallow copy for simplicity
    }
    return *this;
}


void Creature::update() {
    if (movement) movement->move(this);
	if (feeding) feeding->feed(this);//
    energy--;
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

int Creature::getAge() const {
    return age;
}

