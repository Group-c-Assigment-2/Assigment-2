#pragma once
#ifndef _PAYLOAD_H_
#define _PAYLOAD_H_

#include<iostream>

class Payload {
private:
	double passengers;
	double cargo;
	double workstations;


public:
		Payload();
		Payload(double _passenger, double _cargo, double _workstations);
		//Construct itself with the masses of the passengers, cargo, and 
		//workstation
		double GetMass();
		bool AddPassengers(double _passengers);
		bool AddCargo(double _cargo);
		bool AddWorkstations(double _workstations);
		void report();

};



#endif