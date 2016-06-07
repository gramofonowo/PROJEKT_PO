#include "AppInterface.h"
#include <algorithm>
#include <typeinfo>
#include <iterator>

using namespace std;

AppInterface::AppInterface(){

}


void AppInterface::menu(){
	int choice = -1;
	while(choice != 0){

		cout << endl << endl;
		cout << "\tMenu:";
		cout << "\n1. Dodaj pomieszczenie";
		cout << "\n2. Dodaj czujnik";
		cout << "\n3. Wyświetl pomieszczenia";
		cout << "\n4. Wyświetl czujniki";
		cout << "\n5. Usun pomieszczenie";
		cout << "\n6. Usun czujnik";
		cout << "\n0. Wyjdz";
		cout << "\nCo chcesz zrobic?\n\n"; cin >> choice;

		switch(choice){
		case 0:{
			system("cls");
			exit(0);
		}
		case 1:
			cout << endl << endl;
			addRoom();
			break;
		case 2:{
			cout << endl << endl;
			displayRooms();
			cout << "\nWybierz pomieszczenie do ktorego chcesz dodac czujnik:" <<endl;
			int c = -1;
			cin >> c;
			c--;
			addSensor(rooms.at(c));
		}

		break;
		case 3:
			cout << endl << endl;
			displayRooms();
			break;
		case 4:
			cout << endl << endl;
			displaySensors();
			break;
		case 5:
			cout << endl << endl;
			deleteRoom();
		case 6:{
			cout << endl << endl;

			if(rooms.size() > 0){
				cout << endl << "Z ktorego pomieszczenia usunac czujnik?";
				displayRooms();
				int c = -1;
				int i = -1;
				cin >> c;
				c--;
				vector<Sensor*> v = rooms.at(c)->getV("v");
				cout << "\nWybierz czujnik do usuniecia: ";
				cout << "\nDostepne czujniki:";
				int temp = 1;
				for(vector<Sensor*>::iterator it = v.begin(); it != v.end(); it++){
					cout << endl << temp << ": ";
					(*it)->getStatus();
					temp++;
				}
				cin >> i;
				i--;
				Sensor* t = rooms.at(c)->getV("v").at(i);
				rooms.at(c)->Detach(t);

			} else {
				cout << endl << "Brak dodanych pomieszczen!";
			}
			break;
		}

		default:
		//	cout << endl << "Blad!";
			break;
		}
	}

}
void AppInterface::displayRooms(){

	if(rooms.size() == 0)
		cout << "\nBrak dodanych pomieszczen!";
	else {
		int i = 1;
		cout << "\nLista dodanych pomieszczen: " << endl;
		for(vector<DummyRoom*>::iterator it = rooms.begin(); it != rooms.end(); ++it){
			string temp = (*it)->getName();
			cout << i <<". " << temp << endl;
			i++;
		}

	}
}

void AppInterface::displaySensors(){
	cout << "\nWybierz pomieszczenie, dla ktorego chcesz wyswietlic czujniki: ";
	int i = -1;
	displayRooms();
	cout << endl;
	cin >> i;
	i--;
	if(i < 0 || i > (rooms.size() - 1)){
		cout << "\nNie ma takiego czujnika!\n";
		//break;
	} else {
		vector<Sensor*> v = rooms.at(i)->getV("t");

		if(v.size() > 0){
			for(vector<Sensor*>::iterator it = v.begin(); it != v.end(); it++){
				(*it)->getStatus();
			}
		} else {
			cout << "\nBrak dodanych czujnikow!";
		}


	}

}

void AppInterface::addRoom(){
	string name;

	cout << "Podaj nazwe pomieszczenia: " << endl;
	cin >> name;
	DummyRoom *dr = new DummyRoom(name);
	rooms.push_back(dr);
}

void AppInterface::deleteRoom(){
	if(rooms.size() > 0){
		cout << endl << "Ktore pomieszczenie usunac?";
		displayRooms();
		int c = -1;
		cin >> c;
		c--;
		rooms.erase(std::remove(rooms.begin(), rooms.end(), rooms.at(c)), rooms.end());
		cout << "\nPomyslnie usunieto pomieszczenie";
	} else {
		cout << endl << "Brak dodanych pomieszczen!";
	}
}

void AppInterface::addSensor(DummyRoom *dr){
	cout << "\nWybierz rodzaj czujnika: " << endl;
	int c = -1;
	cout << "\n1. Temperatury";
	cout << "\n2. Ruchu";
	cout << "\n3. Dymu" << endl;
	cin >> c;

	if(c > 3 || c < 1){
		cout <<"Zly numer czujnika!"<<endl;
	} else {
		cout << "\nPodaj nazwe czujnika: " << endl;
		string name;
		cin >> name;
		if(c == 1){
			TempSensor *s = new TempSensor(name);
			dr->Attach(s);
		} else if(c == 2){
			MotionSensor *ms = new MotionSensor(name);
			dr->Attach(ms);
		} else if(c == 3){

		}

	}

}
























