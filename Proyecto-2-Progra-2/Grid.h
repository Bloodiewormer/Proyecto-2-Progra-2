#pragma once
#include "Entity.h"
#include <vector>
class Grid
{
private:
	int width; // Ancho de la cuadr�cula
	int height; // Alto de la cuadr�cula
	std::vector<std::vector<Entity*>> cells; // Matriz de celdas que contiene entidades
public:	
	Grid(int size); // Constructor para inicializar la cuadr�cula con un ancho y alto espec�ficos
	bool isEmoty(int x, int y) const; // Verifica si una celda est� vac�a
	Entity getEntity(int x, int y) const; // Obtiene la entidad en una celda espec�fica
	void moveEntity(int fromX, int fromY, int toX, int toY); // Mueve una entidad de una celda a otra
	void removeEntity(int x, int y); // Elimina una entidad de una celda espec�fica
	void addEntity(int x, int y, Entity* entity); // Agrega una entidad a una celda espec�fica
};


