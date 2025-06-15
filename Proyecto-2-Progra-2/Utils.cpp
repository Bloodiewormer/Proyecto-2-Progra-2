#include "Utils.h"

void Utils::clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void Utils::pause()
{
#ifdef _WIN32
	system("pause");
#else
	system("read -p \"Press Enter to continue...\""); // Unix-like systems
#endif
}

void Utils::sleep(int milliseconds)
{
#ifdef _WIN32
	Sleep(milliseconds); // Windows Sleep function
#else
	#include <unistd.h> // Unix-like systems
	usleep(milliseconds * 1000); // Convert milliseconds to microseconds
#endif
}



void Utils::ProgramColor()
{
#ifdef _WIN32
	system("color F1"); //F1 is light blue text on a white background
#else
	system("echo -e \"\\033[1;36m\\033[47m\""); // Set text color to light blue in Unix-like systems
#endif
}

int Utils::inputInt()
{
	int value;
	std::cin >> value;
	while (std::cin.fail()) {
		std::cin.clear(); // clear the error flag
		while (std::cin.get() != '\n'); // discard invalid input
		//throw InvalidInputException("Error: Entrada invalida. Por favor, ingrese un numero entero.");
	}
	return value;

}

double Utils::inputDouble()
{
	double value;
	std::cin >> value;
	while (std::cin.fail()) {
		std::cin.clear(); // clear the error flag
		while (std::cin.get() != '\n'); // discard invalid input
		//throw InvalidInputException("Error: Entrada invalida. Por favor, ingrese un numero decimal.");
	}
	return value;
}

std::string Utils::inputString()
{
	std::string value;
	while (std::cin.peek() == '\n' || std::cin.peek() == '\r') {
		std::cin.get();
	}
	//std::getline(std::cin, value);
	std::getline(std::cin, value);
	return value;
}

bool Utils::YesNo(std::string question)
{
	std::string answer;
	std::cout << question << " (y/n): ";
	std::getline(std::cin, answer);

	// Helper lambda to trim whitespace
	auto trim = [](std::string& s) {
		s.erase(0, s.find_first_not_of(" \t\r\n"));
		s.erase(s.find_last_not_of(" \t\r\n") + 1);//\t is tab, \r is carriage return, \n is newline
		};

	trim(answer);

	while (answer.size() != 1 || (tolower(answer[0]) != 'y' && tolower(answer[0]) != 'n')) {
		std::cout << "Invalid response. Please enter 'y' or 'n': ";
		std::getline(std::cin, answer);
		trim(answer);
	}
	return (tolower(answer[0]) == 'y');
}

double Utils::Random()
{
	srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
	return static_cast<double>(rand()) / RAND_MAX; // Return a random double between 0 and 1
}

