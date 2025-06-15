#pragma once
#include "Position.h"
class Entity
{
protected:
    Position position; // Position of the entity in the grid
    int energy; // Energy level of the entity
public:

    Entity(int x, int y, int energy = 100);
    Entity(const Position& pos, int energy = 100);
    virtual ~Entity() = default;
    virtual void upgrade() = 0;
    virtual char getSymbol() const = 0;
    virtual void draw() const = 0;

    Position getPosition() const;
    void setPosition(int x, int y);
    int getEnergy() const;
    void modifyEnergy(int delta);
    void setEnergy(int value);
    bool isDead() const;
};