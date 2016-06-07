#ifndef DUMMYROOM_H_
#define DUMMYROOM_H_
#define DEFAULT_TEMP 21.0
#define DEFAULT_SMOKE 0.0
#include "ASubject.h"



class DummyRoom : public ASubject {
protected:
	float temp, smoke;
	std::string name;
public:
	virtual ~DummyRoom(){
		std::cout << "\n ROOM DOWN\n";
	};
	DummyRoom(std::string n);
	DummyRoom(std::string n, float temp);
	DummyRoom(std::string n, float temp, float smoke);
	void UpdateSensors(float temp);
	void setTemp(float temp);
	void setSmoke(float smoke);
	float getRoomTemp();
	float getRoomSmoke();
	std::string getName();

};




#endif /* DUMMYROOM_H_ */
