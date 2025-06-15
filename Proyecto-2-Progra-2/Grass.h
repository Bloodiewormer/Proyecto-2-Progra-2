#pragma once
#include "Resource.h"
#include "AsexualReproduction.h"
class Grass : public Resource
{
private: 
public:
	Grass(int x, int y);
	Grass(Position pos);
	char getSymbol() const override;
	void upgrade() override;
    void draw() const override {}
};

