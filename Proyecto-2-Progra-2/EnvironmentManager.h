#pragma once
#include<iostream>
#include<string>
#include <vector>

//Interface 
class IObserver {
public:
    virtual void onClimateChange(const std::string& newClimate) = 0;
    virtual void onSeasonChange(const std::string& newSeason) = 0;
    virtual ~IObserver() = default;
};
//Clase base Subject(Observable)
class EnvironmentManager {
private:
std::vector<IObserver*> observers;
protected:
    void notifyClimateChange(const std::string& newClimate);
    void notifySeasonChange(const std::string& newSeason);
public:
    void registerObserver(IObserver* obs);
    void removeObserver(IObserver* obs);
	virtual std::string getData() const = 0;
    virtual ~EnvironmentManager() = default;
};

//climate
class ClimateManager : public EnvironmentManager {
private:
    std::string currentClimate;
public:
    void setClimate(const std::string& newClimate);
    std::string getData() const override;

};
// season
class SeasonManager : public EnvironmentManager {
private:
    std::string currentSeason;
public:
    void setSeason(const std::string& newSeason);
    std::string getData() const override;
};