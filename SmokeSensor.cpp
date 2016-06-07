#include <iostream>
#include "SmokeSensor.h"
#include <cstdio>

using namespace std;

SmokeSensor::SmokeSensor(string a) : Sensor(a){
	smoke = DEFAULT_SMOKE;
}

SmokeSensor::SmokeSensor(string a, float smoke) : Sensor(a){
	this->smoke = smoke;
}

void SmokeSensor::Update(float temp){
	float t = Sensor::fRand(0.0, 100.0);

	if(smoke == 0.0){
		if(t >= 85.0){
			float random_value = Sensor::fRand(1.0, 3.0);
			smoke += random_value;
		}
	} else {
		float t2 = Sensor::fRand(0.0, 100.0);
		if(t2 >= 75.0){
			float random_value = Sensor::fRand(1.0, 5.0);
			smoke += random_value;
		} else {
			if(smoke > 2.0)
				smoke -= 2.0;
			else
				smoke = 0.0;
		}
	}
	getStatus();

}

void SmokeSensor::getStatus(){
	if(isActive()){
		if(smoke > 10.0){
			printf("%.1f", smoke);
			cout << "ALARM!";
		}else if(smoke > 0.0) {
			cout << endl << getName();
			cout <<", Dym: ";
			printf("%.1f", smoke);
			cout << "% !";
		} else {
			cout << endl << getName();
			cout <<", nie wykryl dymu ";
		}

	} else {
		cout << "Czujnik " << getName();
		cout << " jest wylaczony.";
	}
}


