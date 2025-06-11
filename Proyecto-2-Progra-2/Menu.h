#pragma once
#include <vector>
#include <string>
#include <functional>
#include <iostream>

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
    MenuItem(const std::string& name, std::function<void()> action)
        : name(name), action(action) {
    }
    void display(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << std::endl;
    }
    void execute() override {
        if (action) action();
    }
};

class Menu : public MenuComponent {
    std::string name;
    std::vector<MenuComponent*> items;
public:
    Menu(const std::string& name) : name(name) {}
    ~Menu() {
        for (size_t i = 0; i < items.size(); ++i) {
            delete items[i];
        }
    }
    void add(MenuComponent* item) {
        items.push_back(item);
    }
    void display(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << name << std::endl;
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << std::string(indent + 2, ' ') << (i + 1) << ". ";
            items[i]->display();
        }
    }
    void execute() override {
        while (true) {
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
};
