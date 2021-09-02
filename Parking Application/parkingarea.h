#ifndef PARKINGAREA_H
#define PARKINGAREA_H

#include <iostream>
#include "car.h"

class ParkingArea
{
	friend class Car;

public:
	//Variables
	std::string id; //Unique ID for every parking space
	std::string location; // Central, residential, outskirt
	std::string type; // Orange, Purple, Blue 
	int capacity;	// Total parking capacity
	double pricePerHour; // Depending from location
	time_t startingTime;	// The time a car arrives at the spot.

	//Constructor
	ParkingArea(std::string id, std::string location, std::string type, int capacity);
	
	//Functions
	std::string getParkingId();
	std::string getLocation();
	std::string getType();
};

#endif