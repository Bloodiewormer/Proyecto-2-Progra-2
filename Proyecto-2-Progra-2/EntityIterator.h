#pragma once
#include "Entity.h"
#include <vector>
class EntityIterator{ // maybe not needed, already have been evaluated
private:
    std::vector<Entity*> collection;
    int current;

public:
    EntityIterator(const std::vector<Entity*>& list);
    bool hasNext() const;
    Entity* next();
};

