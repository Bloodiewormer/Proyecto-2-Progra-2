#pragma once
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
// this will work whit 3 slots
//will salve the seed for the random number generator
//also salve the tiks for the game
// and a log for the deaths of creatures 
// also will ssalve a log for the tinks the user has made for example the decorator and at what tick 
class Files //ask for the slot to save the game
{
	public:
	Files() = default;
	~Files() = default;
	// Function to save the game state
	static void saveGame(int seed, int ticks);
	// Function to load the game state
	static std::string* loadGame(); // Returns a pointer to an array of strings containing the game state so it will be like this : // [0] = seed, [1] = ticks
	// Function to delete a saved game
	static void deleteSave();
	static void deleteDeathLog();
	// Function to check if a save slot is empty
	static std::string readDeathLog();

	static void writeDeathLog(const std::string& deathInfo);


};

