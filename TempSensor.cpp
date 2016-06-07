#include <iostream>
#include "TempSensor.h"
#include <cstdio>

using namespace std;


TempSensor::TempSensor(string a) : Sensor(a){
	temp = 20.5;
	heating = false;
	cooling = false;
}

TempSensor::TempSensor(string a, float temp) : Sensor(a){
	this->temp = temp;
	heating = false;
	cooling = false;
}

void TempSensor::Update(float temp) {
	if(!(cooling || heating)){
		float f = Sensor::fRand(0.0, 100.0);
		if(f >= 95){
			setActive(false);
		} else {
			setActive(true);
			float diff = Sensor::fRand(0.0, 1.0);
			if(f >= 30){
				float x = Sensor::fRand(0.0, 10.0);
				if(x > 5.0)
					this->temp += diff;
				else
					this->temp -= diff;
			}
		}


	}
	cooling = false;
	heating = false;
	getStatus();
}


void TempSensor::getStatus(){
	if(isActive()){
		cout << "\nRodzaj: Czujnik temperatury";
		cout << ", Nazwa: " << getName();
		cout << ", Temperatura: ";
		printf("%.1f", temp);
		if(temp > 21){
			cout << ", COOLING ON";
			temp -= 1.0;
			cooling = true;
		}

		else if(temp < 20){
			cout << ", HEATING ON";
			temp += 1.0;
			heating = true;
		}

	} else {
		cout << "\nRodzaj: Czujnik temperatury";
		cout << ", Czujnik " << getName();
		cout << " przerwal swoje dzialanie!";
	}
}
