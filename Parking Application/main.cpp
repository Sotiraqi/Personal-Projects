#pragma warning(disable : 4996)

#include "parkingspot.h"
#include "card.h"
#include <iostream>
#include <map>
#include <conio.h>

using namespace std;

int main()
{
	int i = 0;
	int choose;

	map<string, time_t, time_t> parkingSpots(20);
	CParkingSpot parkspots[20];
	CCard card;
	int parking_time, sum, pin_code;

	while (i != 1)
	{
		cout << "Pazari-Seksioni 1" << endl;
		time_t now = time(0);
		char* dt = ctime(&now);
		cout << "Ora: " << dt << endl;
		cout << "Cmimi i biletes: 50 LEK - 1 ORE" << endl;
		cout << "Menyra e pageses: " << endl;
		cout << "1.Paguaj Cash" << endl;
		cout << "2.Paguaj me karte krediti/debiti" << endl;
		cout << "3.Paguaj me telefon" << endl;
		i = 1;
	}	

	cin >> choose;
	
	if (choose == 1)
	{
		cout << "Ju lutem paraqisni targen e makines tuaj: "; //cin
		parkspots->carPlate();
		cout << "Ju lutem paraqisni kohezgjatjen e parkimit:"; //cin
		cin >> parking_time;
		parkspots->setSpot(parking_time);
		cout << "Ju lutem prezantoni monedha ose kartmonedha." << endl;
		cout << "Kujdes! Prerjet 1000, 2000 dhe 5000 LEK nuk jane te lejuara!" << endl;
		cout << "Shuma: "; 
		cin >> sum;
		parkspots->calculate_rest(sum, 50 * parking_time);

	}
	else if (choose == 2)
	{
		cout << "Ju lutem paraqisni targen e makines tuaj: "; //cin
		parkspots->carPlate();
		cout << "Ju lutem paraqisni kohezgjatjen e parkimit:"; //cin
		cin >> parking_time;
		parkspots->setSpot(parking_time);
		cout << "Ju lutem prezantoni karten e kreditit." << endl;
		cout << "Ju lutem prezantoni PIN: ";
		cin >> pin_code;
		if (card.check_pin(pin_code))
		{
			parkspots->calculate_rest(card.money, 50 * parking_time);
		}

	}
	else if (choose == 3)
	{
		cout << "Pershendetje, pagesen nepermjet telefonit mund ta kryeni" << endl;
		cout << "duke derguar nje mesash ne numrin 50505 i cili permban targen" << endl;
		cout << "tuaj, kohezgjatjen e parkimit dhe fjalen 'pazari'" << endl;
	}
		
	return 0;
}