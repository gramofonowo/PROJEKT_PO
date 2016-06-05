#include "ASubject.h"
#include <algorithm>
#include <typeinfo>
#include <iterator>

using namespace std;

ASubject::ASubject(string name){
	this->name = name;
}

void ASubject::Attach(Sensor *sensor, int s){

	string type = getSensorType(sensor);
	v.push_back(sensor);

	cout << "\nWłączono " << sensor->getName();
	cout << " w " << this->name;

	if(type == "t")
		v_temp.push_back(sensor);
	else if(type == "m")
		v_motion.push_back(sensor);
	else if(type == "s")
		v_smoke.push_back(sensor);

}

void ASubject::Detach(Sensor *sensor){

	string type = getSensorType(sensor);
	string n = sensor->getName();

	if(type == "t"){
		if(v_temp.size() == 1)
			v_temp.clear();
		else
			for(vector<Sensor*>::iterator it = v_temp.begin(); it != v_temp.end(); ++it){
					string temp = (*it)->getName();
					if(temp == n)
						v_temp.erase(it);
			}
	} else if(type == "m"){
		if(v_motion.size() == 1)
			v_motion.clear();
		else
			for(vector<Sensor*>::iterator it = v_motion.begin(); it != v_motion.end(); ++it){
				string temp = (*it)->getName();
				if(temp == n)
					v_motion.erase(it);
			}
	} else if(type == "s"){
		if(v_smoke.size() == 1)
			v_smoke.clear();
		else
			for(vector<Sensor*>::iterator it = v_smoke.begin(); it != v_smoke.end(); ++it){
				string temp = (*it)->getName();
				if(temp == n)
					v_smoke.erase(it);
			}
	}

	v.erase(std::remove(v.begin(), v.end(), sensor), v.end());
	sensor->setActive(false);

	cout << "\nWyłączono " << sensor->getName();
	cout << " w " << this->name;

}

void ASubject::Notify(float temp){
	for(vector<Sensor*>::const_iterator it = v.begin(); it != v.end(); it++){
		if(*it != 0 )
			(*it)->Update(temp);
	}
}

string ASubject::getSensorType(Sensor *sensor){
	Sensor* ptr = sensor;
	if(typeid(*ptr) == typeid(TempSensor)){
		return "t";
	} else if(typeid(*ptr) == typeid(MotionSensor)){
		return "m";
	} else{
		return "s";
	}

}

vector<Sensor*> ASubject::getV(string s){
	if(s == "t")
		return v_temp;
	else if(s == "m")
		return v_motion;
	else if(s == "s")
		return v_smoke;
	else
		return v;
}
