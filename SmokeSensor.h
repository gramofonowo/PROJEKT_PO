#include "Sensor.h"
#ifndef SMOKESENSOR_H_
#define SMOKESENSOR_H_
#define DEFAULT_SMOKE 0.0

class SmokeSensor : public Sensor {
protected:
	float smoke;
public:
	SmokeSensor(std::string n);
	SmokeSensor(std::string n, float smoke);
	virtual ~SmokeSensor(){
		std::cout << " \n SMOKE SENSOR DOWN \n";
	};
	void Update(float temp);
	void getStatus();
	double fRand(double a, double b);
};



#endif /* SMOKESENSOR_H_ */
