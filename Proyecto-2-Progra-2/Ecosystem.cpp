#include "Ecosystem.h"


Ecosystem* Ecosystem::instance = nullptr;

Ecosystem& Ecosystem::getInstance()
{
	if (instance == nullptr) {
		instance = new Ecosystem();
	}
	return *instance;
}

void Ecosystem::run(int maxTicks) {
    for (int i = 0; i < maxTicks; ++i) {
        tick++;
        std::cout << "Tick: " << tick << "\n";
        grid.updateAll();
        grid.draw();
        std::cout << "\n";
        system("pause");
    }
}