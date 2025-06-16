#pragma once
#include "Grid.h"
#include "EnvironmentManager.h"
#include "Utils.h"
#include <vector>
#include <iostream>
class Ecosystem //singleton
{
private:
	int seed = 0; // Semilla para la generación aleatoria
	Grid grid;
	int tick;
	static Ecosystem* instance;
	Ecosystem();
	ClimateManager climateManager; // Gestor de clima y estaciones
	SeasonManager seasonManager; // Gestor de estaciones
	void cycleSeason(); // Método para ciclar el entorno.
	void cycleClimate(); // Método para ciclar el clima. 

public:
	static Ecosystem& getInstance();
	Grid& getGrid();
	void run(int maxTicks);
	void jumpToTick(int targetTick); // Método para saltar a un tick específico

	int getTick() const;

	void setSeed(int newSeed);
	int getSeed() const;

	ClimateManager& getClimateManager();
	SeasonManager& getSeasonManager(); 
};