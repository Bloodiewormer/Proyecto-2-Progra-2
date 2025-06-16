#pragma once
#include <vector>
#include <string>
#include <functional>
#include <iostream>


#include "Ecosystem.h"
#include "Utils.h"



class MenuComponent {
public:
    virtual ~MenuComponent() = default;
    virtual void display(int indent = 0) const = 0;
    virtual void execute() = 0;
};

class MenuItem : public MenuComponent {
    std::string name;
    std::function<void()> action;
public:
    MenuItem(const std::string& name, std::function<void()> action);
        
    void display(int indent = 0) const override;
    void execute() override;

};

class Menu : public MenuComponent {
    std::string name;
    std::vector<MenuComponent*> items;
public:
    Menu(const std::string& name);
    ~Menu();
    void add(MenuComponent* item);
    void display(int indent = 0) const override;
    void execute() override;

    void displayHeader() const;


};
