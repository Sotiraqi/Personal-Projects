#pragma warning(disable : 4996) //Bug VSC 2019 (ctime function)
#include <iomanip>
#include <chrono>
#include "carslist.h"

using namespace std;
using namespace chrono;

CarsList::CarsList()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void CarsList::addCar(Car* car)
{
	nodePtr n = new Node;
	n->next = NULL;
	n->car = car;

	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
	}
	else
	{
		head = n;
	}
}

void CarsList::removeCar(Car* car)
{
	system_clock::time_point tm = system_clock::now();
	time_t currentTime = system_clock::to_time_t(tm);
	
	if (currentTime == car->endTime)
	{
		nodePtr n = NULL;
		temp = head;
		curr = head;

		while (curr != NULL && curr->car != car)
		{
			temp = curr;
			curr = curr->next;
		}

		if (curr == NULL)
		{
			cout << "Car not found" << endl;
			delete n;
		}
		else
		{
			n = curr;
			curr = curr->next;
			temp->next = curr;

			if (car == head->car)
			{
				head = head->next;
				temp = NULL;
			}

			delete n;
			cout << "Car time expired!" << endl;
		}
	}
	
}

void CarsList::printCars()
{
	curr = head;
	while (curr != NULL)
	{
		cout << "Plates: " << curr->car->getPlates() << " Area ID: " << curr->car->areaId << " - Finish time: " << ctime(&curr->car->endTime) << endl;
		curr = curr->next;
	}
}

