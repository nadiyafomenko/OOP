//На основі контейнера vector побудувати стек цілих чисел.
//Виконати операції занесення елемента у стек, вилучення значення з вершини стеку, виведення усіх значень стеку на екран, 
//визначення кількості елементів стеку.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>

void readDataFromFile(std::vector<int>* v);
void readDataFromKeybord(std::vector<int>* v);
void PrintStack(std::vector<int>* v);
void PrintOutputInFile(std::vector<int>* v);

int main()
{
    std::vector<int> v;
    int option = 0;


    std::cout << "Choose option:\n";
    std::cout << "1. Read data from file\n2. From keybord\n";
    std::cin >> option;

    unsigned int time_start = clock();
    try {
        switch (option) {
        case 1: {
            readDataFromFile(&v);  //зчитуємо дані з файлу
            break;
        }
        case 2: {
            readDataFromKeybord(&v);  //зчитуємо дані з файлу
            break;
        }
        default: throw "incorrect option";
        }
    }
    catch (const char* msg)
    {
        std::cerr << msg << std::endl;
    }
    PrintStack(&v);

    v.pop_back();
    v.pop_back();

    PrintStack(&v);
    PrintOutputInFile(&v); //вносиму дані у файл
   
    
    v.clear();
    unsigned int time_end = clock();
    std::cout << "\nTime: " << ((double)time_end - (double)time_start) / 1000  << " s" << std::endl;
}

void readDataFromFile(std::vector<int>* v) {
    int numb;
    std::ifstream input("TestData.txt");
    if (input.is_open())
    {
        while (input >> numb)
        {
            v->push_back(numb);
        }
        input.close();
    }
    else throw "Error opening file";
}

void readDataFromKeybord(std::vector<int>* v)
{
    int numb;
    std::cout << "Enter numbers: (press 0 to break)" << std::endl;
    while (std::cin >> numb)
    {
        if (numb == 0) break;
        else v->push_back(numb);
        
    }
}

void PrintStack(std::vector<int>* v) {
    std::cout << "Stack - ";
    for (auto& v : *v) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
    std::cout << "Size: " << v->size() << std::endl;
}

void PrintOutputInFile(std::vector<int>* v)
{
    std::ofstream output("output.txt");

    output << "Stack - ";
    for (auto& v : *v) {
        output << v << " ";
    }
    output << std::endl;

    std::cout << "Output file is ready";

    output.close();
}
