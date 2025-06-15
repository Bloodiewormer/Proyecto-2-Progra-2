#pragma once
#include "Grid.h"
#include "EnvironmentManager.h"
#include "Utils.h"
#include <vector>
#include <iostream>
class Ecosystem //singleton
{
private:
	int seed = 0; // Semilla para la generaci�n aleatoria
	Grid grid;
	int tick;
	static Ecosystem* instance;
	Ecosystem() : tick(0) { 
		grid = Grid(); 
	}// Inicializa una cuadr�cula de 10x10 por defecto
	ClimateManager climateManager; // Gestor de clima y estaciones
	SeasonManager seasonManager; // Gestor de estaciones
	void cycleSeason(); // M�todo para ciclar el entorno.
	void cycleClimate(); // M�todo para ciclar el clima. 

public:
	static Ecosystem& getInstance();
	Grid& getGrid() { return grid; }
	void run(int maxTicks);
	void jumpToTick(int targetTick); // M�todo para saltar a un tick espec�fico

	int getTick() const { return tick; } // M�todo para obtener el n�mero de tics actuales

	void setSeed(int newSeed) { seed = newSeed; } // M�todo para establecer la semilla
	int getSeed() const { return seed; } // M�todo para obtener la semilla actual

	ClimateManager& getClimateManager();
	SeasonManager& getSeasonManager(); 
};