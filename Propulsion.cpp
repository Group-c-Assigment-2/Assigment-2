/* Propulsion.cpp
Fahima
*/

#include "Propulsion.h"

Propulsion::Propulsion() {
    fuel = 0;
    lightLevel = 0;
}

Propulsion::Propulsion(double fuel, double lightLevel) {
    this->fuel = fuel;
    this->lightLevel = lightLevel;
}

//return true if there is snough fuel to 
//ChangeSpeed / FireLasers etc.
bool Propulsion::ConsumeFuel(const double& energy) {
    long double reqFuel = 0;
    reqFuel = energy / pow(speedOfLight, 2);

    if (reqFuel > fuel) {
        return false;
    }

    else {
        this->fuel -= reqFuel;
        return true;
    }
}

void Propulsion::AddFuel(double fuel) {
    if (fuel > 0) {
        if (this->fuel + fuel <= capacity) {
            this->fuel += fuel;
        }
        else {
            this->fuel = capacity;
        }
    }
}

void Propulsion::GenerateFuel(double time) {
    double fuel = 0;
    if (time > 0) {
        fuel = this->lightLevel * time;
    }
    this->AddFuel(fuel);
}

void Propulsion::SetLightLevel(double lightLevel) {
    this->lightLevel = lightLevel;
}

void Propulsion::GenerateReport() const {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2) << "Propulsion: fuel Level: "
        << fuel << " kg of matter/anti-matter, light level: "
        << lightLevel << std::endl;
}
