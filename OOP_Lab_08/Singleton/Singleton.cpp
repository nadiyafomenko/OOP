#include <iostream>
#include "Date.h"

int main()
{
    Date* date = Date::Instance();
    Date* _date = Date::Instance();         // returned existed object
   // Date _date = new Date(20, 10, 20);    // Error: no suitable constructor exists
   
    try {
        int day;
        int month;
        int year;
        std::cout << "Day: ";
        std::cin >> day;
        std::cout << "Month: ";
        std::cin >> month;
        std::cout << "Year: ";
        std::cin >> year;

        date->SetDay(11, 10, 2020);
        date->SetDay(day, month, year);

        date->WriteLine("/");
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
}

