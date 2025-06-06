#include "RandomMovement.h"

//Position RandomMovement::move(const Position& current) {
//    int dx = (std::rand() % 3) - 1; // -1, 0, 1
//    int dy = (std::rand() % 3) - 1;
//    return Position(current.getX() + dx, current.getY() + dy);
//}

void RandomMovement::move(Creature* creature)
{
    int dx = rand() % 3 - 1;
    int dy = rand() % 3 - 1;
    Position p = creature->getPosition();
    int newX = p.x + dx;
    int newY = p.y + dy;
    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX >= GRID_SIZE) newX = GRID_SIZE - 1;
    if (newY >= GRID_SIZE) newY = GRID_SIZE - 1;

    Ecosystem::getInstance().getGrid().moveEntity(creature, newX, newY);
}
