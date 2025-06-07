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
		return new Herbivore(x, y, new RandomMovement(), new HerbivoreFeeding());
    }
    static Carnivore* createCarnivore(int x, int y) {
		return new Carnivore(x, y, new RandomMovement(), new CarnivoreFeeding());
    }
    static Omnivore* createOmnivore(int x, int y) {
		return new Omnivore(x, y, new RandomMovement(), new HerbivoreFeeding());// Omnivore can eat both herbivores and carnivores, so we can use HerbivoreFeeding for simplicity
    }
};;