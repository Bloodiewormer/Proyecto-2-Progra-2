#pragma once
#include "IFeedingStrategy.h"
#include "Creature.h"
#include "Ecosystem.h"
#include "Resource.h"

#include "Files.h"
class CarnivoreFeeding : public IFeedingStrategy{
public:
    void feed(Creature* creature) override;
};

