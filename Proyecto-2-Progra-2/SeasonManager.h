#pragma once
#include <string>
#include <vector>

class SeasonManager {
private:
    std::vector<std::string> seasons;
    int currentIndex;

public:
    SeasonManager();

    std::string getSeason() const;
    void nextSeason();
};


