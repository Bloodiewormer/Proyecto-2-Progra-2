#include "UI.h"

void UI::showWelcomeBanner()
{
	std::cout << "+-----------------------------------------------------+" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| (c) 2025                                            |" << std::endl;
	std::cout << "| EIF204 - Programación 2                             |" << std::endl;
	std::cout << "| 1er ciclo 2025                                      |" << std::endl;
	std::cout << "| NRC 41370 – Grupo 00                                |" << std::endl;
	std::cout << "| Proyecto 1                                          |" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| 2-0854-0087; David Alberto Gonzalez Cordoba         |" << std::endl;
	std::cout << "| 4-0243-0410; Marisol Quiros Viquez                  |" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "| versión 1.0.0 2025-04-01                            |" << std::endl;
	std::cout << "|                                                     |" << std::endl;
	std::cout << "+-----------------------------------------------------+" << std::endl;
	Utils::pause();
	Utils::clearScreen();

}
