#pragma once
#include "Entity.h"
#include <vector>
class Grid
{
private:
	int width; // Ancho de la cuadrícula
	int height; // Alto de la cuadrícula
	std::vector<std::vector<Entity*>> cells; // Matriz de celdas que contiene entidades
public:	
	Grid(int size); // Constructor para inicializar la cuadrícula con un ancho y alto específicos
	bool isEmoty(int x, int y) const; // Verifica si una celda está vacía
	Entity getEntity(int x, int y) const; // Obtiene la entidad en una celda específica
	void moveEntity(int fromX, int fromY, int toX, int toY); // Mueve una entidad de una celda a otra
	void removeEntity(int x, int y); // Elimina una entidad de una celda específica
	void addEntity(int x, int y, Entity* entity); // Agrega una entidad a una celda específica
};


