#include "Date.h"
#include <iostream>
#include <stdio.h>

using namespace std;


bool Date::IsValidDay(int day, int month, int year)
{

	switch (month) {
	case 1: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 2: {
		return (day >= 1 && day <= 29);
		break;
	}
	case 3: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 4: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 5: {
		return (day >= 1 && day <= 30);
		break;
	}
	case 6: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 7: {
		return (day >= 1 && day <= 30);
		break;
	}
	case 8: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 9: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 10: {
		return (day >= 1 && day <= 30);
		break;
	}
	case 11: {
		return (day >= 1 && day <= 31);
		break;
	}
	case 12: {
		return (day >= 1 && day <= 31);
		break;
	}
	default: throw "Incorrect day";
	}
	
}
Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date() {
}

void Date::SetDate(int day, int month, int year)
{
	if (year <= 0)
	{
		throw "Incorrect year";
	}
	if (month <= 0 || month > 12)
	{
		throw "Incorrect month";
	}
	if (!this->IsValidDay(day, month, year))
	{
		throw "Incorrect day";
	}

	this->day = day;
	this->month = month;  
	this->year = year;
}

int Date::GetDay()
{
	return this->day;
}

int Date::GetMonth()
{
	return this->month;
}

int Date::GetYear()
{
	return this->year;
}


