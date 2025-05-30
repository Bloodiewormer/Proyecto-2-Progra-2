#include "RandomMovement.h"

Position RandomMovement::move(const Position& current) {
    int dx = (std::rand() % 3) - 1; // -1, 0, 1
    int dy = (std::rand() % 3) - 1;
    return Position(current.getX() + dx, current.getY() + dy);
}

