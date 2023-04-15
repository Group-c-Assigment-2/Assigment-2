/* WeaponsSystem.h
Harout
*/

#include "WeaponsSystem.h"

bool Weapons::FireTorpedos(int _torpedos) {

	bool retValue = false;

	if (_torpedos <= numTorpedos) {
		numTorpedos -= _torpedos;
		retValue = true;
	}

	return retValue;
}

double Weapons::FireLaser(double time) {
	// return energy req to fire lasers
	// to propulsion to calculate if enough
	// fuel is there
	double energy;
	energy = energyPerSecond * time;
	return energy;
}

void Weapons::AddTorpedos(int torpedos) {
		if (torpedos > 0) {
			if ((this->numTorpedos + torpedos) <= maxTorpedos) {
				this->numTorpedos += torpedos;
			}
			else {
				this->numTorpedos = maxTorpedos;
			}
		}
}

void Weapons::AddCannons(int _laserCannons) {
	if (numLaserCannons > 0) {
		if ((this->numLaserCannons + _laserCannons) <= maxLaserCannons) {
			numLaserCannons += _laserCannons;
		}
		else {
			numLaserCannons = maxLaserCannons;
		}
	}
}

void Weapons::GenerateReport() const {
	std::cout << "Weapon: number of laser cannons: " << numLaserCannons
		<< ", number of torpedos: " << numTorpedos << std::endl;
}