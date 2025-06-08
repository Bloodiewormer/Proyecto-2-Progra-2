#pragma once
#include "Entity.h"

#include <vector>

const int GRID_SIZE = 50;

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
	std::vector<Entity*> getEntities() const;
	Entity* getEntityAt(int x, int y) const;
	void removeEntity(Entity* e);// Elimina una entidad del grid

	Position getUnoccupiedPosition() const; // Obtiene una posición no ocupada en el grid

	
	
	
};


