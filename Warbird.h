#pragma once
#ifndef WARBIRD_H
#define WARBIRD_H

#include "Propulsion.h"
#include "Payload.h"
#include "WeaponsSystem.h"

#include <iostream>

class Warbird
{
private:
    Propulsion propulsionSystem1; // Why use pointers?
    Propulsion propulsionSystem2;
    Payload payloadSystem;
    Weapons weaponSystem1;
    Weapons weaponSystem2;
    double speed;            // speed of travel in meters per second
    double distanceTraveled; // distance traveled in meters

public:
    Warbird();
    // constructor parameters are incorrect: refer to main file and assgn2
    // constructor i am still working on it and a bit confused.

    int getSpeed() { return speed; }
    int getDistanceTraveled() { return distanceTraveled; }

    int setSpeed(int s) { speed = s; }
    int setDistanceTraveled(int d) { distanceTraveled = d; }

    bool ChangeSpeed(double speed);
    void Travel(double time, double lightLevel);
    bool FireTorpedo(int torpedoes);
    bool FireLaser();
    void GenerateReport();
};

#endif // WARBIRD_H
