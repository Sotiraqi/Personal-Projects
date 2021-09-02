#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <chrono>
#include "parkingarea.h"

class Car
{
private:
	std::string plates;	// Car plates
	
public:
	time_t endTime;
	std::string areaId;
	void setPlates();	
	std::string getPlates(); 
};



#endif
