#include "Ecosystem.h"


Ecosystem* Ecosystem::instance = nullptr;

void Ecosystem::cycleEnvironment(){
    // Ciclo simple cada 5 ticks
    const char* seasons[] = { "primavera", "verano", "otonio", "invierno" };
    const char* climates[] = { "soleado", "lluvioso", "nuboso", "seco" };

    int seasonIndex = (tick / 5) % 4;
    int climateIndex = (tick / 5) % 4;

    climateManager.notifySeasonChange(seasons[seasonIndex]);
    climateManager.notifyClimateChange(climates[climateIndex]);

    std::cout << ">> Estación actual: " << seasons[seasonIndex] << "\n";
    std::cout << ">> Clima actual: " << climates[climateIndex] << "\n";
}

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

        // Ciclo de estación y clima cada 5 ticks
        if (tick % 5 == 1) {
            cycleEnvironment();  // <-- Solo añade esta línea
        }

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