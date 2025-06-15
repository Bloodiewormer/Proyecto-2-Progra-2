#include "AsexualReproduction.h"
#include "Ecosystem.h"
#include "Grass.h"
//#include "WaterEntity.h"

void AsexualReproduction::reproduce(Entity* creature)
{
    // Only allow asexual reproduction for Grass and WaterEntity
    char symbol = creature->getSymbol();

    if (symbol == 'G') { // Grass
        // Grass always reproduces asexually
        Position newPos = Ecosystem::getInstance().getGrid().getUnoccupiedPositionNear(
            creature->getPosition().x, creature->getPosition().y);
        Grass* newGrass = new Grass(newPos);
        Ecosystem::getInstance().getGrid().placeEntity(newGrass);
    } else if (symbol == 'W') { // WaterEntity (future type)
        // Only reproduce if it's raining
        //if (Ecosystem::getInstance().isRaining()) {
        //    Position newPos = grid->getUnoccupiedPosition();
        //    WaterEntity* newWater = new WaterEntity(newPos);
        //    grid->placeEntity(newWater);
        //    creature->modifyEnergy(-8); // Energy cost for water reproduction
        //}
    }
}
