#include <iostream>
#include "SmokeSensor.h"
#include "ASubject.h"
#include <cstdio>

using namespace std;

SmokeSensor::SmokeSensor(string a) : Sensor(a){
	smoke = DEFAULT_SMOKE;
}

SmokeSensor::SmokeSensor(string a, float smoke) : Sensor(a){
	this->smoke = smoke;
}

void SmokeSensor::Update(float temp){

	float x = Sensor::fRand(0.0, 100.0);

	if(x >= 93.0){
		setActive(false);
	} else {
		setActive(true);
		if(smoke == 0.0){
			float t = Sensor::fRand(0.0, 100.0);
			if(t >= 80.0){
				float random_value = Sensor::fRand(1.0, 10.0);
				smoke += random_value;
			}
		} else {
			float t2 = Sensor::fRand(0.0, 100.0);
			if(t2 >= 30.0){
				float random_value = Sensor::fRand(1.0, 5.0);
				smoke += random_value;
			}
		}
	}


	getStatus();

}

void SmokeSensor::getStatus(){
	if(isActive()){
		if(smoke > 10.0){
			cout << "\nRodzaj: Czujnik dymu";
			cout << ", Nazwa: " << getName();
			cout << ", STAN KRYTYCZNY ";
			printf("%.1f", smoke);
			cout << "% DYMU W POWIETRZU";
		}else if(smoke > 0.0) {
			cout << "\nRodzaj: Czujnik dymu";
			cout << ", Nazwa: " << getName();
			cout <<", Dym: ";
			printf("%.1f", smoke);
			cout << "% !";
		} else {
			cout << "\nRodzaj: Czujnik dymu";
			cout << ", Nazwa: " << getName();
			cout <<", nie wykrył dymu ";
		}
		if(smoke > 25.0){
			cout << " --> GIT COMMIT, GIT PUSH & LEAVE THE BUILDING! <-- ";
		}

	} else {
		cout << "\nRodzaj: Czujnik dymu";
		cout << ", Nazwa: " << getName();
		cout << ", przerwal swoje dzialanie!";
	}
}


