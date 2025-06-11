#pragma once
#include "Menu.h"
#include "Utils.h"
#include "Ecosystem.h"
#include "EntityFactory.h"
#include "UI.h"
class Controller
{
	public :
	Controller() = default;
	~Controller() = default;
	void run();
	void showMenu();
	void menuSaveSlots();
	
};

