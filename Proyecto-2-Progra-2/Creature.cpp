#include "Creature.h"

Creature::Creature(int x, int y, IMovementStrategy* moveStrat, IFeedingStrategy* f):Entity(x, y), movement(moveStrat), feeding(f), age(0) {
    energy = 100; // Default energy value
	age = 0; // Default age value
}

Creature::Creature(const Creature& other) : Entity(other.position.x, other.position.y, other.energy) {
    movement = other.movement; // shallow copy for simplicity
	feeding = other.feeding; // shallow copy for simplicity
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
	if (feeding) feeding->feed(this);
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

