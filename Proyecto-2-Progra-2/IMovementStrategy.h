#pragma once
#include "Entity.h"

class IMovementStrategy {
public:
    virtual Position move(const Position& current) = 0;
    virtual ~IMovementStrategy() {}
};

