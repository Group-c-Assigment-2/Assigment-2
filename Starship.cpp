/*
Starship.cpp file
Jasleen
150417210
*/
#include "Starship.h"

Starship::Starship() {
    distance = 0;
    speed = 0;
}

//Constructor accepts parameters such as fuel level, light level, 
//mass of passengers, mass of cargo, mass of workstation, 
//no. of torpedos and lasers
Starship::Starship(double fuel, double lightLevel, double mPassenger,
    double mCargo, double mWorkStn, int torp, int laser) {
    distance = 0;
    speed = 0;
    // create objects by calling paramteric constructors 
    // and assigning dyanmic memory
    prop = new Propulsion(fuel, lightLevel);
    payload = new Payload(mPassenger, mCargo, mWorkStn);
    weapon = new Weapons(torp, laser);
}

bool Starship::ChangeSpeed(const double& vel) {
    double energy = 0;
    energy = 0.5 * payload->GetMass() * vel * vel;

    // Consume fuel returns true if enough fuel in
    //  propulsion (prop) to produce "energy" to change vel
    if (prop->ConsumeFuel(energy)) {
        this->speed += vel;
        return true;
    }

    else {
        return false;
    }
}

void Starship::Travel(double time, double lightLevel) {
    this->distance += this->speed * time;
    this->prop->SetLightLevel(lightLevel);
    // propulsion generates fuel for the time ship has travelled
    //using lightLevel*time
    this->prop->GenerateFuel(time);
}

bool Starship::FireTorpedo(int num) {
    //FireTorpedos returns true f there are enough torps 
    // to fire
    if (weapon->FireTorpedos(num)) {
        return true;
    }
    else return false;
}

bool Starship::FireLaser(double time) {
    //FireLaser returns energy required to fire the lasers
    double energy = weapon->FireLaser(time);

    //ConsumeFuel returns true if there is enough fuel to
    // to produce energy required to fire the lasers
    if (prop->ConsumeFuel(energy)) {
        prop->ConsumeFuel(energy);
        return true;
    }

    else return false;

}

void Starship::GenerateReport() const {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2) << "The Star ship is travelling at "
        << speed << " m/s and has travelled " << distance << " m." << std::endl;
    this->prop->GenerateReport();
    this->payload->GenerateReport();
    this->weapon->GenerateReport();
    std::cout << std::endl;
}

// delete dynamically allocated memory
Starship::~Starship() {
    delete prop;
    delete weapon;
    delete payload;
}