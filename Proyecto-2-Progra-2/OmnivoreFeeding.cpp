#include "OmnivoreFeeding.h"

void OmnivoreFeeding::feed(Creature* creature)
{
    for (Entity* e : Ecosystem::getInstance().getGrid().getEntities()) {
        if (e == creature) continue;
        int dx = creature->getPosition().x - e->getPosition().x;
        int dy = creature->getPosition().y - e->getPosition().y;
        if (dx * dx + dy * dy <= 2) {
            if (dynamic_cast<Resource*>(e)) {
                Ecosystem::getInstance().getGrid().removeEntity(e);
                creature->modifyEnergy(2);
                break;
            }
            else if (dynamic_cast<Creature*>(e) && typeid(*e) != typeid(*creature)) {
                Ecosystem::getInstance().getGrid().removeEntity(e);
                creature->modifyEnergy(4);
                break;
            }
        }
    }
}

