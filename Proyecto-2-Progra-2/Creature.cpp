#include "Creature.h"

Creature::Creature(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
    : Entity(pos, energy), movement(m), feeding(f), reproduction(r), age(0) {
}

void Creature::update() {
    age++;
    position = movement->move(position);
    feeding->feed(this);
    reproduction->reproduce(this);
}

int Creature::getAge() const {
    return age;
}

