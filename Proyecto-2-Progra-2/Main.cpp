#include <iostream>
#include "Utils.h"
//std::cout << "+-----------------------------------------------------+" << std::endl;
//std::cout << "|                                                     |" << std::endl;
//std::cout << "| (c) 2025                                            |" << std::endl;
//std::cout << "| EIF204 - Programaci�n 2                             |" << std::endl;
//std::cout << "| 1er ciclo 2025                                      |" << std::endl;
//std::cout << "| NRC 41370 � Grupo 00                                 |" << std::endl;
//std::cout << "| Proyecto 1                                          |" << std::endl;
//std::cout << "|                                                     |" << std::endl;
//std::cout << "| 2-0854-0087; David Alberto Gonzalez Cordoba         |" << std::endl;
//std::cout << "| 4-0243-0410; Marisol Quiros Viquez                  |" << std::endl;
//std::cout << "|                                                     |" << std::endl;
//std::cout << "| versi�n 1.0.0 2025-04-01                            |" << std::endl;
//std::cout << "|                                                     |" << std::endl;
//std::cout << "+-----------------------------------------------------+" << std::endl;
int main() {
	Utils::ProgramColor(); // set color to console

}

/// <Notas>/// 
//Funcionamiento del programa: simulacion de ecosistema
// El programa se manejara por tics, cada segundo se aumentara en 1
// cada 20 tics se pasara a la siguente estacion
// comportamiento de los animales:
// - los herbivoros se alimentan de la hierba, se mueven para buscarla, huyen de los depredadores y se reproduciran solo si hay suficiente comida y un compa�ero
// - los carn�voros se alimentan de los herb�voros, persiguen a los herb�voros, muy agresivos, se reproduciran si ve a un compa�ero
// - los omn�voros se alimentan de la hierba y de los herb�voros, puede tanto buscar como evitar y se reproduciran de manera al azar si hay un compa�ero

// cada tic puede crecer una planta si hay suficiente agua y luz con una probabilidad editable por el usuario
//criaturas se reproduciran si hay suficiente comida y un compa�ero, edad > 5 tics, y si no hay depredadores cerca con una probabilidad editable por el usuario
//carnivoro encuentra a herbivoro  si esta cerca y tiene hambre, lo mata y se lo come, si no tiene hambre no lo mata
//omnivoro elige entre comer hierba o herbivoro, si hay ambos, come lo que mas le convenga, si no hay ninguno, no come

//cada tick aumenta un contador global
//se verifica si el contador es multiplo de 20, si lo es, se cambia la estacion
//se actualiza todos los entity con update (patron observer)
//se elimina los animale con energia <= 0
//Se regeneran recursos si se cumplen condiciones (sol, agua, estaci�n).

//se puede pausar el programa en cualquier momento para  ver el estado actual del ecosistema

