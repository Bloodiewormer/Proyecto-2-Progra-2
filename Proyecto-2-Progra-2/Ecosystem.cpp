#include "Ecosystem.h"

Ecosystem* Ecosystem::getInstance()
{
	if (instance == nullptr) {
		instance = new Ecosystem();
	}
	return instance;
}
