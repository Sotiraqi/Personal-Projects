#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class CParkingSpot
{
private:
	bool isOccupated = false;
public:
	bool setSpot(int parking_time);
	string carPlate();
	int calculate_rest(int sum, int t_price);
};

