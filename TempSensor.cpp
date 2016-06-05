#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "TempSensor.h"

using namespace std;

double temp_value;

TempSensor::TempSensor(string a) : Sensor(a){
	 srand(time(NULL));
	 value = Sensor::fRand(2.0, 1.0);

}

void TempSensor::Update(float temp) {
	this->temp = temp;
	cout << "\nTemperatura " << getName() << " wynosi " << temp << " stopni";
}


void TempSensor::getStatus(){
	if(isActive()){
		cout << "\nNazwa: " << getName();
		cout <<", Temperatura: " << temp;
	} else {
		cout << "\nCzujnik " << getName();
		cout << " jest wyłączony.";
	}
}
