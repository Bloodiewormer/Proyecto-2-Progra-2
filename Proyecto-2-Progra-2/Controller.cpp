#include "Controller.h"

void Controller::run()
{
    std::cout << "Introduce seed for random generator?" << std::endl;
    std::cout << " (0) for random seed" << std::endl;
    int seed = Utils::inputInt();
    if (seed == 0) {
        seed = static_cast<unsigned int>(time(nullptr));
        srand(seed); // use current time as seed
    }
    else {
        srand(static_cast<unsigned int>(seed)); // use user provided seed
    }

    std::cout << "Using seed: " << seed << std::endl;


    Ecosystem& eco = Ecosystem::getInstance();
    Grid& grid = eco.getGrid();

    Entity* h1 = EntityFactory::createHerbivore(grid.getUnoccupiedPosition());
    Entity* h2 = EntityFactory::createHerbivore(grid.getUnoccupiedPosition());
    Entity* c1 = EntityFactory::createCarnivore(grid.getUnoccupiedPosition());
    Entity* c2 = EntityFactory::createCarnivore(grid.getUnoccupiedPosition());
    Entity* o1 = EntityFactory::createOmnivore(grid.getUnoccupiedPosition());
    Entity* o2 = EntityFactory::createOmnivore(grid.getUnoccupiedPosition());
    Entity* p1 = EntityFactory::createGrass(grid.getUnoccupiedPosition());
    Entity* p2 = EntityFactory::createGrass(grid.getUnoccupiedPosition());

    grid.placeEntity(h1);
    grid.placeEntity(c1);
    grid.placeEntity(o1);
    grid.placeEntity(h2);
    grid.placeEntity(c2);
    grid.placeEntity(o2);
    grid.placeEntity(p1);
    grid.placeEntity(p2);

    while 
		(true) {
		Utils::clearScreen();
		std::cout << "Ecosystem Simulation\n";
		std::cout << "====================\n";
		std::cout << "Tick: " << eco.getTick() << "\n";
		std::cout << "Season: " << eco.getSeasonManager().getData() << "\n";
		std::cout << "Climate: " << eco.getClimateManager().getData() << "\n";
		grid.draw();
		showMenu();
		// Run the ecosystem for a specified number of ticks
	}
}

void Controller::showMenu()
{
    Menu* mainMenu = new Menu("Main Menu");

    // Modify parameter example
    mainMenu->add(new MenuItem("Run for 10 ticks", []() {
        std::cout << " ";
        int speed = Utils::inputInt();

        Ecosystem::getInstance().run(10); // Implement setSpeed in Ecosystem if needed
        }));

    // Run simulation for X ticks
    mainMenu->add(new MenuItem("Run Simulation for X Ticks", []() {
        std::cout << "Enter number of ticks: ";
        int ticks = Utils::inputInt();
        Ecosystem::getInstance().run(ticks);
        }));

    // Visualize current creatures
    mainMenu->add(new MenuItem("Visualize Creatures", []() {
		std::vector<Entity*> creatures = Ecosystem::getInstance().getGrid().getEntities();

        std::cout << "Total Creatures: " << creatures.size() << "\n";
        for (Entity* creature : creatures) {
            if (creature->getSymbol() != 'G') {
                std::cout << "================\n";
                creature->draw();
            }
        }
        std::cout << "================\n";
        }));

    // Exit
    mainMenu->add(new MenuItem("Exit", []() {
        std::cout << "Exiting...\n";
        exit(0);
        }));

    mainMenu->execute();

    // Clean up memory
    delete mainMenu;
}
