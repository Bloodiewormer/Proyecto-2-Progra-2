
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

    virtual ~Creature();
    Creature(int x, int y);
    Creature(Position p);
    Creature(const Creature& other);
    Creature& operator=(const Creature& other);

    virtual void update() override;
    void setMovementStrategy(IMovementStrategy* m);
    void setFeedingStrategy(IFeedingStrategy* f);
	void setReproductionStrategy(IReproductionStrategy* r);

    int getAge() const;
};