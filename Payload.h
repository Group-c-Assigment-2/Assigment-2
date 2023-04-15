/*
* Payload.h
Crissha 
*/
#pragma once

#pragma once
#ifndef _PAYLOAD_H_
#define _PAYLOAD_H_

#include<iostream>

class Payload {
private:
	double mPassengers;
	double mCargo;
	double mWorkstations;

public:
	Payload();
	//Construct itself with the masses of the mPassengers, cargo, and 
	//workstation
	Payload(const double &mPassenger, const double& mCargo,
		const double& mWorkstations);
	double GetMass() const;
	bool AddPassengers(double mPassengers);
	bool AddCargo(double _cargo);
	bool AddWorkstations(double _workstations);
	void GenerateReport() const;
};

#endif
