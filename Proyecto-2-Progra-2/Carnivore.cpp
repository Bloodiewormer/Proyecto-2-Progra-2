#include "Carnivore.h"

//Carnivore::Carnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
//    : Creature(pos, m, f, r, energy) {}

Carnivore::Carnivore(int x, int y, IMovementStrategy* m, IFeedingStrategy* f):Creature(x, y, m, f)
{
}

char Carnivore::getSymbol()
{
	return 'C';
}
