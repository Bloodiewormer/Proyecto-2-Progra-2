#pragma once
#include<iostream>
#include<string>
#include <vector>

#include"SeasonManager.h"

class IObserver {
public:
    virtual void onClimateChange(const char* newClimate) = 0;
    virtual void onSeasonChange(const char* newSeason) = 0;
    virtual ~IObserver() = default;
};

class ClimateManager{
private:
    std::vector<IObserver*> observers;
    std::string currentClimate;
    //std::string currentSeason;

public:
    void registerObserver(IObserver* obs);
    void removeObserver(IObserver* obs);

    void notifyClimateChange(const std::string& newClimate);
    void notifySeasonChange(const std::string& newSeason);

    std::string getClimate() const;
    //std::string getSeason() const;

};

