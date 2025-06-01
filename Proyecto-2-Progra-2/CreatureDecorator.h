#pragma once
#include"Creature.h"
class CreatureDecorator : public Creature{
protected:
	Creature* baseCreature;

public:
	CreatureDecorator(Creature* base);
	virtual ~CreatureDecorator();

	virtual void update() override;
};

