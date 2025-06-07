#include "TargetedMovement.h"
#include "Resource.h"
#include "Creature.h"


void TargetedMovement::move(Creature* creature) {
    Position current = creature->getPosition();
    Entity* closest = nullptr;
    int minDist = std::numeric_limits<int>::max();

    for (auto* e : Ecosystem::getInstance().getGrid().getEntities()) {
        if (e != creature && dynamic_cast<Resource*>(e)) {
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
