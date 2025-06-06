#include "Creature.h"

//Creature::Creature(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
//    : Entity(pos, energy), movement(m), feeding(f), reproduction(r), age(0) {
//}



Creature::Creature(int x, int y, IMovementStrategy* moveStrat):Entity(x, y), movement(moveStrat) {}

Creature::Creature(const Creature& other) : Entity(other.position.x, other.position.y, other.energy) {
    movement = other.movement; // shallow copy for simplicity
}

Creature& Creature::operator=(const Creature& other)
{
    if (this != &other) {
        position = other.position;
        energy = other.energy;
        movement = other.movement;
    }
    return *this;
}


void Creature::update() {
    if (movement) movement->move(this);
    energy--;
	age++;
    /*
    feeding->feed(this);
    reproduction->reproduce(this);*/
}

void Creature::setMovementStrategy(IMovementStrategy* m)
{
	movement = m;
}

int Creature::getAge() const {
    return age;
}

