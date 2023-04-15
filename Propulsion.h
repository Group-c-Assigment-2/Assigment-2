/* Propulsion.h
Fahima
*/
#pragma once
#ifndef _PROPULSION_H_
#define _PROPULSION_H_

#include <cmath>
#include <iostream>
#include <iomanip>

/*m. The propulsion system consists of the following:
o The fuel level in kg of matter/anti-matter,
o The fuel tank capacity, fixed at 1000.0kg of matter/anti-matter,
o The speed of light, fixed at 299,792,458 m/s,
o The light to fuel conversion, equals the light level times the time travelled,
o The light level, where a level of 1.0 is the light level on the surface of the
sun.*/

class Propulsion {
    // private
    double fuel;
    const double capacity = 1000;
    const double speedOfLight = 299792458;
    double lightLevel;

public:
    // constructor
    Propulsion();
    Propulsion(double fuel, double lightLevel);
    bool ConsumeFuel(const double &energy);
    void AddFuel(double _fuel);
    void GenerateFuel(double time);
    void SetLightLevel(double _lightLevel);
    void GenerateReport() const;
};
#endif