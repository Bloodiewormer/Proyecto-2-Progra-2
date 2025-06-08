#pragma once
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"
#include "RandomMovement.h"
#include "CarnivoreFeeding.h"
#include "HerbivoreFeeding.h"


class CreatureFactory {
public:
    static Herbivore* createHerbivore(int x, int y) {
		return new Herbivore(x, y);
    }
	static Herbivore* createHerbivore(Position position) {
        return new Herbivore(position);
	}
    static Carnivore* createCarnivore(int x, int y) {
		return new Carnivore(x, y);
    }
    static Carnivore* createCarnivore(Position position) {
		return new Carnivore(position);
	}
    static Omnivore* createOmnivore(int x, int y) {
		return new Omnivore(x, y);
    }
	static Omnivore* createOmnivore(Position position) {
		return new Omnivore(position);
	}
};;