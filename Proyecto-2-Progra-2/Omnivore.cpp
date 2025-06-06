#include "Omnivore.h"

/*mnivore::Omnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy) : Creature(pos, m, f, r, energy) {}*/

Omnivore::Omnivore(int x, int y, IMovementStrategy* m):Creature(x, y, m) {}

char Omnivore::getSymbol()
{
	return 'O';
}


