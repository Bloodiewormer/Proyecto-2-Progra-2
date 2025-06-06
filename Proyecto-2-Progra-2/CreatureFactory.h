#pragma once
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"
#include "RandomMovement.h"

class CreatureFactory {
public:
    static Herbivore* createHerbivore(int x, int y) {
        return new Herbivore(x, y, new RandomMovement());
    }
    static Carnivore* createCarnivore(int x, int y) {
        return new Carnivore(x, y, new RandomMovement());
    }
    static Omnivore* createOmnivore(int x, int y) {
        return new Omnivore(x, y, new RandomMovement());
    }
};;