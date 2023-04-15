/*
Warbird.cpp
Raghav
*/
#include "Warbird.h"

//Constructor accepts parameters such as fuel level, light level, 
  //mass of passengers, mass of cargo, mass of workstation, 
  //no. of torpedos and lasers 
Warbird::Warbird(double fuel, double lightLevel, double mPass,
    double mCar, double mWork, int torp, int laser) {
    distance = 0;
    speed = 0;
    // create objects by calling paramteric constructors 
    // and assigning dyanmic memory
    prop1 = new Propulsion(fuel, lightLevel);
    prop2 = new Propulsion(fuel, lightLevel);
    payload = new Payload(mPass, mCar, mWork);
    weapon1 = new Weapons(torp, laser);
    weapon2 = new Weapons(torp, laser);
}

bool Warbird::ChangeSpeed(double vel) {
    double energy = 0;
    energy = (0.5 * payload->GetMass() * vel * vel) / 2;

    // Consume fuel returns true if enough fuel in
    //  propulsion (prop) to produce "energy" to change vel
    if (prop1->ConsumeFuel(energy) && prop2->ConsumeFuel(energy)) {
        this->speed += vel;
        return true;
    }

    else {
        return false;
    }
}

void Warbird::Travel(double time, double lightLevel) {
    this->distance += this->speed * time;
    this->prop1->SetLightLevel(lightLevel);
    //propulsion generates fuel for the time ship has travelled
    //using lightLevel*time
    this->prop1->GenerateFuel(time);
    this->prop2->SetLightLevel(lightLevel);
    this->prop2->GenerateFuel(time);
}

bool Warbird::FireTorpedo(int num) {
    //Two weapon systems so divide number of torpedos by 2
    int numEachTorp = num / 2;

    //FireTorpedos returns true f there are enough torps 
    // to fire
    if (weapon1->FireTorpedos(numEachTorp) && weapon2->FireTorpedos(numEachTorp)) {
        return true;
    }
    else return false;
}

bool Warbird::FireLaser(double time) {
    // FireLaser returns energy required to fire the lasers
    double energy1 = weapon1->FireLaser(time);
    double energy2 = weapon2->FireLaser(time);

    //ConsumeFuel returns true if there is enough fuel to
    //to produce energy required to fire the lasers
    if (prop1->ConsumeFuel(energy1) && prop2->ConsumeFuel(energy2)) {
        prop1->ConsumeFuel(energy1);
        prop2->ConsumeFuel(energy2);
        return true;
    }

    else return false;

}

void Warbird::GenerateReport() const {
    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(2) << "The Warbird ship is travelling at "
        << speed << " m/s and has travelled " << distance << " m." << std::endl;
    this->prop1->GenerateReport();
    this->prop2->GenerateReport();
    this->payload->GenerateReport();
    this->weapon1->GenerateReport();
    this->weapon2->GenerateReport();
    std::cout << std::endl;
}

// delete dynamically allocated memory
Warbird::~Warbird() {
    delete prop1;
    delete prop2;
    delete weapon1;
    delete weapon2;
    delete payload;
}