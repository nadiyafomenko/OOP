#pragma once

class Date
{
private:
	int day;
	int month;
	int year;

	bool IsValidDay();

public:
	Date();
	Date(int day, int month, int year);
	Date(const Date& date);
	~Date();

	void SetDate(int day, int month, int year);

	int GetDay();
	int GetMonth();
	int GetYear();

	const int getCurrentYear();
	const int getCurrentDay();
	const int getCurrentMonth();

	Date operator < (Date day1);
	Date operator--();
};

