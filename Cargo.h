/*
Cargo.h file
Jasleen
150417210
*/
#pragma once

#ifndef _CARGO_H_
#define _CARGO_H_
#include "Propulsion.h"
#include "Payload.h"

class Cargo {
	Propulsion *prop;
	Payload *payload1;
	Payload *payload2;
	double speed; // in m/s
	double distance;// in m

public :
	// constructor
	Cargo(double, double, double, double, double);
	bool ChangeSpeed(const double &vel);
	void Travel(double time, double lightLevel);
	void GenerateReport () const;
	//destructor
	~Cargo();
};

#endif
