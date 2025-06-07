#pragma once
class Creature;

struct IFeedingStrategy {
    virtual void feed(Creature* creature) = 0;
    virtual ~IFeedingStrategy() {}
};


