#pragma once
#include "Grid.h"
#include "ClimateManager.h"
#include "Utils.h"
#include <vector>
#include <iostream>
class Ecosystem //singleton
{
private:
	Grid grid;
	int tick;
	static Ecosystem* instance;
	Ecosystem() : tick(0) { 
		grid = Grid(); // Inicializa una cuadrícula de 10x10 por defecto
	}

	ClimateManager climateManager; // Gestor de clima y estaciones
	void cycleEnvironment(); // Método para ciclar el entorno. Cambia estación y clima

public:
	static Ecosystem& getInstance();
	Grid& getGrid() { return grid; }
	void run(int maxTicks);


	//void saveState(); // metodo para guardar el estado del ecosistema
	//void loadState(); // metodo para cargar el estado del ecosistema

	ClimateManager& getClimateManager();
};