
#pragma once
#include "Entity.h"
#include"IMovementStrategy.h"
#include "IFeedingStrategy.h"
#include "IReproductionStrategy.h"
#include"ClimateManager.h"

class Creature : public Entity, public IObserver
{
protected:
    IMovementStrategy* movement;
    IFeedingStrategy* feeding;
    IReproductionStrategy* reproduction;
    int age;

    int seasonBoost;   // Aumento por estación
    int climateBoost;  // Aumento por clima

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

    // Métodos de IObserver
    void onSeasonChange(const char* newSeason) override;
    void onClimateChange(const char* newClimate) override;

    int getSeasonBoost() const;
    int getClimateBoost() const;
};