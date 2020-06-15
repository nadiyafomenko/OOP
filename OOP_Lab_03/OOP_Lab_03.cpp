#include <iostream>
#include "Date.h"

int count = 0;

void Sort(Date* mas);

int main() {


    Date DaysMas[12];
    int p = 0, i = 0;
    int day, month, year;

    Date* tempday = new Date();
    do 
    {
       

        try 
        {
            std::cout << "Year:  ";
            std::cin >> year;

            std::cout << "Month:  ";
            std::cin >> month;

            std::cout << "Day:  ";
            std::cin >> day;
            tempday->SetDay(day, month, year);



            //заповнення масиву екземплярів класу
            DaysMas[i] = *tempday; count++; i++;
            
            std::cout << tempday->GetDay() << "-" << tempday->GetMonth() << "-" << tempday->GetYear();
        }
        catch (const char* msg)
        {
            std::cerr << msg << std::endl;
        }

        
        
       
        std::cout << "\nif you want to add one more day press 1 (else press 0):   ";
        std::cin >> p;
    } while (p == 1);

    Sort(DaysMas);

    std::cout << "\nSorted days table:" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << DaysMas[i].GetDay() << "-" << DaysMas[i].GetMonth() << "-" << DaysMas[i].GetYear() << std::endl;
    }

    std::cout << "\nShowing -- operator overloading:" << std::endl;
    for (int i = 0; i < count; i++) {
        --DaysMas[i];
        std::cout << DaysMas[i].GetDay() << "-" << DaysMas[i].GetMonth() << "-" << DaysMas[i].GetYear() << std::endl;
    }

    return 0;
}

void Sort(Date *mas) {
    for (int i = 0; i < count; i++) {
        int min = i;
        for (int j = i + 1; j < count; ++j)
        {
            if (mas[j] < mas[min])
                min = j;
        }
        std::swap(mas[i], mas[min]);
    }
}



//Алгоритм:
//1. Створення масиву екземплярів класу
//2. Функція яка обчислює значення різниці від поточної дати за допомогою "<" та викликає функцію сортування. Приймає силку на масив екземпярів
//3. Функція сортування, яка приймає 