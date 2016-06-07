#ifndef APPINTERFACE_H_
#define APPINTERFACE_H_

#include <iostream>
#include <iterator>
#include "DummyRoom.h"


class AppInterface {
protected:
	std::vector<DummyRoom*> rooms;


public:
	AppInterface();
	void addRoom();
	virtual ~AppInterface(){
		std::cout << "\n INT DOWN\n";
		for(std::vector<DummyRoom*>::iterator it = rooms.begin(); it != rooms.end(); ++it){
			delete (*it);
		}
	};
	void deleteRoom();
	void displayRooms();
	void displaySensors();
	void addSensor(DummyRoom *dr);
	void menu();
};



#endif /* APPINTERFACE_H_ */
