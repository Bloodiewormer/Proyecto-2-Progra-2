#pragma once
#include"Entity.h"
class IReproductionStrategy {
public:
    virtual void reproduce(class Creature* creature) = 0;
    virtual ~IReproductionStrategy() {}
};

