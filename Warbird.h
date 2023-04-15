/*
Warbird.h
Raghav
*/
#pragma once
#ifndef _WARBIRD_H_
#define _WARBIRD_H_

#include "Propulsion.h"
#include "Payload.h"
#include "WeaponsSystem.h"

class Warbird
{
private:
    Propulsion* prop1; 
    Propulsion* prop2;
    Payload* payload;
    Weapons* weapon1;
    Weapons* weapon2;
    double speed; // speed of travel in meters per second
    double distance; // distance traveled in meters

public:
    Warbird() {
        distance = 0;
        speed = 0;
    }

    //Constructor accepts parameters such as fuel level, light level, 
   //mass of passengers, mass of cargo, mass of workstation, 
   //no. of torpedos and lasers 
    Warbird(double fuel, double lightLevel, double mPass,
        double mCar, double mWork, int torp, int laser);

    bool ChangeSpeed(double vel);
    void Travel(double time, double lightLevel);
    bool FireTorpedo(int num);
    bool FireLaser(double time);
    void GenerateReport() const;
    ~Warbird();
};

#endif // WARBIRD_H
