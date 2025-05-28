#include "Position.h"

Position::Position(int x, int y) : x(x), y(y) {}

int Position::getX() const{ return x; }

int Position::getY() const{ return y; }

bool Position::operator==(const Position& other) const{
	return x == other.x && y == other.y;
}
