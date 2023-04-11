#include "Warbird.h"

// Default constructor
Warbird::Warbird() : speed(0), distanceTraveled(0) {}

// Changes the speed of the Warbird
bool Warbird::ChangeSpeed(double speed)
{
    // calculate the energy required
    double energy = 0.5 * payloadSystem.GetMass() * speed * speed;

    // check if the propulsion systems can provide the required energy
    if (propulsionSystem1.ConsumeFuel(energy) && propulsionSystem2.ConsumeFuel(energy))
    {
        this->speed = speed;
        return true;
    }
    else
    {
        return false;
    }
}

// Updates the distance traveled based on the amount of time and light level
void Warbird::Travel(double time, double lightLevel)
{
    double fuelGenerated = propulsionSystem1.GenerateFuel(time) + propulsionSystem2.GenerateFuel(time);
    distanceTraveled += speed * time * lightLevel;
    propulsionSystem1.SetLightLevel(lightLevel);
    propulsionSystem2.SetLightLevel(lightLevel);
}

// Fires the torpedoes if they are available
bool Warbird::FireTorpedo(int torpedoes)
{
    if (weaponSystem1.FireTorpedos(torpedoes) && weaponSystem2.FireTorpedos(torpedoes))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Fires the laser cannons if possible
bool Warbird::FireLaser(double duration)
{
    double energyRequired = weaponSystem1.energyConsumption(duration) + weaponSystem2.energyConsumption(duration);

    // check if the propulsion systems can provide the required energy
    if (propulsionSystem1.ConsumeFuel(energyRequired) && propulsionSystem2.ConsumeFuel(energyRequired))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Prints the report of the Warbird including speed, distance traveled, and subsystem reports
void Warbird::GenerateReport()
{
    std::cout << "Speed: " << speed << " m/s\n";
    std::cout << "Distance traveled: " << distanceTraveled << " m\n";
    propulsionSystem1.GenerateReport();
    propulsionSystem2.GenerateReport();
    payloadSystem.GenerateReport();
    weaponSystem1.GenerateReport();
    weaponSystem2.GenerateReport();
}
