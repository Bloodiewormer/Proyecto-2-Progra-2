#pragma once
#include "Resource.h"
class Grass : public Resource
{
public:
    Grass(int x, int y) : Resource(x, y) { energy = 1; }
	Grass(Position pos) : Resource(pos.x,pos.y) { energy = 1; }
    char getSymbol() const override { return 'G'; }

    void update() override {
		// grass will haave a 5% chance to reproduce each turn
        if (rand() % 100 < 5) { // 5% chance to reproduce
			// Asexual reproduction strategy needs to be implemented
 
		}
    }

    void draw() const override {
		//do nothing, grass does not draw itself
	}
};

