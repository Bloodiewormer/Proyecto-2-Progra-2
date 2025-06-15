#include "Grass.h"

Grass::Grass(int x, int y) : Resource(x, y) {
	energy = 1;
	this->reproduction = new AsexualReproduction();
}

Grass::Grass(Position pos) : Resource(pos.x, pos.y) {
	energy = 1;
	this->reproduction = new AsexualReproduction();
}

char Grass::getSymbol() const {
	return 'G';
}

void Grass::upgrade() {
	// grass will have a 5% chance to reproduce each turn
	if (rand() % 100 < 5) { // 5% chance to reproduce
		this->reproduction->reproduce(this);
	}
}