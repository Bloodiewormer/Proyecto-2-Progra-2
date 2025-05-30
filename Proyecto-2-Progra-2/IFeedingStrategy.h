#pragma once
#include"Entity.h"

class IFeedingStrategy {
public:
    virtual void feed(class Creature* creature) = 0;
    virtual ~IFeedingStrategy() {}
};

