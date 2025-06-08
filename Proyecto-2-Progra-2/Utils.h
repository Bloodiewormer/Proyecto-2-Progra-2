#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class Utils
{
public:
	static void clearScreen();
	static void pause();
	static void sleep(int milliseconds);
	static void ProgramColor();
	static int inputInt();
	static double inputDouble();
	static std::string inputString();
	static double Random();
};




