#include "HerbivoreFeeding.h"


void HerbivoreFeeding::feed(Creature* creature)
{
    for (Entity* e : Ecosystem::getInstance().getGrid().getEntities()) {
        if (e != creature && dynamic_cast<Resource*>(e)) {
            int dx = creature->getPosition().x - e->getPosition().x;
            int dy = creature->getPosition().y - e->getPosition().y;
            if (dx * dx + dy * dy <= 2) {
                Ecosystem::getInstance().getGrid().removeEntity(e);
                creature->modifyEnergy(3);
                break;
            }
        }
    }
}
