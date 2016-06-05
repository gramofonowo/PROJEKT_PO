#ifndef APPINTERFACE_H_
#define APPINTERFACE_H_

#include <iostream>
#include "DummyRoom.h"


class AppInterface {
protected:

	DummyRoom room;
public:
	void addRoom();
	void deleteRoom();
	void displayRooms();
	void displaySensors();
	void menu();
};



#endif /* APPINTERFACE_H_ */
