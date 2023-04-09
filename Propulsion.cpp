// Propulsion.cpp - functions for propulsion object

#include "Propulsion.h"
#include <iostream>

Propulsion::Propulsion() {
    fuel = 0.00;
    lightLevel = 0.00;
    capacity = 1000.0; // fixed
    speedoflight = 299792458.0;
};

Propulsion::Propulsion(double _fuel, double _lightLevel) {
    fuel = _fuel;
    lightLevel = _lightLevel;
    capacity = 1000.0; // fixed
    speedoflight = 299792458.0;
};

// Consume fuel (passing through the energy required, return true if there is enough fuel to provide the energy required and false otherwise). Fuel is consumed according to Einstein's equation E=mc2, m=E/c2.
bool Propulsion::ConsumeFuel(double energy) {
    double fuel_required = energy / (speedoflight * speedoflight);
    if (fuel >= fuel_required) {
        fuel -= fuel_required;
        return true;
    }
    else {
        return false;
    };
};

// Add fuel (in kg of matter/anti-matter)
void Propulsion::AddFuel(double _fuel) {
    fuel += _fuel;
};

// Generate fuel (passing through the time elapsed in seconds). The amount of fuel generated for a given number of seconds is the light level times the time in seconds.
void Propulsion::GenerateFuel(double time) {
    double fuel_generated = (lightLevel * time);
    if ((fuel + fuel_generated) >= capacity) {
        fuel = capacity;
    }
    else {
        fuel += fuel_generated;
    };
};

//Set the light level (passing through the light level)
void Propulsion::SetLightLevel(double _lightLevel) {
    lightLevel = _lightLevel;
};

// generates final report
void Propulsion::GenerateReport() {
    std::cout << "Propulsion: fuel level: " << fuel << "kg of matter/anti-matter, light level: " << lightLevel << std::endl;
}
