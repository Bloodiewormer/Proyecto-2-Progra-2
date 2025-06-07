#include "Resource.h"

Resource::Resource(int x, int y, const std::string& type, int energyValue)
	: Entity(x, y,energyValue), type(type){
}

std::string Resource::getType() const {
    return type;
}

void Resource::update() {
   // Por ahora nada. Se puede extender para regenerate()
}



