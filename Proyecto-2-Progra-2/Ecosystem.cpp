#include "Ecosystem.h"


Ecosystem* Ecosystem::instance = nullptr;

void Ecosystem::cycleSeason(){
    const char* seasons[] = { "primavera", "verano", "otonnio", "invierno" };
    int seasonIndex = 1;
	seasonIndex = (tick / 5) % 4; // Calculate the current season index based on the tick count
    //climateManager.notifySeasonChange(seasons[seasonIndex]);
	seasonManager.setSeason(seasons[seasonIndex]);
}

void Ecosystem::cycleClimate()
{
    const char* climates[] = { "soleado", "lluvioso", "nuboso", "seco" };
    int climateIndex = rand() % 4; // Randomly select climate for the current season
	climateManager.setClimate(climates[climateIndex]);
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
		std::cout << seasonManager.getData() << std::endl;
        std::cout << climateManager.getData()<<std::endl;
        grid.draw();
        grid.updateAll();


        std::cout << "\n";
		//Utils::sleep(1000); // Sleep for 1 second
        Utils::pause();
		Utils::clearScreen();
    }
}

void Ecosystem::jumpToTick(int targetTick)
{
    for (int i = 0; i < targetTick; ++i) {
        tick++;


        if (tick % 5 == 1) {
            cycleSeason(); 
        }
        if (tick % 2 == 0) {
            cycleClimate(); // Cambia el clima cada 2 ticks
        }
        grid.updateAll();
    }
}

ClimateManager& Ecosystem::getClimateManager(){
	return climateManager;
}

SeasonManager& Ecosystem::getSeasonManager(){
	return seasonManager;
}
