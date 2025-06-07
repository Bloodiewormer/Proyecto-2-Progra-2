#include "Herbivore.h"

//Herbivore::Herbivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
//    : Creature(pos, m, f, r, energy) {}

Herbivore::Herbivore(int x, int y, IMovementStrategy* m,IFeedingStrategy* f ): Creature(x, y, m,f) {}

char Herbivore::getSymbol()
{
	return 'H';	
}

