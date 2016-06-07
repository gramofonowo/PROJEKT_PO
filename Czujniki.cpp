#include <iostream>
#include "AppInterface.h"
#include<windows.h>

using namespace std;

int main () {

	srand(1234);

	DummyRoom *dr = new DummyRoom("Salon");
	TempSensor *s1 = new TempSensor("tempsens1");
	MotionSensor *s2 = new MotionSensor("motionsens1");
	SmokeSensor *s3 = new SmokeSensor("smokesens1");

	dr->Attach(s3);
	dr->Attach(s1);
	dr->Attach(s2);

	cout << endl;

	float i = 0.5;
	float f = dr->getRoomTemp();
	for(int j = 0; j < 10; j++){

		i += 0.5;
		i *= -1;
		f += i;
		cout << endl << " ==== UPDATE CZUJNIKOW W " << dr->getName() << " ===" << endl;
		dr->UpdateSensors(f);
		cout << endl;
		Sleep(1000);
	}

		/*


		TempSensor s1("13");
		room.Attach(&s1);
		MotionSensor s2("tesest");
		room.Attach(&s2);
				float i = 0.5;
		for(int j = 0; j < 10; j++){
			float f = 17 + i;
			i += 0.5;
			i *= -1;
			room.ChangeTemperature(f + i);
		}

			vector<Sensor*> v =room.getV("v");
		v.at(0)->getStatus();

	TempSensor s2("23");
	TempSensor s3("34");
	TempSensor s4("45");
	MotionSensor s5("ms");




	room.Attach(&s2, 1);
	room.Attach(&s3, 1);
	room.Attach(&s4, 1);
	room.Attach(&s5, 3);

//	room.ChangeTemperature(22.0f);
//
	room.Detach(&s2);
	room.Detach(&s3);
//	room.Detach(&s4);
//	room.ChangeTemperature(16.0f);



	cout <<"\nSize: t = " << room.getV("t").size();
		cout <<", m = " << room.getV("m").size();
		cout <<", s = " << room.getV("s").size();
		cout <<", v = " << room.getV("ddd").size();
		cout <<"... \n";




	AppInterface ai;
	ai.menu();
*/

	return 0;
}

