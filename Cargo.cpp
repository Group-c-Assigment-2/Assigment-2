/*
Cargo.cpp file
Jasleen
150417210
*/
#include "Cargo.h"

// Constructor accepts parameters such as fuel level, light level,
//mass of passengers, mass of cargo, mass of workstation, 
Cargo::Cargo(double fuel, double lightLevel, double mPassenger,
	double mCargo, double mWorkStation) {
	this->distance = 0;
	this->speed = 0;
	// create objects by calling paramteric constructors 
	// and assigning dyanmic memory
	prop = new Propulsion(fuel, lightLevel);
	payload1 = new Payload(mPassenger, mCargo, mWorkStation);
	payload2 = new Payload(mPassenger, mCargo, mWorkStation);
}

bool Cargo::ChangeSpeed(const double& vel) {
	double energy = 0;
	double totalMass = 0;

	//Two payloads so add mass of both
	totalMass = payload1->GetMass() + payload2->GetMass();

	energy = 0.5 * totalMass * vel * vel;

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

void Cargo::Travel(double time, double lightLevel) {
	this->distance += (this->speed) * time;
	this->prop->SetLightLevel(lightLevel);
	// propulsion generates fuel for the time ship has travelled
	//using lightLevel*time
	this->prop->GenerateFuel(time);
}

void Cargo::GenerateReport() const {
	std::cout.setf(std::ios::fixed);
	std::cout << std::setprecision(2) << "The cargo ship is travelling at "
		<< speed << " m/s and has travelled " << distance << " m." << std::endl;
	this->prop->GenerateReport();
	this->payload1->GenerateReport();
	this->payload2->GenerateReport();
	std::cout << std::endl;
}

//customized default destructor to free dynamically allocated memory
Cargo::~Cargo() {
	delete prop;
	delete payload1;
	delete payload2;
}
