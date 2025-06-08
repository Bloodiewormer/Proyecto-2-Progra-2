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
        grid.draw();
        grid.updateAll();

		//vector<Animal*> animals = grid.getAnimals();
        std::vector<Entity*> creatures = grid.getEntities();

		std::cout << "Total Creatures: " << creatures.size() << "\n";
        for(Entity* creature : creatures) {
			if (creature->getSymbol() != 'G') {
				std::cout << "================\n";
				creature->draw();
			}
		}
		std::cout << "================\n";
       


        std::cout << "\n";
		//Utils::sleep(1000); // Sleep for 1 second
        Utils::pause();
		Utils::clearScreen();
    }
}