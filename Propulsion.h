// Propulsion.h - file for propulsion class

#ifndef _PROPULSION_H_
#define _PROPULSION_H_
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
    double capacity; // fixed
    double speedoflight; // fixed
    double lightLevel;
public:
    // constructor
    Propulsion();
    Propulsion(double _fuel, double _lightLevel);
    bool ConsumeFuel(double energy);
    void AddFuel(double _fuel);
    void GenerateFuel(double time);
    void SetLightLevel(double _lightLevel);
    void GenerateReport();
};

#endif


