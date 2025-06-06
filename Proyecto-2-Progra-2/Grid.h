#pragma once
#include "Entity.h"

const int GRID_SIZE = 10;

class Grid
{
private:
	Entity* cells[GRID_SIZE][GRID_SIZE];
public:	

	Grid();
	void placeEntity(Entity* e);// Coloca una entidad en una celda específica
	void moveEntity(Entity* e, int newX, int newY);
	void updateAll();
	void draw();
	bool isInBounds(int x, int y);// Verifica si las coordenadas están dentro de los límites del grid
	
};


