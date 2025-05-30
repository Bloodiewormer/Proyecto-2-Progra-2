#pragma once
#include "Entity.h"
#include"IMovementStrategy.h"
#include "IFeedingStrategy.h"
#include "IReproductionStrategy.h"
class Creature : public Entity
{
protected:
    IMovementStrategy* movement;
    IFeedingStrategy* feeding;
    IReproductionStrategy* reproduction;
    int age;

public:
    Creature(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
    virtual ~Creature() = default;

    virtual void update() override;

    int getAge() const;
};

