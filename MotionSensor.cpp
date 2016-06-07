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
	float f = Sensor::fRand(0.0, 100.0);
	if(f >= 95){
		setActive(false);
	} else {
		setActive(true);
		float t = Sensor::fRand(0.0, 70.0);
		if(t <= temp){
			mD = true;
			distance = Sensor::fRand(1.0, 4.0);
		} else {
			if(mD && t >= 50.0){
				distance += Sensor::fRand(0.0, 1.0);
			}

			else {
				mD = false;
			}

		}
	}

	getStatus();
};

void MotionSensor::getStatus(){

	if(isActive()){
			cout << "\nRodzaj: Czujnik ruchu";
			cout << ", Nazwa: " << getName();
			if(mD){
				cout << " wykryto ruch w odleglosci: ";
				printf("%.2f", distance);
				cout << " m.";
			}
			else
				cout << ", nie wykryto ruchu";
		} else {
			cout << "\nRodzaj: Czujnik ruchu";
			cout << ", Czujnik " << getName();
			cout << " przerwal swoje dzialanie!";
		}

};
