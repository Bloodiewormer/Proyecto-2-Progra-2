#include "ClimateManager.h"

void ClimateManager::registerObserver(IObserver* obs){
	observers.push_back(obs);
}

void ClimateManager::removeObserver(IObserver* obs){
    for (int i = 0; i < observers.size(); ++i) {
        if (observers[i] == obs) {
            observers.erase(observers.begin() + i);
            break;
        }
    }
}

void ClimateManager::notifyClimateChange(const std::string& newClimate){
    currentClimate = newClimate;
    for (int i = 0; i < observers.size(); ++i) {
        observers[i]->onClimateChange(newClimate.c_str());
    }
}

void ClimateManager::notifySeasonChange(const std::string& newSeason){
    //currentSeason = newSeason;
    for (int i = 0; i < observers.size(); ++i) {
        observers[i]->onSeasonChange(newSeason.c_str());
    }
}

std::string ClimateManager::getClimate() const{
    return currentClimate;
}

//std::string ClimateManager::getSeason() const{
  //  return currentSeason;
//}
