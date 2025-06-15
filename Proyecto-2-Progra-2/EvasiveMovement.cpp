#include "EvasiveMovement.h"

void EvasiveMovement::move(Creature* creature) {
    Position current = creature->getPosition();
    Entity* closest = nullptr;
    int minDist = 1000000; // Arbitrary large number to represent "infinity"

    // Find the closest other creature of a different type (species)
    for (auto* e : Ecosystem::getInstance().getGrid().getEntities()) {
        if (e != creature) {
            Creature* other = dynamic_cast<Creature*>(e);
            if (other && typeid(*other) != typeid(*creature)) {
                int dx = e->getPosition().x - current.x;
                int dy = e->getPosition().y - current.y;
                int dist = dx * dx + dy * dy;
                if (dist < minDist) {
                    minDist = dist;
                    closest = e;
                }
            }
        }
    }

	// Set a threshold distance (squared) for evasion, e.g., 4 units away (4*4= 16)
    const int EVADE_DISTANCE_SQ = 16;

    int dx = 0, dy = 0;
    if (closest && minDist <= EVADE_DISTANCE_SQ) {
        // Move away from the closest creature of a different species
        dx = (closest->getPosition().x < current.x) ? 1 : (closest->getPosition().x > current.x ? -1 : 0);
        dy = (closest->getPosition().y < current.y) ? 1 : (closest->getPosition().y > current.y ? -1 : 0);
    }
    else {
        // No close creatures of different species found, move randomly
        dx = rand() % 3 - 1;
        dy = rand() % 3 - 1;
    }

    int newX = current.x + dx;
    int newY = current.y + dy;

    // Clamp to grid bounds
    if (newX < 0) newX = 0;
    if (newY < 0) newY = 0;
    if (newX >= GRID_SIZE) newX = GRID_SIZE - 1;
    if (newY >= GRID_SIZE) newY = GRID_SIZE - 1;

    Ecosystem::getInstance().getGrid().moveEntity(creature, newX, newY);
}