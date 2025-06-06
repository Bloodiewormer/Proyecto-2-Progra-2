#pragma once
#include "Creature.h"
#include "ClimateManager.h"
#include <iostream>

class CreatureObserver : public Creature, public IObserver {
public:
    CreatureObserver(int x, int y, IMovementStrategy* m) : Creature(x, y, m) {}
    void onSeasonChange(const char* season) override {
        std::cout << "Creature at (" << position.x << ", " << position.y << ") noticed season change: " << season << "\n";
    }
};
