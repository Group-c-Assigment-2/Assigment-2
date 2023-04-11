#include "Payload.h"
#include<iomanip>

Payload::Payload()
{
	passengers = 0.0;
	cargo = 0.0;
	workstations = 0.0;
}

Payload::Payload(double _passenger, double _cargo, double _workstations)
{
	passengers = _passenger;
	cargo = _cargo;
	workstations = _workstations;
}

double Payload::GetMass()
{
	double tot;
	tot = passengers + cargo + workstations;
	return tot;
}

bool Payload::AddPassengers(double _passengers)
{
	bool ret = false;
	if (_passengers > 0) {
		passengers += _passengers;
		ret = true;
	}
	else
	return ret;
}

bool Payload::AddCargo(double _cargo)
{
	bool ret = false;
	if (_cargo > 0) {
		cargo += _cargo;
		ret = true;
	}
	else
		return ret;
}

bool Payload::AddWorkstations(double _workstations)
{
	bool ret = false;
	if (_workstations > 0) {
		workstations += _workstations;
		ret = true;
	}
	else
		return ret;
}

void Payload::report()
{
	std::cout << std::setprecision(4)<< " Payload: mass of passengers: " << this->passengers << "kg" << ", mass of cargo:" << this->cargo << "kg" << "mass of workstations:" << this->workstations << "kg";
}
