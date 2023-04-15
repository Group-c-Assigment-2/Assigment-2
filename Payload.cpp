/*
* Payload.cpp
Crissha 
*/
#pragma once
#include "Payload.h"
#include<iomanip>

Payload::Payload()
{
	mPassengers = 0.0;
	mCargo = 0.0;
	mWorkstations = 0.0;
}

//Construct itself with the masses of the mPassengers, cargo, and 
//workstation
Payload::Payload(const double &mPassenger, const double &mCargo, 
	const double &mWorkstations)
{
	this->mPassengers = mPassenger;
	this->mCargo = mCargo;
	this->mWorkstations = mWorkstations;
}

double Payload::GetMass() const
{
	double tot;
	tot = mPassengers + mCargo + mWorkstations;
	return tot;
}

bool Payload::AddPassengers(double mPassengers)
{
	bool ret = false;
	if (mPassengers > 0) {
		this->mPassengers += mPassengers;
		ret = true;
	}
	return ret;
}

bool Payload::AddCargo(double mCargo)
{
	bool ret = false;
	if (mCargo > 0) {
		this->mCargo += mCargo;
		ret = true;
	}
		
	return ret;
}

bool Payload::AddWorkstations(double mWorkstations)
{
	bool ret = false;
	if (mWorkstations > 0) {
		this->mWorkstations += mWorkstations;
		ret = true;
	}
	return ret;
}

void Payload::GenerateReport() const
{// precision value is 2
	std::cout.setf(std::ios::fixed);
	std::cout << std::setprecision(2)<< "Payload: mass of "
		"Passengers: " << mPassengers << " kg" << ", mass of " 
		"cargo: " << mCargo << " kg" << " , mass of workstations "
		": " << mWorkstations << " kg." <<std::endl;
}
