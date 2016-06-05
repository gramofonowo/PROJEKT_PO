#pragma once
#ifndef ASUBJECT_H_
#define ASUBJECT_H_

#include <vector>
#include "Sensor.h"
#include "TempSensor.h"
#include "MotionSensor.h"


class ASubject {
protected:
	std::vector<Sensor*> v, v_temp, v_smoke, v_motion;
	std::string name;
public:
	ASubject(std::string name);
	void Attach(Sensor *room, int s);
	void Detach(Sensor *room);
	void Notify(float temp);
	std::vector<Sensor*> getV(std::string v);
	std::string getSensorType(Sensor *sensor);
};



#endif /* ASUBJECT_H_ */
