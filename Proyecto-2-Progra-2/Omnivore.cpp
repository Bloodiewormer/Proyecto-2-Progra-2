#include "Omnivore.h"

/*mnivore::Omnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy) : Creature(pos, m, f, r, energy) {}*/

Omnivore::Omnivore(int x, int y, IMovementStrategy* m, IFeedingStrategy* f):Creature(x, y, m, f) {}

char Omnivore::getSymbol()
{
	return 'O';
}

void Omnivore::update()
{
	// Call the base class update method
	Creature::update();
	// Additional logic specific to Omnivore can be added here
	
	// si es menore de 30 de energia se cambia la estrategia de alimentacion a carnivoro
	// si esta entre 30 y 60 de forma aleatoria
	//si es mayor a 60 se cambia a herbivoro
	if (energy < 30) {
		setFeedingStrategy(new CarnivoreFeeding());
	} else if (energy >= 30 && energy <= 60) {
		if (rand() % 2 == 0) {
			setFeedingStrategy(new CarnivoreFeeding());
		} else {
			setFeedingStrategy(new HerbivoreFeeding());
		}
	} else {
		setFeedingStrategy(new HerbivoreFeeding());
	}



}


