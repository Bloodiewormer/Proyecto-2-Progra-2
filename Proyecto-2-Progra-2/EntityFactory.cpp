#include "EntityFactory.h"

Herbivore* EntityFactory::createHerbivore(int x, int y)
{
    Herbivore* h = new Herbivore(x, y);
    Ecosystem::getInstance().getClimateManager().registerObserver(h);
    Ecosystem::getInstance().getSeasonManager().registerObserver(h);
    return h;
}

Herbivore* EntityFactory::createHerbivore(Position position)
{
    Herbivore* h = new Herbivore(position);
    Ecosystem::getInstance().getClimateManager().registerObserver(h);
    Ecosystem::getInstance().getSeasonManager().registerObserver(h);
    return h;
}

Carnivore* EntityFactory::createCarnivore(int x, int y)
{
    Carnivore* c = new Carnivore(x, y);
    Ecosystem::getInstance().getClimateManager().registerObserver(c);
    Ecosystem::getInstance().getSeasonManager().registerObserver(c);
    return c;
}

Carnivore* EntityFactory::createCarnivore(Position position)
{
    Carnivore* c = new Carnivore(position);
    Ecosystem::getInstance().getClimateManager().registerObserver(c);
    Ecosystem::getInstance().getSeasonManager().registerObserver(c);
    return c;
}

Omnivore* EntityFactory::createOmnivore(int x, int y)
{
    Omnivore* o = new Omnivore(x, y);
    Ecosystem::getInstance().getClimateManager().registerObserver(o);
    Ecosystem::getInstance().getSeasonManager().registerObserver(o);
    return o;
}

Omnivore* EntityFactory::createOmnivore(Position position)
{
    Omnivore* o = new Omnivore(position);
    Ecosystem::getInstance().getClimateManager().registerObserver(o);
    Ecosystem::getInstance().getSeasonManager().registerObserver(o);
    return o;
}

Grass* EntityFactory::createGrass(int x, int y)
{
    return new Grass(x, y);
}

Grass* EntityFactory::createGrass(Position position)
{
    return new Grass(position);
}
