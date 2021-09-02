#include "parkingarea.h"

using namespace std;

ParkingArea::ParkingArea(string id, string location, string type, int capacity) : id(" "), location(" "), type(" "), capacity(0), pricePerHour(0), startingTime(0)
{
	this->id = id;
	this->location = location;
	this->type = type;
	this->capacity = capacity;

}

string ParkingArea::getLocation()
{
	return location;
}

string ParkingArea::getParkingId()
{
	return id;
}

string ParkingArea::getType()
{
	return type;
}