#include "Menu.h"

MenuItem::MenuItem(const std::string& name, std::function<void()> action)
    : name(name), action(action) {
}

void MenuItem::display(int indent) const
{
    std::cout << std::string(indent, ' ') << name << std::endl;
}

void MenuItem::execute()
{
    if (action) action();
}

Menu::Menu(const std::string& name) : name(name) {}

Menu::~Menu()
{
    for (size_t i = 0; i < items.size(); ++i) {
        delete items[i];
    }
}

void Menu::add(MenuComponent* item)
{
    items.push_back(item);
}

void Menu::display(int indent) const
{
    std::cout << std::string(indent, ' ') << name << std::endl;
    for (size_t i = 0; i < items.size(); ++i) {
        std::cout << std::string(indent + 2, ' ') << (i + 1) << ". ";
        items[i]->display();
    }
}

void Menu::execute()
{
    while (true) {
        displayHeader();
        display();
        std::cout << "Select option (0 to return): ";
        int choice;
        std::cin >> choice;
        if (choice == 0) break;
        if (choice > 0 && choice <= static_cast<int>(items.size())) {
            items[choice - 1]->execute();
        }
    }
}

void Menu::displayHeader() const
{

    Utils::clearScreen();
    Ecosystem& eco = Ecosystem::getInstance();
    Grid& grid = eco.getGrid();
    std::cout << "Ecosystem Simulation\n";
    std::cout << "====================\n";
    std::cout << "Tick: " << eco.getTick() << "\n";
    std::cout << "Season: " << eco.getSeasonManager().getData() << "\n";
    std::cout << "Climate: " << eco.getClimateManager().getData() << "\n";
    grid.draw();
}
