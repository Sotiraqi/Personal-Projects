#pragma warning(disable : 4996)

#include "parkingspot.h"

bool CParkingSpot::setSpot(int parking_time)
{
	time_t now = time(0);
	char* dt = ctime(&now);

	if (isOccupated)
	{
		

		return true;
	}

	
}

string CParkingSpot::carPlate()
{
	string carplate;
	cin >> carplate;
	return carplate;
}

int CParkingSpot::calculate_rest(int t_sum, int t_price)
{
	int rest = t_sum - t_price;
	
	if (rest < 0)
		cout << "Krediti juaj nuk mjafton!";
	else
		cout << "Merrni kusurin: "<< rest << endl;
	return 0;
}
