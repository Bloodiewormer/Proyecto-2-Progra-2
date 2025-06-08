#pragma once
#include"IReproductionStrategy.h"
#include "Creature.h"
#include "Entity.h"
#include "Carnivore.h"
#include "Herbivore.h"
#include "Omnivore.h"
#include "Ecosystem.h"
class MatingReproduction : public IReproductionStrategy{
public:
	void reproduce(Entity* creature) override;
};

