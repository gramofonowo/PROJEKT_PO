#include "AppInterface.h"
#include <algorithm>
#include <typeinfo>
#include <iterator>
#include <windows.h>

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
		cout << "\n3. Wyswietl pomieszczenia";
		cout << "\n4. Wyswietl czujniki";
		cout << "\n5. Usun pomieszczenie";
		cout << "\n6. Usun czujnik";
		cout << "\n7. Symulacja";
		cout << "\n8. Automatyczna implementacja czujnikow";
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
			break;
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
				if(v.size() > 0){
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
					cout << endl << "Brak dodanych czujnikow";
				}

			} else {
				cout << endl << "Brak dodanych pomieszczen!";
			}
			break;
		}
		case 7:{
			cout << endl << endl;
			simulate();
			break;
		}
		case 8:{
			cout << endl << endl;
			createDummyObjects();
			cout << endl << endl << "Temperatura idealna <20, 21>"<<endl;
			cout <<"Zagrozenie pozaru powyzej 10%"<<endl;
			simulate();
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
		vector<Sensor*> v = rooms.at(i)->getV("v");

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
			SmokeSensor *ss = new SmokeSensor(name);
			dr->Attach(ss);
		}

	}

}

void AppInterface::addRoom(DummyRoom *r){
	rooms.push_back(r);
}

void AppInterface::simulate(){

	float f = 20.0;

	if(rooms.size() > 0){
		int j = 0;
		cout << endl << "Ile symulacji przeprowadzic?";
		cin >> j;
		if(j > 0){
			for(int i = 0; i < j; i++){
				cout << "\n SYMULACJA NR " << (i+1) << endl;
				for(vector<DummyRoom*>::iterator it = rooms.begin(); it != rooms.end(); ++it){
					string temp = (*it)->getName();
					vector<Sensor*> v = (*it)->getV("v");

					if(v.size() > 0){

						cout << endl << " ==== SYMULACJA CZUJNIKOW W " << temp << " ===" << endl;
						(*it)->UpdateSensors(f);
						cout << endl;


					} else {
						cout << endl << temp << " nie ma dodanych czujnikow!";
					}
				}
				Sleep(1000);
			}
		} else {
			cout << endl << "Nieprawidlowa liczba!";
		}

	} else {
		cout << "\nBrak dodanych pomieszczen!";
	}
};



void AppInterface::createDummyObjects(){

	DummyRoom *dr = new DummyRoom("Salon");
	DummyRoom *dr2 = new DummyRoom("Kuchnia");
	DummyRoom *dr3 = new DummyRoom("Sypialnia");
	DummyRoom *dr4 = new DummyRoom("Pokoj dzienny");
	DummyRoom *dr5 = new DummyRoom("Garaz");


	TempSensor *ts = new TempSensor("temp_sens_Salon");
	TempSensor *ts2 = new TempSensor("temp_sens_Kuchnia");
	TempSensor *ts3 = new TempSensor("temp_sens_Sypialnia");
	TempSensor *ts4 = new TempSensor("temp_sens_Pokoj_dzienny");
	TempSensor *ts5 = new TempSensor("temp_sens_Garaz");

	MotionSensor *ms = new MotionSensor("motion_sens_Salon");
	MotionSensor *ms2 = new MotionSensor("motion_sens_Kuchnia");
	MotionSensor *ms3 = new MotionSensor("motion_sens_Sypialnia");
	MotionSensor *ms4 = new MotionSensor("motion_sens_Pokoj_dzienny");
	MotionSensor *ms5 = new MotionSensor("motion_sens_Garaz");

	SmokeSensor *ss = new SmokeSensor("smoke_sens_Salon");
	SmokeSensor *ss2 = new SmokeSensor("smoke_sens_Kuchnia");
	SmokeSensor *ss3 = new SmokeSensor("smoke_sens_Sypialnia");
	SmokeSensor *ss4 = new SmokeSensor("smoke_sens_Pokoj_dzienny");
	SmokeSensor *ss5 = new SmokeSensor("smoke_sens_Garaz");

	dr->Attach(ts);
	dr->Attach(ss);
	dr->Attach(ms);

	dr2->Attach(ts2);
	dr2->Attach(ss2);
	dr2->Attach(ms2);

	dr3->Attach(ts3);
	dr3->Attach(ss3);
	dr3->Attach(ms3);

	dr4->Attach(ts4);
	dr4->Attach(ss4);
	dr4->Attach(ms4);

	dr5->Attach(ts5);
	dr5->Attach(ss5);
	dr5->Attach(ms5);


	rooms.push_back(dr);
	rooms.push_back(dr2);
	rooms.push_back(dr3);
	rooms.push_back(dr4);
	rooms.push_back(dr5);
};

















