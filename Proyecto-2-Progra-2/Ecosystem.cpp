#include "Ecosystem.h"


Ecosystem* Ecosystem::instance = nullptr;

void Ecosystem::cycleSeason(){
    const char* seasons[] = { "primavera", "verano", "otonnio", "invierno" };
    int seasonIndex = 1;
	seasonIndex = (tick / 5) % 4; // Calculate the current season index based on the tick count
    climateManager.notifySeasonChange(seasons[seasonIndex]);
}

void Ecosystem::cycleClimate()
{
    const char* climates[] = { "soleado", "lluvioso", "nuboso", "seco" };
    int climateIndex = rand() % 4; // Randomly select climate for the current season
    climateManager.notifyClimateChange(climates[climateIndex]);
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
            cycleSeason();  // <-- Solo añade esta línea
        }
        if (tick % 2 == 0) {
            cycleClimate(); // Cambia el clima cada 2 ticks
		}
		std::cout << climateManager.getSeason() << std::endl;
        std::cout << climateManager.getClimate()<<std::endl;
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

ClimateManager& Ecosystem::getClimateManager(){
	return climateManager;
}
