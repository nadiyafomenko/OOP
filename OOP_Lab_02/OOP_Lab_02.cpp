
#include <iostream>
#include "Date.h"


#define MAX 5 //максимальна кількість об'єктів дати

using namespace std;

int main()
{
	//створення об'єкту з поточною датою
	Date* currentDate = new Date();
	int currentDay = currentDate -> getCurrentDay();
	int currentMonth = currentDate->getCurrentMonth();
	int currentYear = currentDate->getCurrentYear();
	printf("Today is %d-%d-%d\n", currentDay, currentMonth, currentYear);
	currentDate->SetDate(currentDay, currentMonth, currentYear);



	Date date_mas[MAX];
	int day = 0, month = 0, year = 0, p, i = 0;

	do
	{
		Date* date = new Date();
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

			//виділення динамічної пам'яті

			printf("Change format: \n 1.DD/MM/YYYY \n 2.YYYY-MM-DD\n");
			scanf_s("%d", &format);


			switch (format)
			{
			case 1:
				printf("%d/%d/%d", date->GetDay(), date->GetMonth(), date->GetYear());
				nextDay1 = date->GetDay() + 1;
				printf("\nNext day:  %d/%d/%d", nextDay1, date->GetMonth(), date->GetYear());
				break;
			case 2:
				printf("%d-%d-%d", date->GetDay(), date->GetMonth(), date->GetYear());
				nextDay2 = date->GetDay() + 1;
				printf("\nNext day:  %d-%d-%d", nextDay2, date->GetMonth(), date->GetYear());
				break;
			default: printf("Wrong format");
			}
		}
		catch (const char* msg)
		{
			cerr << msg << endl;
		}

		
		//заповнення масиву об'єктів 
		date_mas[i] = *date; //запис екземпляру класу у масив об'єктів 
		i++;


		Date *decrementedDate = date--;
		printf("%d", decrementedDate->GetDay());


		delete date; //звільнення пам'яті для запису наступного об'єкту 

		//можливість додавання ще одного об'є'кту або вихід з циклу
		printf("\n\nif you want to enter one more press 1:");
		scanf_s("%d", &p);
		if (p == 0) break;
	} while (p == 1);




	system("pause");
	return 0;
}

