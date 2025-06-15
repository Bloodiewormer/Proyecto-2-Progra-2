#include "CarnivoreFeeding.h"


void CarnivoreFeeding::feed(Creature* creature)
{
    //Range-based for loop
    for (Entity* e : Ecosystem::getInstance().getGrid().getEntities()) {
        if (e != creature && dynamic_cast<Creature*>(e) && typeid(*e) != typeid(*creature)) {
            int dx = creature->getPosition().x - e->getPosition().x;
            int dy = creature->getPosition().y - e->getPosition().y;
            if (dx * dx + dy * dy <= 2) {

				//log of death
                if (e->getSymbol() == 'O') Files::writeDeathLog("Omnivore died at tick " + std::to_string(Ecosystem::getInstance().getTick()) + " eaten at position: " + std::to_string(e->getPosition().x) + ", " + std::to_string(e->getPosition().y));
                else if(e->getSymbol() == 'H') Files::writeDeathLog("Herbivore died at tick "+ std::to_string(Ecosystem::getInstance().getTick()) + " eaten at position: " + std::to_string(e->getPosition().x) + ", " + std::to_string(e->getPosition().y));
				else if (e->getSymbol() == 'C') Files::writeDeathLog("Carnivore died at tick " + std::to_string(Ecosystem::getInstance().getTick()) + " eaten at position: " + std::to_string(e->getPosition().x) + ", " + std::to_string(e->getPosition().y));
                Ecosystem::getInstance().getGrid().removeEntity(e);
                creature->modifyEnergy(5);
				if (creature->getEnergy() >= 100) { // Check if energy is high enough to avoid overflow
                   creature->setEnergy(101);
                } 
                break;
            }
        }
    }
}

