#pragma warning(disable : 4996) //Bug VSC 2019 (ctime function)
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <ctime>
#include <conio.h>
#include <chrono>
#include <iomanip>
#include "parkingarea.h"
#include "car.h"
#include "cityparkingareas.h"
#include "carslist.h"


using namespace std;
using namespace chrono;

CarsList parkingList;

void showTime();
int getTime(Car* car, int upperTimeBound);
void applicationMenu(Car* car); //Main program menu
void parkingProcess(Car* car, ParkingArea* parkingArea[]);
void calculatePrice(Car* car, ParkingArea* parkingarea);
void carGenerator();

/* ----------------- Implementation -------------------*/

inline void showTime()
{
	system_clock::time_point tm = system_clock::now();
	time_t currentTime = system_clock::to_time_t(tm);
	cout << ctime(&currentTime) << endl;
	
	
}

inline int getTime(Car* car, int upperTimeBound)
{
	using clock = std::chrono::system_clock;
	cout << "Enter the time that you want to add in minutes" << endl;
	int time_min;
	cin >> time_min;
	cin.ignore();

	if (time_min % 15 != 0)
	{
		cout << "Invalid minutes, must be a multiple of 15!" << endl;
		getTime(car, upperTimeBound);
	}
	else if (time_min < 15 || time_min > upperTimeBound)
	{
		cout << "Invalid minutes, check the parking type and try again!" << endl;
		getTime(car, upperTimeBound);
	}
	else
	{
		clock::time_point nowp = clock::now();
		clock::time_point end = nowp + std::chrono::minutes(time_min);
		time_t nowt = clock::to_time_t(nowp);
		time_t endt = clock::to_time_t(end);
		car->endTime = endt;		
		cout << "Parking time starts on:" << ctime(&nowt) << "\n";
		cout << "and finishes on: " << ctime(&endt) << std::endl;

		return time_min;
	}
}

void applicationMenu(Car* car)
{
	cout << "Welcome client, the time is: ";
	showTime();
	cout << "Please select the city area: " << endl;
	cout << "1. Center" << endl;
	cout << "2. Busy area" << endl;
	cout << "3. Residential" << endl;

	char c = _getch();

	switch (c)
	{
	case 48:
		parkingList.printCars();
		applicationMenu(car);
	case 49:
		parkingProcess(car, g_centralParkingArea);
	case 50:
		parkingProcess(car, g_busyParkingArea);
	case 51:
		parkingProcess(car, g_residentialParkingArea);
	default:
		cout<<"Invalid selection please try again!";
		applicationMenu(car);
	}
	
		
}

inline void parkingProcess(Car* car, ParkingArea* parkingArea[])
{
	cout << "Please choose area by id: " << endl;

	if (parkingArea == g_centralParkingArea)
	{
	step1:
				
		for (int i = 0; i < 2; i++) //2 parking areas
		{
			cout << i + 1 << "." << g_centralParkingArea[i]->getParkingId() << endl;
		}


		char c = _getch();

		if (c == 49)
		{
			calculatePrice(car, g_centralParkingArea[0]);
		}
		else if (c == 50)
		{
			calculatePrice(car, g_centralParkingArea[1]);
		}
		else
		{
			cout << "Invalid command" << endl;
			goto step1;
		}
	}
	else if (parkingArea == g_busyParkingArea)
	{
	step2:
		for (int i = 0; i < 4; i++) // 4 parking areas
		{
			cout << i + 1 << "." << g_busyParkingArea[i]->getParkingId() << endl;
		}

		char c = _getch();

		switch (c)
		{
		case 49:
			calculatePrice(car, g_busyParkingArea[0]);
		case 50:
			calculatePrice(car, g_busyParkingArea[1]);
		case 51:
			calculatePrice(car, g_busyParkingArea[2]);
		case 52:
			calculatePrice(car, g_busyParkingArea[3]);
		default:
			cout << "Invalid command"<<endl;
			goto step2;
		}
	}
	else
	{
	step3:
		for (int i = 0; i < 6; i++) // 6 parking areas
		{
			cout << i + 1 << "." << g_residentialParkingArea[i]->getParkingId() << endl;
		}

		char c = _getch();

		switch (c)
		{
		case 49:
			calculatePrice(car, g_residentialParkingArea[0]);
		case 50:
			calculatePrice(car, g_residentialParkingArea[1]);
		case 51:
			calculatePrice(car, g_residentialParkingArea[2]);
		case 52:
			calculatePrice(car, g_residentialParkingArea[3]);
		case 53:
			calculatePrice(car, g_residentialParkingArea[4]);
		case 54:
			calculatePrice(car, g_residentialParkingArea[5]);
		default:
			cout << "Invalid command" << endl;
			goto step3;
		}
	}	
}

inline void calculatePrice(Car* car, ParkingArea* parkingarea)
{
	
	//Prices List
	float pricePerHour;
	if (parkingarea->location == "center")
	{
		pricePerHour = 80.0; //price if location is center
	}
	else if (parkingarea->location == "busy")
	{
		//if()
		pricePerHour = 40.0; //price if location is busy
	}
	else if (parkingarea->location == "residential")
	{
		pricePerHour = 20.0; // price if location is residential
	}
	else
	{
		pricePerHour = 40.0; // default price
	}

	Car newCar;

	car->setPlates();
	cout << "Please choose the time you would like to park: ";
	
	if (parkingarea->type == "orange")
	{
		cout << "Orange type (15 minutes - 1 hour)"<<endl;
		car->areaId = parkingarea->getParkingId();
		float total = ((float)getTime(car, 60)/60) * pricePerHour;
		cout << "Total to pay: " << total << endl;
		parkingList.addCar(car);	
		carGenerator();
				
	}
	else if (parkingarea->type == "purple")
	{
		cout << "Purple type (15 minutes - 3 hours)" << endl;
		car->areaId = parkingarea->getParkingId();
		float total = ((float)getTime(car, 180) / 60) * pricePerHour;
		cout << "Total to pay: " << total << endl;
		parkingList.addCar(car);
		carGenerator();
	}
	else
	{
		cout << "Blue type (15 minutes - 24 hours)" << endl;
		car->areaId = parkingarea->getParkingId();
		float total = ((float)getTime(car, 1440) / 60) * pricePerHour;
		cout << "Total to pay: " << total << endl;
		parkingList.addCar(car);
		carGenerator();
	}
}

inline void carGenerator()
{
	Car* randomCars = new Car();
	applicationMenu(randomCars);
}




#endif
