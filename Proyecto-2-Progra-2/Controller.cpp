#include "Controller.h"

void Controller::run()
{
	UI::showWelcomeBanner(); // Show welcome banner

	Ecosystem& eco = Ecosystem::getInstance();

	
    // Ask if the user wants to load a previous simulation
    if (Utils::YesNo("Do you want to load last saved simulation?")) {
        if (!load()) {
            std::cout << "No saved game found. Creating new simulation." << std::endl;
            unsigned int seed = static_cast<unsigned int>(time(nullptr)); // Use current time as seed
            eco.setSeed(seed);
            srand(seed);
            std::cout << "Using seed: " << eco.getSeed() << std::endl;
            createInitialEntities();
            Utils::pause();
        }
    } else {
		Files::deleteDeathLog(); // Clear the death log if not loading a game
		Files::deleteSave(); // Clear the save file if not loading a game
        std::cout << "Introduce seed for random generator?" << std::endl;
        std::cout << " (0) for random seed" << std::endl;
        int seed = Utils::inputInt();
        if (seed == 0) {
            unsigned int newSeed = static_cast<unsigned int>(time(nullptr));
            eco.setSeed(newSeed);
            srand(newSeed);
        } else {
            eco.setSeed(static_cast<unsigned int>(seed));
            srand(static_cast<unsigned int>(seed));
        }
        std::cout << "Using seed: " << eco.getSeed() << std::endl;
		Utils::pause();
        createInitialEntities();
    }

    showMenu();
    // Run the ecosystem for a specified number of ticks
}

void Controller::showMenu()
{
    
    
    Menu* mainMenu = new Menu("Main Menu");

    // Modify parameter example
    mainMenu->add(new MenuItem("Run for 10 ticks", []() {
        std::cout << " ";
		Utils::clearScreen();
        Ecosystem::getInstance().run(10); // Implement setSpeed in Ecosystem if needed
        }));

    // Run simulation for X ticks
    mainMenu->add(new MenuItem("Run Simulation for X Ticks", []() {
        std::cout << "Enter number of ticks: ";
        int ticks = Utils::inputInt();
        Utils::clearScreen();
        Ecosystem::getInstance().run(ticks);
        }));

    // Visualize current creatures
    mainMenu->add(new MenuItem("Visualize Creatures", []() {
		std::vector<Entity*> creatures = Ecosystem::getInstance().getGrid().getEntities();
		int totalCreatures = creatures.size();

        for (Entity* creature : creatures) {
            if (creature->getSymbol() != 'G') {
				totalCreatures--;
            }
        }

        std::cout << "Total Creatures: " << totalCreatures << "\n";
        for (Entity* creature : creatures) {
            if (creature->getSymbol() != 'G') {
                std::cout << "================\n";
                creature->draw();
            }
        }
        std::cout << "================\n";
        Utils::pause();
        }));

	// save the current state of the simulation
    mainMenu->add(new MenuItem("Save Simulation", []() {
        Utils::clearScreen();
        Ecosystem& eco = Ecosystem::getInstance();
        int currentTick = eco.getTick();
        std::cout << "Saving simulation at tick: " << currentTick << "\n";
		Files::saveGame(eco.getSeed(), currentTick); // Save the game state to a file
        Utils::pause();
	}));

	// read log of dead creatures
    mainMenu->add(new MenuItem("Read Log of Dead Creatures", []() {
        Utils::clearScreen();
		std::string deahLog = Files::readDeathLog();
        if (deahLog.empty()) {
            std::cout << "No death log found.\n";
        } else {
			std::cout << "Death Log:\n" << deahLog << "\n";
        }
		Utils::pause();
		}));

// add a new creature (this works but need to create a log that saves the tick for user input and the create a form of how to load that from that log)
 //   mainMenu->add(new MenuItem("Add New Creature", []() {
 //       Utils::clearScreen();
 //       std::cout << "Choose type of creature to add:\n";
 //       std::cout << "1. Herbivore\n";
 //       std::cout << "2. Carnivore\n";
 //       std::cout << "3. Omnivore\n";
 //       std::cout << "4. Grass\n";
 //       int choice = Utils::inputInt();
 //       
 //       Grid& grid = Ecosystem::getInstance().getGrid();
 //       Entity* newCreature = nullptr;
 //       
 //       switch (choice) {
 //           case 1: newCreature = EntityFactory::createHerbivore(grid.getUnoccupiedPosition()); break;
 //           case 2: newCreature = EntityFactory::createCarnivore(grid.getUnoccupiedPosition()); break;
 //           case 3: newCreature = EntityFactory::createOmnivore(grid.getUnoccupiedPosition()); break;
 //           case 4: newCreature = EntityFactory::createGrass(grid.getUnoccupiedPosition()); break;
 //           default: std::cout << "Invalid choice.\n"; return;
 //       }
 //       
 //       grid.placeEntity(newCreature);
 //	std::cout << "New creature added successfully.\n";
 //       Utils::pause();
	//}));

    // Exit
    mainMenu->add(new MenuItem("Exit", []() {
        Utils::clearScreen();
        std::cout << "Exiting...\n";
        exit(0);
    }));


    // Execute the main menu
    mainMenu->execute();

    // Clean up memory
    delete mainMenu;
}

