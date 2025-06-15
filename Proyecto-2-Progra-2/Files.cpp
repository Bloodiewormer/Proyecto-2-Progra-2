#include "Files.h"

void Files::saveGame( int seed, int ticks)
{
	std::ofstream file("save.txt");
	if (file.is_open()) {
		file << seed << "\n" << ticks << "\n";
		
		file.close();
	}
	else {
		std::cerr << "Error opening file for saving game." << std::endl;
	}
}

std::string* Files::loadGame()
{
	std::ifstream saveFile("save.txt");
	if (!saveFile.is_open()) {
		std::cerr << "Error opening save file " << std::endl;
		return nullptr; // Save file does not exist
	}

	int seed, ticks;
	saveFile >> seed >> ticks;

	if (saveFile.fail()) {
		std::cerr << "Error reading data from save file." << std::endl;
		saveFile.close();
		return nullptr; // Return nullptr if reading fails
	}
	saveFile.close();

	std::string* SaveStates = new std::string[2]; // Array to hold the save states
	SaveStates[0] = std::to_string(seed); // Save the seed
	SaveStates[1] = std::to_string(ticks); // Save the ticks
	return SaveStates;
}

void Files::deleteSave()
{
	std::string filename = "save.txt";
	std::remove(filename.data()); // Remove the save file 
	std::cout << "Deleted save file: " << filename << std::endl;
}

void Files::deleteDeathLog()
{
    
    std::string logFilename = "log.txt";
    std::remove(logFilename.data()); // Remove the log file
	std::cout << "Deleted death log file: " << logFilename << std::endl;
}



std::string Files::readDeathLog() 
{
	//the log will have this format
	// # Creature Death
	//-Herbivore died at tick34 eaten at position : 9, 4
	//-Herbivore died at tick51 eaten at position : 0, 0
	//-Omnivore died at tick62 eaten at position : 0, 1
	//- erbivore died of starvation at position(0, 1)

	//do not read the User Input section, just the Creature Death section
	//use sstream to return the string with the creature death information
	std::ifstream file("log.txt");
	if (!file.is_open()) {
		std::cerr << "Error opening log file." << std::endl;
		return ""; // Return empty string if the file cannot be opened
	}

	std::string line;
	std::string deathLog;
	while (std::getline(file, line)) {
		if (line.find("Creature Death") != std::string::npos) {
			// Skip the header line
			continue;
		}
		if (line.find("-") == 0) { // Check if the line starts with '-'
			deathLog += line + "\n"; // Append the death information to the log
		}
	}
	file.close();

	return deathLog; // Return the accumulated death log

	


}

void Files::writeDeathLog(const std::string& deathInfo)
{
	std::ofstream file("log.txt", std::ios::app); // Open in append mode
	if (file.is_open()) {
		file << "- " << deathInfo << "\n"; // Write the death information
		file.close();
	}
	else {
		std::cerr << "Error opening log file for writing." << std::endl;
	}
}
