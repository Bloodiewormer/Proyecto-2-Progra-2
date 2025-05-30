#pragma once
#include "Position.h"
class Entity
{
protected:
	Position position; // Position of the entity in the grid
	int energy; // Energy level of the entity
public:
    Entity(Position pos, int energy = 100);
    virtual ~Entity() = default;

    Position getPosition() const;
    int getEnergy() const;
    void setEnergy(int value);
    void setPosition(const Position& pos);

    virtual void update() = 0;

};

