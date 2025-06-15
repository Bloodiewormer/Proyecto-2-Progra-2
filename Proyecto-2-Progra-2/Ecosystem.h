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
	Ecosystem() : tick(0) { 
		grid = Grid(); 
	}// Inicializa una cuadrícula de 10x10 por defecto
	ClimateManager climateManager; // Gestor de clima y estaciones
	SeasonManager seasonManager; // Gestor de estaciones
	void cycleSeason(); // Método para ciclar el entorno.
	void cycleClimate(); // Método para ciclar el clima. 

public:
	static Ecosystem& getInstance();
	Grid& getGrid() { return grid; }
	void run(int maxTicks);
	void jumpToTick(int targetTick); // Método para saltar a un tick específico

	int getTick() const { return tick; } // Método para obtener el número de tics actuales

	void setSeed(int newSeed) { seed = newSeed; } // Método para establecer la semilla
	int getSeed() const { return seed; } // Método para obtener la semilla actual

	ClimateManager& getClimateManager();
	SeasonManager& getSeasonManager(); 
};