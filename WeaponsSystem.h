/*
Harout Nazarian
hnazarian2@myseneca.ca
116431222
*/

#pragma once

#ifndef _WEAPONSSYSTEM_H_
#define _WEAPONSSYSTEM_H_

#include <iostream>
#include <iomanip>

class Weapons {

private:

	int numTorpedos;
	int numLaser;
	const int torpedoCapacity = 110;
	const int maxNumLaser = 10;
	const double energyPerSecond = 1000000000000;

public:

	Weapons() {
		
		numTorpedos = 0;
		numLaser= 0;

	}

	Weapons(int _torpedos, int _laser) {

		numTorpedos = _torpedos;
		numLaser = _laser;

	}

	bool FireTorpedos(int& _torpedos);
	double FireLaser(double& _timeDuration);
	void AddTorpedos(int _torpedos);
	void AddCannons(int _laser);
	void GenerateReport();
	
};

#endif // !_WEAPONSSYSTEM_H_
