#ifndef SENSOR_H_
#define SENSOR_H_


#include "IObserver.h"
#include <string>
#include <iostream>
#include <cstdlib>


class Sensor : IObserver{
	std::string name;
	float temp;
	bool on;
public:
	Sensor(std::string n);
	virtual ~Sensor(){
		std::cout << "\n SENSOR DOWN\n";
	};
	virtual void Update(float temp) = 0;
	virtual void getStatus() = 0;

	double fRand(double fMin, double fMax);
	void setActive(bool active);
	void setName(std::string name);
	bool isActive();
	std::string getName();


};



#endif /* SENSOR_H_ */
