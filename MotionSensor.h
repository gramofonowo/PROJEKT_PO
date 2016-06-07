#include "Sensor.h"
#ifndef MOTIONSENSOR_H_
#define MOTIONSENSOR_H_

class MotionSensor : public Sensor {
		float distance;
		bool mD;
	public:
		MotionSensor(std::string n);
		virtual ~MotionSensor(){};
		void Update(float temp);
		void getStatus();
		double fRand(double a, double b);
};



#endif /* MOTIONSENSOR_H_ */
