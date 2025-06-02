#include "Carnivore.h"

Carnivore::Carnivore(Position pos, IMovementStrategy* m, IFeedingStrategy* f, IReproductionStrategy* r, int energy)
    : Creature(pos, m, f, r, energy) {}