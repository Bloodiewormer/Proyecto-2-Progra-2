#include "Creature.h"
#include <cstring>

Creature::Creature(int x, int y) :Entity(x, y), age(0) {
    movement = nullptr; // Initialize movement strategy to nullptr
    feeding = nullptr; // Initialize feeding strategy to nullptr
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(Position p) : Entity(p.x, p.y), age(0) {
    movement = nullptr; // Initialize movement strategy to nullptr
    feeding = nullptr; // Initialize feeding strategy to nullptr
    energy = 100; // Default energy value
    age = 0; // Default age value
}

Creature::Creature(const Creature& other) : Entity(other.position.x, other.position.y, other.energy), age(other.age) {
    movement = other.movement; // shallow copy for simplicity  
    feeding = other.feeding; // shallow copy for simplicity  
    energy = other.energy; // Ensure energy is copied  
    age = other.age; // Initialize age explicitly  
}

Creature& Creature::operator=(const Creature& other)
{
    if (this != &other) {
        position = other.position;
        energy = other.energy;
        movement = other.movement;
        feeding = other.feeding; // shallow copy for simplicity
    }
    return *this;
}


void Creature::update() {
    if (movement) movement->move(this);
    if (feeding) feeding->feed(this);//
    energy--;
    //if(season =="summer") energy--; // Example condition for energy consumption
    age++;

    /*
    reproduction->reproduce(this);*/
}

void Creature::setMovementStrategy(IMovementStrategy* m)
{
    movement = m;
}

void Creature::setFeedingStrategy(IFeedingStrategy* f)
{
    feeding = f;
}

int Creature::getAge() const {
    return age;
}

void Creature::onSeasonChange(const char* newSeason){
    if (strcmp(newSeason, "primavera") == 0) seasonBoost = 10;
    else if (strcmp(newSeason, "verano") == 0) seasonBoost = 5;
    else if (strcmp(newSeason, "otonio") == 0) seasonBoost = 3;
    else if (strcmp(newSeason, "invierno") == 0) seasonBoost = -5;
    else seasonBoost = 0;
}

void Creature::onClimateChange(const char* newClimate){
    if (strcmp(newClimate, "soleado") == 0) climateBoost = 5;
    else if (strcmp(newClimate, "lluvioso") == 0) climateBoost = 3;
    else if (strcmp(newClimate, "nuboso") == 0) climateBoost = 1;
    else if (strcmp(newClimate, "seco") == 0) climateBoost = -3;
    else climateBoost = 0;
}

int Creature::getSeasonBoost() const{
    return seasonBoost;
}

int Creature::getClimateBoost() const{
    return seasonBoost;
}

