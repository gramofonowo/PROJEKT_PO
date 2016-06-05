#include "Sensor.h"
#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_
class TempSensor : public Sensor{
	float temp;
	double value;
public:
	TempSensor(std::string n);
	virtual ~TempSensor(){};
	void Update(float temp);
	void getStatus();
	//double fRand(double a, double b);
};





#endif /* TEMPSENSOR_H_ */
