#include "SeasonManager.h"

SeasonManager::SeasonManager() {
    seasons = { "primavera", "verano", "otonio", "invierno" };
    currentIndex = 0;
}

std::string SeasonManager::getSeason() const {
    return seasons[currentIndex];
}

void SeasonManager::nextSeason() {
    currentIndex = (currentIndex + 1) % seasons.size();
}

