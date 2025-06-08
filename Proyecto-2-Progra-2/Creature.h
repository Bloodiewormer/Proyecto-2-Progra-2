
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
    // IReproductionStrategy* reproduction;
    int age;

public:
    //Creature(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy = 100);
    Creature(int x, int y);
    Creature(Position p);
    Creature(const Creature& other);
    Creature& operator=(const Creature& other);
    virtual ~Creature() = default;

    virtual void update() override;
    void setMovementStrategy(IMovementStrategy* m);
    void setFeedingStrategy(IFeedingStrategy* f);

    int getAge() const;
};