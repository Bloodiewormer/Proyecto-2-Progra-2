#pragma once
#include <string>
#include "Entity.h"
class Resource : public Entity
{
private:
    std::string type;
    int regenerationTimer;

public:
    Resource(Position pos, const std::string& type, int energyValue = 20, int regen = 0);

    std::string getType() const;
    void update() override;
};

