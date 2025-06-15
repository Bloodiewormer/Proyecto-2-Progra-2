#include "MatingReproduction.h"

void MatingReproduction::reproduce(Entity* creature)
{
    for (Entity* e : Ecosystem::getInstance().getGrid().getEntities()) {
        if (e != creature && dynamic_cast<Creature*>(e) && typeid(*e) == typeid(*creature)) {
            int dx = creature->getPosition().x - e->getPosition().x;
            int dy = creature->getPosition().y - e->getPosition().y;
            if (dx * dx + dy * dy <= 2) {
                Position newPos = Ecosystem::getInstance().getGrid().getUnoccupiedPositionNear(
                    creature->getPosition().x, creature->getPosition().y
                );
                if (creature->getSymbol() == 'C') {
                    Creature* newCreature = new Carnivore(newPos);
                    Ecosystem::getInstance().getGrid().placeEntity(newCreature);
                }
                else if (creature->getSymbol() == 'H') {
                    Creature* newCreature = new Herbivore(newPos);
                    Ecosystem::getInstance().getGrid().placeEntity(newCreature);
                }
                else if (creature->getSymbol() == 'O') {
                    Creature* newCreature = new Omnivore(newPos);
                    Ecosystem::getInstance().getGrid().placeEntity(newCreature);
                }

                creature->modifyEnergy(-10);
                static_cast<Creature*>(e)->modifyEnergy(-10);
                break;
            }
        }
    }
}
