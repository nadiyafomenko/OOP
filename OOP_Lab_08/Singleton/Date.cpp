#include "Date.h"
#include <iostream>

Date::Date() {
	std::cout << "Default constructor" << std::endl;
}

Date::Date(unsigned day, unsigned month, unsigned year)
{
	std::cout << "Constructor with parameters" << std::endl;

	this->day = day;
	this->month = month;
	this->year = year;
}

Date::~Date()
{
	std::cout << "Destructor" << std::endl;
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
	if (isValid() != true)
	{
		throw "Incorrect day";
	}
}

bool Date::isValid()
{
	return this->day > 0 and this->day <= daysInMonths[this->month - 1];
}

Date* Date::Instance()
{
	static Date Instance(1,1,1);
	return &Instance;
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

void Date::Write(const char* separator)
{
	std::cout << "Date: " << day << separator << month << separator << year;
}

void Date::WriteLine(const char* separator)
{
	std::cout << "Date: " << day << separator << month << separator << year << std::endl;
}
