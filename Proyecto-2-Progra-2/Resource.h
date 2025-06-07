#pragma once
#include <string>
#include "Entity.h"
class Resource : public Entity
{
private:
    std::string type; // can only be "water" and "Grass(food)"
public:
    Resource(int x, int y, const std::string& type, int energyValue);
    std::string getType() const;
    void update() override;
};

