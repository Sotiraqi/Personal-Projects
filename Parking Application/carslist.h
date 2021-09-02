#ifndef CARSLIST_H
#define CARSLIST_H

#include "car.h"


class CarsList
{
private:
	typedef struct Node
	{
		Car* car;
		Node* next;
	}* nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;
public:
	CarsList();
	void addCar(Car* car);
	void removeCar(Car* car);
	void printCars();
};



#endif