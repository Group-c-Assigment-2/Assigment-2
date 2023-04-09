#pragma once

#ifndef _CARGOSHIP_H_
#define _CARGOSHIP_H_
#include "Propulsion.h"
#include "Payload.h"
#include "WeaponsSystem.h"

#define NUM_PAYLOADS 2

class Propulsion;
class Payload;

class Cargo {
	Propulsion prop;
	// make array or declare two separate objects?
	Payload payload[NUM_PAYLOADS];
	double speed; // in m
	double distance;// in m/s

public :
	// constructor
	Cargo(double, double, double, double, double);
	bool ChangeSpeed(double vel);
	void Travel(double time, double lightLevel);
	void GenerateReport();
};

Cargo::Cargo(double fuel, double lightlevel, double mPassenger, double mCargo, double mWorkStation) {
	this->distance = 0;
	this->speed = 0;
	prop.setPropulsion(fuel, lightlevel);

	for (int i = 0; i < NUM_PAYLOADS; i++) {
		this->payload[i].setPayload(mPassenger, mCargo, mWorkStation);
	}
}

bool Cargo::ChangeSpeed (double vel) {
	double energy = 0;
	double totalMass = 0;

	for (int i = 0; i < NUM_PAYLOADS; i++) {
		totalMass += this->payload[i].GetMass();
	}

	energy = 0.5 * totalMass * vel * vel;

	if (this->prop.ConsumeFuel(energy)) {
		this->speed = vel;
		return true;
	}

	else {
		return false;
	}
}

void Cargo::Travel(double time, double lightLevel) {
	this->distance = this->speed * time;
	this->prop.SetLightLevel(lightLevel);
	this->prop.GenerateFuel(time);
}

void Cargo::GenerateReport() {
	std::cout << "The cargo ship is travelling at " << speed << " m/s "
		"and has travelled " << distance << " m.";
}

#endif
