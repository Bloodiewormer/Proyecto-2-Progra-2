#include "CreatureDecorator.h"

CreatureDecorator::CreatureDecorator(Creature* base) 
	: Creature(base->getPosition(), nullptr, nullptr, nullptr, base->getEnergy()) {}

CreatureDecorator::~CreatureDecorator(){
	delete baseCreature;
}

void CreatureDecorator::update(){
	baseCreature->update();
}
