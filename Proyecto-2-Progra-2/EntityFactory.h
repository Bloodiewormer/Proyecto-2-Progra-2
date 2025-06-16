#pragma once
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"
#include "Grass.h"

#pragma once
#include "Herbivore.h"
#include "Carnivore.h"
#include "Omnivore.h"
#include "Grass.h"
#include "Ecosystem.h" // Needed for manager access

class EntityFactory {
public:
    // Creatures
    static Herbivore* createHerbivore(int x, int y);
    static Herbivore* createHerbivore(Position position);
    static Carnivore* createCarnivore(int x, int y);
    static Carnivore* createCarnivore(Position position);
    static Omnivore* createOmnivore(int x, int y);
    static Omnivore* createOmnivore(Position position);

    // Resources
    static Grass* createGrass(int x, int y);
    static Grass* createGrass(Position position);
};