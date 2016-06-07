#include "Sensor.h"
#ifndef TEMPSENSOR_H_
#define TEMPSENSOR_H_
#define DEFAULT_TEMP 21.0

class TempSensor : public Sensor{
	float temp;
public:
	TempSensor(std::string n);
	TempSensor(std:: string n, float temp);
	virtual ~TempSensor(){
		std::cout << "\n TEMP SENSOR DOWN\n";
	};
	void Update(float temp);
	void getStatus();
	double fRand(double a, double b);
};





#endif /* TEMPSENSOR_H_ */
