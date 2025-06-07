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
	static int InputInt();
	static double InputDouble();
	static std::string InputString();
	static double Random();
};




