/*
Harout Nazarian
hnazarian2@myseneca.ca
116431222
*/

#include "WeaponsSystem.h"


bool Weapons::FireTorpedos(int& _torpedos) { //reduces the numbers of torpedos as they are being fired 

	bool retValue = false;

	if (_torpedos <= numTorpedos) {
		
		numTorpedos -= _torpedos;
		
		retValue = true;
	
	}
	
	return retValue;
}

double Weapons::FireLaser(double& _timeDuration) { // calculates how much energy is consumed by firing laser

	double energyConsumption;

	energyConsumption = energyPerSecond * _timeDuration;

	return energyConsumption;

}

void Weapons::AddTorpedos(int _torpedos) { //checks if the sum is more than 0, 
	//and if the sum is less than the capacity, then adds torpedos

	if (numTorpedos > 0 ) {
		
		if (numTorpedos + _torpedos < torpedoCapacity) {
		
			numTorpedos += _torpedos;

		}

	}

}

void Weapons::AddCannons(int _laser) { //checks if the num laser is more than 0,
	//checks if the sum is less than the capacity, then adds cannos

	if (numLaser > 0) {
		
		if (numLaser + _laser < maxNumLaser) {

			numLaser += _laser;
		
		}
	}
	
}

void Weapons::GenerateReport() { //prints a report of num of torpedos
	//prints a report of num of laser cannons

	std::cout << "The number of torpedos: " << numTorpedos << std::endl;
	std::cout << "The number of laser cannons: " << numLaser << std::endl;
}
