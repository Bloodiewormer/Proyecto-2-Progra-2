#pragma once
#include <string>
#include "Entity.h"
#include "IReproductionStrategy.h"
class Resource : public Entity
{
protected:
	IReproductionStrategy* reproduction;
public:
    Resource(int x, int y);

};

