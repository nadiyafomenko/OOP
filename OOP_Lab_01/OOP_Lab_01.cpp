#include <iostream>
#include "Date.h"

using namespace std;

int main()
{
	int day = 0, month = 0, year = 0, p;
	Date* date = new Date(1,1,1);

	try
	{

		int format;
		int nextDay1 = 0;
		int nextDay2 = 0;


		printf("Day:  \n");
		scanf_s("%d", &day);
		printf("Month:  \n");
		scanf_s("%d", &month);
		printf("Year:  \n");
		scanf_s("%d", &year);
		date->SetDate(day, month, year);

		printf("%d/%d/%d", date->GetDay(), date->GetMonth(), date->GetYear());

		} catch (const char* msg) {
			cerr << msg << endl;
		}

		delete date; 

		system("pause");
		return 0;
}

