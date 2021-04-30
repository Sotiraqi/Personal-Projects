#pragma once
class CCard
{
	int pin = 1234;
public:
	int money = 50000;
	bool check_pin(int PIN);
};

