#pragma once
#include"Entity.h"
class IReproductionStrategy {
public:
    virtual void reproduce(class Entity* mate) = 0;
    virtual ~IReproductionStrategy() {}
};

