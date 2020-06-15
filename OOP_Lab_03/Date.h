#include <cstring>
#ifndef DATE_H
#define DATE_H


class Date
{
private:
	int day;
	int month;
	int year;

	int currentDay = 1;
	int currentMonth = 1;
	int currentYear = 1;

public:
	Date();
	Date(unsigned day, unsigned month, unsigned year);

	~Date();
	void SetDay(int day,int  month,int year);
	int GetDay();
	int GetMonth();
	int GetYear();

	bool isValid();


	int GetCurrentDay();

	int GetCurrentMonth();

	int GetCurrentYear();

	bool operator<(Date& day);

	Date& operator--();

	int daysInMonths[12] = { 31, 29, 31, 31, 30, 31, 30, 31, 31, 30, 31, 31 };

};

#endif // !DATE_H