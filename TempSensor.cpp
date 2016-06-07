#include <iostream>
#include "TempSensor.h"

using namespace std;


TempSensor::TempSensor(string a) : Sensor(a){
	 temp = DEFAULT_TEMP;
}

TempSensor::TempSensor(string a, float temp) : Sensor(a){
	this->temp = temp;
}

void TempSensor::Update(float temp) {
	this->temp = temp;
	cout << endl << this->getName() << ", Temperatura wynosi " << temp << " stopni";
}


void TempSensor::getStatus(){
	if(isActive()){
		cout << "Nazwa: " << getName();
		cout <<", Temperatura: " << temp;
	} else {
		cout << "Czujnik " << getName();
		cout << " jest wylaczony.";
	}
}
