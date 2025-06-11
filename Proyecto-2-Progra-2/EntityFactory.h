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
    static Herbivore* createHerbivore(int x, int y) {
        Herbivore* h = new Herbivore(x, y);
        Ecosystem::getInstance().getClimateManager().registerObserver(h);
        Ecosystem::getInstance().getSeasonManager().registerObserver(h);
        return h;
    }
    static Herbivore* createHerbivore(Position position) {
        Herbivore* h = new Herbivore(position);
        Ecosystem::getInstance().getClimateManager().registerObserver(h);
        Ecosystem::getInstance().getSeasonManager().registerObserver(h);
        return h;
    }
    static Carnivore* createCarnivore(int x, int y) {
        Carnivore* c = new Carnivore(x, y);
        Ecosystem::getInstance().getClimateManager().registerObserver(c);
        Ecosystem::getInstance().getSeasonManager().registerObserver(c);
        return c;
    }
    static Carnivore* createCarnivore(Position position) {
        Carnivore* c = new Carnivore(position);
        Ecosystem::getInstance().getClimateManager().registerObserver(c);
        Ecosystem::getInstance().getSeasonManager().registerObserver(c);
        return c;
    }
    static Omnivore* createOmnivore(int x, int y) {
        Omnivore* o = new Omnivore(x, y);
        Ecosystem::getInstance().getClimateManager().registerObserver(o);
        Ecosystem::getInstance().getSeasonManager().registerObserver(o);
        return o;
    }
    static Omnivore* createOmnivore(Position position) {
        Omnivore* o = new Omnivore(position);
        Ecosystem::getInstance().getClimateManager().registerObserver(o);
        Ecosystem::getInstance().getSeasonManager().registerObserver(o);
        return o;
    }

    // Resources
    static Grass* createGrass(int x, int y) {
        return new Grass(x, y);
    }
    static Grass* createGrass(Position position) {
        return new Grass(position);
    }
};