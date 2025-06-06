#include "Position.h"

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}

bool Position::operator==(const Position& other) const
{
	return (this->x == other.x && this->y == other.y);	
}

bool Position::operator!=(const Position& other) const
{
	return !(*this == other);
}


