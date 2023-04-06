#pragma once

#ifndef _WEAPONSSYSTEM_H_
#define _WEAPONSSYSTEM_H_

#include <iostream>
#include <iomanip>

class Weapons {

private:

	int numberOfTorpedos;
	int numberOfLaserCannons;
	const int torpedoCapacity = 110;
	const int maxNumOfLaserCannon = 10;
	const int energyPerSecond = 1000000000000;

public:

	Weapons() {
		
		numberOfTorpedos = 0;
		numberOfLaserCannons = 0;

	}

	Weapons(int _torpedos, int _laserCannons) {

		numberOfTorpedos = _torpedos;
		numberOfLaserCannons = _laserCannons;

	}

	bool FireTorpedos(int _torpedos);
	double FireLaser(double _timeDuration);
	void AddTorpedos(int _torpedos);
	void AddCannons(int _laserCannons);
	void GenerateReport();
	
};

#endif // !_WEAPONSSYSTEM_H_
