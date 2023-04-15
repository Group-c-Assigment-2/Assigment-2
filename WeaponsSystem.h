/* WeaponsSystem.h
Harout
*/
#pragma once
#pragma once

#ifndef _WEAPONSSYSTEM_H_
#define _WEAPONSSYSTEM_H_
#include <iostream>

class Weapons {

private:
	int numTorpedos;
	int numLaserCannons;
	const int maxTorpedos = 110;
	const int maxLaserCannons = 10;
	const double energyPerSecond = 1000000000000.0; 

public:

	Weapons();
	Weapons(int _torpedos, int _laserCannons) {
		numTorpedos = _torpedos;
		numLaserCannons = _laserCannons;
	}
	bool FireTorpedos(int _torpedos);
	double FireLaser(double time);
	void AddTorpedos(int _torpedos);
	void AddCannons(int _laserCannons);
	void GenerateReport() const;
};

#endif // !_WEAPONSSYSTEM_H_
