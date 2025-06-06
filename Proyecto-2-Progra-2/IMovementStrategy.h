#pragma once

class Creature;

struct IMovementStrategy {
    virtual void move(Creature* creature) = 0;
    virtual ~IMovementStrategy() {}
};
