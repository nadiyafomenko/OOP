#pragma once

class Date
{
private:
	int day;
	int month;
	int year;

	bool IsValidDay(int day, int month, int year);

public:
	Date();
	Date(int day, int month, int year);
	~Date();

	void SetDate(int day, int month, int year);

	int GetDay();
	int GetMonth();
	int GetYear();

	//void PrintDate(Date day);
};

