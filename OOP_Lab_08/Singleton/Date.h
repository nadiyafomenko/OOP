#pragma once


class Date
{
private:
	int day;
	int month;
	int year;

	Date();
	Date(unsigned day, unsigned month, unsigned year);
	~Date();

	int daysInMonths[12] = { 31, 29, 31, 31, 30, 31, 30, 31, 31, 30, 31, 31 };
	bool isValid();
public:

	static Date* Instance();

	Date(Date& other) = delete;

	void operator=(const Date&) = delete;

	void SetDay(int day, int  month, int year);

	int GetDay();
	int GetMonth();
	int GetYear();

	void Write(const char* separator);
	void WriteLine(const char* separator);
};
