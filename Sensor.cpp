#include <iostream>
#include "Sensor.h"

Sensor::Sensor(std::string name){
	this->name = name;
	on = true;
}

double Sensor::fRand(double fMin, double fMax){
	double f = (double)rand() / RAND_MAX;
	return fMin + f * (fMax - fMin);
}

void Sensor::setName(std::string name){
	this->name = name;
}

std::string Sensor::getName(){
	return name;
}

void Sensor::setActive(bool active){
	on = active;
}

bool Sensor::isActive(){
	return on;
}
