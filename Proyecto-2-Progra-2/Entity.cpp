#include "Entity.h"

Entity::Entity(int x, int y, int energy)
    : position(x, y), energy(energy) {
}

Entity::Entity(const Position& pos, int energy)
{
    position = pos;
	this->energy = energy;
}

Position Entity::getPosition() const {
    return position;
}

int Entity::getEnergy() const {
    return energy;
}

void Entity::modifyEnergy(int delta)//this adds or subtracts energy from the entity
{
	energy += delta; //ej: if delta is -10, energy will decrease by 10
    if (energy < 0) {
        energy = 0; // Ensure energy does not go below zero
	}
}

void Entity::setEnergy(int value) {//this sets the energy to a specific value
    energy = value;
}

bool Entity::isDead() const
{
	return energy <= 0; // Returns true if energy is zero or less
}

void Entity::setPosition(int x, int y) {
    position.x = x; position.y = y;
}

