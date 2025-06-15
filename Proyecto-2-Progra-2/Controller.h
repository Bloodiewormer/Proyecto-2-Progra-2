#pragma once
#include "Menu.h"
#include "Utils.h"
#include "Ecosystem.h"
#include "EntityFactory.h"
#include "UI.h"
#include "Files.h"
class Controller
{
	public :
	Controller() = default;
	~Controller() = default;
	void run();
	void showMenu();
	bool load();
	void createInitialEntities();
};

