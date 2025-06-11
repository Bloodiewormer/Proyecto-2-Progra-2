#include "EnvironmentManager.h"

void EnvironmentManager::notifyClimateChange(const std::string& newClimate)
{
    for (IObserver* obs : observers) {
        obs->onClimateChange(newClimate);
    }
}

void EnvironmentManager::notifySeasonChange(const std::string& newSeason)
{
    for (IObserver* obs : observers) {
        obs->onClimateChange(newSeason);
    }
}

void EnvironmentManager::registerObserver(IObserver* obs)
{
    for (int i = 0; i < observers.size(); ++i) {
        if (observers[i] == obs) {
            return; // Observer already registered
        }
    }
	observers.push_back(obs);
}

void EnvironmentManager::removeObserver(IObserver* obs)
{
    for (size_t i = 0; i < observers.size(); ++i) {
        if (observers[i] == obs) {
            observers.erase(observers.begin() + i);
            return;
        }
    }
}

void ClimateManager::setClimate(const std::string& newClimate)
{
    if(currentClimate != newClimate) {
        currentClimate = newClimate;
        notifyClimateChange(newClimate);
    }
}

std::string ClimateManager::getData() const
{
	return currentClimate;
}

void SeasonManager::setSeason(const std::string& newSeason)
{
    if (currentSeason != newSeason) {
        currentSeason = newSeason;
        notifySeasonChange(newSeason);
    }
}

std::string SeasonManager::getData() const
{
	return currentSeason;
}