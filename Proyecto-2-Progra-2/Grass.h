#pragma once
#include "Resource.h"
#include "AsexualReproduction.h"
class Grass : public Resource
{
private: 
public:
    Grass(int x, int y) : Resource(x, y) { 
		
		energy = 1; 
		this->reproduction = new AsexualReproduction();
	
	}
	Grass(Position pos) : Resource(pos.x,pos.y) { 
		energy = 1;
		this->reproduction = new AsexualReproduction();
	}
    char getSymbol() const override { return 'G'; }

    void update() override {
		// grass will haave a 5% chance to reproduce each turn
        if (rand() % 100 < 5) { // 5% chance to reproduce
			this->reproduction->reproduce(this);
		}
    }

    void draw() const override {
		//do nothing, grass does not draw itself
	}
};

