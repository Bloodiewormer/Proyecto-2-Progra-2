#include "Entity.h"

Entity::Entity(Position pos, int energy)
    : position(pos), energy(energy) {
}

Position Entity::getPosition() const {
    return position;
}

int Entity::getEnergy() const {
    return energy;
}

void Entity::setEnergy(int value) {
    energy = value;
}

void Entity::setPosition(const Position& pos) {
    position = pos;
}

