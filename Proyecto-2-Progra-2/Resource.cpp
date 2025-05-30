#include "Resource.h"

Resource::Resource(Position pos, const std::string& type, int energyValue, int regen)
    : Entity(pos, energyValue), type(type), regenerationTimer(regen) {
}

std::string Resource::getType() const {
    return type;
}

void Resource::update() {
    // Por ahora nada. Se puede extender para regenerate()
}

