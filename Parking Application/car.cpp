#include "car.h"

using namespace std;

void Car::setPlates()
{
	cout << "Please enter the plates of your car: ";
	cin >> plates;
}

std::string Car::getPlates()
{
	return plates;
}


