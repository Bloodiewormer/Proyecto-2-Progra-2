#include "TargetedMovement.h"



void TargetedMovement::move(Creature* creature) {
    Position current = creature->getPosition();
    Entity* closest = nullptr;
    int minDist = 1000000; // Arbitrary large number to represent "infinity"

    for (auto* e : Ecosystem::getInstance().getGrid().getEntities()) {
        // Exclude self and all entities of the same dynamic type as the creature
        if (e != creature && dynamic_cast<Resource*>(e) && typeid(*e) != typeid(*creature)) {
            int dx = e->getPosition().x - current.x;
            int dy = e->getPosition().y - current.y;
            int dist = dx * dx + dy * dy;
            if (dist < minDist) {
                minDist = dist;
                closest = e;
            }
        }
    }

    if (closest) {
        int dx = (closest->getPosition().x > current.x) ? 1 : (closest->getPosition().x < current.x ? -1 : 0);
        int dy = (closest->getPosition().y > current.y) ? 1 : (closest->getPosition().y < current.y ? -1 : 0);
        Ecosystem::getInstance().getGrid().moveEntity(creature, current.x + dx, current.y + dy);
    }
}
