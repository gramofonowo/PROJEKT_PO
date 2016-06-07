#include "MotionSensor.h"
#include <random>
#include <iostream>
#include <cstdio>

using namespace std;

MotionSensor::MotionSensor(string n) : Sensor(n){
	mD = false;
	distance = 0.0;
}

void MotionSensor::Update(float temp){
	float t = Sensor::fRand(0.0, 70.0);
	if(t <= temp){
		mD = true;
		distance = Sensor::fRand(1.0, 4.0);
		cout << endl << this->getName() << ", wykryl ruch w odleglosci ";
		printf("%.2f", distance);
		cout << " m.";

	} else {
		if(mD && t >= 50.0){
			distance += Sensor::fRand(0.0, 1.0);
			cout << endl << this->getName() << ", wykryl ruch w odleglosci ";
			printf("%.2f", distance);
			cout << " m.";
		}

		else {
			mD = false;
			cout << endl << this->getName() << ", nie wykryl ruchu ";
		}

	}

};

void MotionSensor::getStatus(){

	if(isActive()){
			cout << "\nNazwa: " << getName();
			if(mD)
				cout << ", wykryto ruch w odleglosci: " << distance << " m.";
			else
				cout << ", nie wykryto ruchu";
		} else {
			cout << "\nCzujnik " << getName();
			cout << " jest wylaczony.";
		}

};
