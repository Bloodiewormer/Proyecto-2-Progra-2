#pragma once
#include "Grid.h"
class Ecosystem //singleton
{
private:
	// singleton instance
	static Ecosystem* instance;
	Ecosystem() {} // Constructor privado para evitar instanciación externa
	//atributes del ecosistema
	int tickCount; // contador de tics
	int energyLevel; // nivel de energia del ecosistema
	//list<Creature*> creatures; // lista de criaturas en el ecosistema //todavia no se si se usa lista propia o de la standard library
	Grid* grid; // grid del ecosistema
public:
	static Ecosystem* getInstance();
	void timeTick(); // metodo para avanzar un tic en el ecosistema
	//void saveState(); // metodo para guardar el estado del ecosistema
	//void loadState(); // metodo para cargar el estado del ecosistema

	
};