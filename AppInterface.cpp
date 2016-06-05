#include "AppInterface.h"


using namespace std;

void AppInterface::menu(){
	int choice = -1;
	while(choice != 0){
		cout << "\n Menu:";
		cout << "\n1. Dodaj pomieszczenie";
		cout << "\n2. Dodaj czujnik";
		cout << "\n3. Wyświetl pomieszczenia";
		cout << "\n4. Wyświetl czujniki";
		cout << "\n0. Wyjdz";
		cin >> choice;
		switch(choice){
		case 0:
			break;
		default:
			cout << "\nBlad!";
			break;
		}
	}

}
void AppInterface::displayRooms(){

}

void AppInterface::displaySensors(){

}

void AppInterface::addRoom(){

}

void AppInterface::deleteRoom(){

}
