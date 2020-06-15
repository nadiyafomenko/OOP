#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;


bool Date::IsValidDay()
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
	default: printf("error...");
	}

}
Date::Date()
{
	this->day = 1;
	this->month = 1;
	this->year = 1;
	/*printf("Constructor....\n");*/
}
Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
	/*printf("Constructor....\n");*/
}
Date::Date(const Date& date)
{
	day = date.day;
	month = date.month;
	year = date.year;
}

Date::~Date() {
	//printf("Destructor....\n");
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
	if (!this->IsValidDay())
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

const int Date::getCurrentYear()
{
	time_t t;
	time(&t);
	int year = localtime(&t)->tm_year;
	year += 1900;
	return year;
}

const int Date::getCurrentDay()
{
	time_t t;
	time(&t);
	int day = localtime(&t)->tm_mday;
	return day;
}

const int Date::getCurrentMonth()
{
	time_t t;
	time(&t);
	int month = localtime(&t)->tm_mon;
	return month + 1;
}



Date Date::operator<(Date day)
{
	this->day = day.day - getCurrentYear();
	this->month = day.month - getCurrentDay();
	this->year = day.year - getCurrentMonth();
	return Date();
}

Date Date::operator--()
{
	Date temp;
	temp.day = --day;
	return temp;
}


