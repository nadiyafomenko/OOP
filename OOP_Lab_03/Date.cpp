#include "Date.h"
#include <iostream>
#include <string>

Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;

}
Date::Date(unsigned day, unsigned month, unsigned year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
	//
}

void Date::SetDay(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;

	if (year <= 0)
	{
		throw "Incorrect year";
	}
	if (month <= 0 || month > 12)
	{
		throw "Incorrect month";
	}
	if (isValid() != true )
	{
		throw "Incorrect day";
	}


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

bool Date::isValid()
{
	return this->day > 0 and this->day <= daysInMonths[this->month - 1];
}

int Date::GetCurrentDay()
{
	return this->currentDay;
}

int Date::GetCurrentMonth()
{
	return this->currentMonth;
}

int Date::GetCurrentYear()
{
	return this->currentYear;
}

bool Date::operator<(Date& day) {
	int thisvalue = this->year * 365 + this->month * 31 + this->day;
	int dayvalue = day.year * 365 + day.month * 31 + day.day;
	return(thisvalue > dayvalue);
}

Date& Date::operator--()
{
	day--;
	return *this;
}