bool Controller::load()
{
   Ecosystem& eco = Ecosystem::getInstance();
   std::string* data = Files::loadGame();
   if (data == nullptr) {
       std::cout << "No saved game found." << std::endl;
	   return false;
   }
   unsigned int seed = 0;
   try {
       seed = std::stoul(data[0]); // Convert std::string to unsigned int
       if (seed == 0) {
		   
           seed = static_cast<unsigned int>(time(nullptr)); // Use current time as seed if 0
       }
   }
   catch (const std::invalid_argument& e) {
       std::cerr << "Invalid seed value in saved game: " << data[0] << std::endl;
       return false;
   }
   catch (const std::out_of_range& e) {
       std::cerr << "Seed value out of range: " << data[0] << std::endl;
       return false;
   }
   Files::deleteDeathLog(); // Clear the death log if not loading a game
   srand(seed);
   eco.setSeed(seed); // Set the seed in Ecosystem
   createInitialEntities(); // Create initial entities after loading
   std::cout << "Loaded seed: " << seed << std::endl;
   int tickCount = std::stoi(data[1]); // Convert std::string to int
   eco.jumpToTick(tickCount); // Jump to the tick count
   return true;
}



void Controller::createInitialEntities(){
    Ecosystem& eco = Ecosystem::getInstance();
    Grid& grid = eco.getGrid();
    Entity* h1 = EntityFactory::createHerbivore(grid.getUnoccupiedPosition());
    Entity* h2 = EntityFactory::createHerbivore(grid.getUnoccupiedPositionNear(h1->getPosition().x, h1->getPosition().y));
    Entity* c1 = EntityFactory::createCarnivore(grid.getUnoccupiedPosition());
    Entity* c2 = EntityFactory::createCarnivore(grid.getUnoccupiedPositionNear(c1->getPosition().x, c1->getPosition().y));
    Entity* o1 = EntityFactory::createOmnivore(grid.getUnoccupiedPosition());
    Entity* o2 = EntityFactory::createOmnivore(grid.getUnoccupiedPositionNear(o1->getPosition().x, o1->getPosition().y));
    Entity* p1 = EntityFactory::createGrass(grid.getUnoccupiedPosition());
    Entity* p2 = EntityFactory::createGrass(grid.getUnoccupiedPosition());
    Entity* p3 = EntityFactory::createGrass(grid.getUnoccupiedPosition());
    Entity* p4 = EntityFactory::createGrass(grid.getUnoccupiedPosition());
    grid.placeEntity(h1);
    grid.placeEntity(c1);
    grid.placeEntity(o1);
    grid.placeEntity(h2);
    grid.placeEntity(c2);
    grid.placeEntity(o2);
    grid.placeEntity(p1);
    grid.placeEntity(p2);
}
