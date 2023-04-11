#include "WeaponsSystem.h"


bool Weapons::FireTorpedos(int& _torpedos) { //might need to change it to address and pointers

	bool retValue = false;

	if (_torpedos <= numberOfTorpedos) {
		numberOfTorpedos -= _torpedos;
		retValue = true;
	}

	return retValue;
}

double Weapons::FireLaser(double& _timeDuration) {

	double energyConsumption;

	energyConsumption = energyPerSecond * _timeDuration;

	return energyConsumption;

}

void Weapons::AddTorpedos(int _torpedos) { 
	
	if (numberOfTorpedos + _torpedos <= torpedoCapacity) {
		numberOfTorpedos += _torpedos;
	}

}

void Weapons::AddCannons(int _laserCannons) { 

	if (numberOfLaserCannons + _laserCannons <= maxNumOfLaserCannon) {
		numberOfLaserCannons += _laserCannons;
	}
	
}

void Weapons::GenerateReport() {

	std::cout << "The number of torpedos: " << numberOfTorpedos << std::endl;
	std::cout << "The number of laser cannons: " << numberOfLaserCannons << std::endl;
}
