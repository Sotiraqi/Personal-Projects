#ifndef CITYPARKINGAREAS_H
#define CITYPARKINGAREAS_H

#include "parkingarea.h"



//Setting the parking areas.

//Central Areas
ParkingArea* g_centralParkingArea[2] = { new ParkingArea("C0001", "center", "orange", 40), 
									   new ParkingArea("C0002", "center", "purple", 30) };	

//Busy Areas
ParkingArea* g_busyParkingArea[4] = { new ParkingArea("B0001", "busy", "orange", 20), 
									new ParkingArea("B0002", "busy", "purple", 60), 
									new ParkingArea("B0003", "busy", "purple", 40), 
									new ParkingArea("B0004", "busy", "purple", 40) };	

//Residential Areas
ParkingArea* g_residentialParkingArea[6] = { new ParkingArea("R0001", "residential", "blue", 80),
										   new ParkingArea("R0002", "residential", "blue", 90),
										   new ParkingArea("R0003", "residential", "blue", 90),
										   new ParkingArea("R0004", "residential", "blue", 70),
										   new ParkingArea("R0005", "residential", "blue", 60),
										   new ParkingArea("R0006", "residential", "blue", 80) };

#endif // !CITYPARKINGAREAS_H
