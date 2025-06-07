#pragma once
#include "Grid.h"
#include "Utils.h"
#include <iostream>
class Ecosystem //singleton
{
private:
	Grid grid;
	int tick;
	static Ecosystem* instance;
	Ecosystem() : tick(0) {}



public:
	static Ecosystem& getInstance();
	Grid& getGrid() { return grid; }
	void run(int maxTicks);


	//void saveState(); // metodo para guardar el estado del ecosistema
	//void loadState(); // metodo para cargar el estado del ecosistema

	
};