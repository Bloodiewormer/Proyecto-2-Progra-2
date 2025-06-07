#include "Omnivore.h"

/*mnivore::Omnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy) : Creature(pos, m, f, r, energy) {}*/

Omnivore::Omnivore(int x, int y, IMovementStrategy* m, IFeedingStrategy* f):Creature(x, y, m, f) {}

char Omnivore::getSymbol()
{
	return 'O';
}


