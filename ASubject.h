#pragma once
#ifndef ASUBJECT_H_
#define ASUBJECT_H_

#include <vector>
#include "Sensor.h"
#include "TempSensor.h"
#include "MotionSensor.h"
#include "SmokeSensor.h"


class ASubject {
protected:
	std::vector<Sensor*> v, v_temp, v_smoke, v_motion;
	std::string name;
public:
	ASubject(std::string name);
	virtual ~ASubject(){
		for(std::vector<Sensor*>::iterator it = v.begin(); it != v.end(); it++){
			delete (*it);
		}
		for(std::vector<Sensor*>::iterator it = v_temp.begin(); it != v_temp.end(); it++){
			delete (*it);
		}
		for(std::vector<Sensor*>::iterator it = v_smoke.begin(); it != v_smoke.end(); it++){
			delete (*it);
		}
		for(std::vector<Sensor*>::iterator it = v_motion.begin(); it != v_motion.end(); it++){
			delete (*it);
		}

	};
	void Attach(Sensor *room);
	void Detach(Sensor *room);
	void Notify(float temp);
	std::vector<Sensor*> getV(std::string v);
	std::string getSensorType(Sensor *sensor);
};



#endif /* ASUBJECT_H_ */
