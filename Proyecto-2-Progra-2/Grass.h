#pragma once
#include "Resource.h"
class Grass : public Resource
{
public:
    Grass(int x, int y, int energyValue = 1): Resource(x, y, energyValue) {}
    char getSymbol() override { return 'G'; }

    void update() override {
		// grass will haave a 5% chance to reproduce each turn
        if (rand() % 100 < 5) { // 5% chance to reproduce
			// Asexual reproduction strategy needs to be implemented
 
		}
    }
};

