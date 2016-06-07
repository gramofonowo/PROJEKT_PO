#include "DummyRoom.h"


using namespace std;


DummyRoom::DummyRoom(string n) : ASubject(n){
	name = n;
	smoke = DEFAULT_SMOKE;
	temp = DEFAULT_TEMP;
};

DummyRoom::DummyRoom(string n, float temp) : ASubject(n){
	this->temp = temp;
	smoke = DEFAULT_SMOKE;
}

DummyRoom::DummyRoom(string n, float temp, float smoke) : ASubject(n){
	this->temp = temp;
	this->smoke = smoke;
}

void DummyRoom::UpdateSensors(float temp){
	Notify(temp);
}

void DummyRoom::setSmoke(float smoke){
	this->smoke = smoke;
}

void DummyRoom::setTemp(float temp){
	this->temp = temp;
}

float DummyRoom::getRoomSmoke(){
	return smoke;
}

float DummyRoom::getRoomTemp(){
	return temp;
}

string DummyRoom::getName(){
	return name;
}

