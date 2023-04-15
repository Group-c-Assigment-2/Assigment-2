/*
Starship.h file
Jasleen 
150417210
*/
#pragma once
#ifndef _STARSHIP_H_
#define _STARSHIP_H_
#include "Propulsion.h"
#include "Payload.h"
#include "WeaponsSystem.h"

class Starship
{
private:
    Propulsion* prop;
    Payload* payload;
    Weapons* weapon;
    double speed; // speed of travel in meters per second
    double distance; // distance traveled in meters

public:
    Starship();
    
    //Constructor accepts parameters such as fuel level, light level, 
    //mass of passengers, mass of cargo, mass of workstation, 
    //no. of torpedos and lasers
    Starship(double fuel, double lightLevel, double mPassenger,
        double mCargo, double mWorkStn, int torp, int laser);
    bool ChangeSpeed(const double& vel);
    void Travel(double time, double lightLevel);
    bool FireTorpedo(int num);
    bool FireLaser(double time);
    void GenerateReport() const;

    // delete dynamically allocated memory
    ~Starship();
};

#endif // WARBIRD_H
