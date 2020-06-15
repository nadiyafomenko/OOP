#include <iostream>
#include <string>
#include "PrintedProducts.h"
#include "Newspaper.h"

int count = 0;
void Sort(Newspaper* mas);

int main()
{
	Newspaper NewspaperMas[15];
	int i = 0;
	int p = 0;
	do {
		std::string authorName;
		std::string title;
		double pages;
		std::string pageSize;
		int amount;
		int period;
		int pageHeight;
		int pageWidth;

		
		std::cin.ignore();
		std::cout << "Enter autor's name:\t";
		std::getline(std::cin, authorName);
		std::cout << "Enter a title:\t";
		std::getline(std::cin, title);
		std::cout << "Enter amount of pages:\t";
		std::cin >> pages;
		std::cout << "Enter a page height:\t";
		std::cin >> pageHeight;
		std::cout << "Enter a page height:\t";
		std::cin >> pageWidth;
		std::cout << "Enter a product amount:\t";
		std::cin >> amount;
		std::cout << "Enter a period:\t";
		std::cin >> period;
		
		

		try {
			Newspaper newspaper(authorName, title, pages, pageHeight, pageWidth, amount, period);
			NewspaperMas[i] = newspaper; i++; count++;
		}
		catch (const char* msg) {
			std::cout << "\n" << "Error:" << "\t";
			std::cout << msg << std::endl;
		}

		
		std::cout << "Add one more product press 0, finish press 1 \n";
		std::cin >> p;
	} while (p == 0);

	Sort(NewspaperMas);
	for (int i = 0; i < count; i++) {
		std::cout << "Newspaper's table: " << std::endl;
		std::cout << NewspaperMas[i] << std::endl;   
	}
	
}


void Sort(Newspaper* mas) {
	for (int i = 0; i < count; i++) {
		int min = i;
		for (int j = i + 1; j < count; ++j)
		{
			if (mas[j].GetNewspaperCost() < mas[min].GetNewspaperCost())
				min = j;
		}
		std::swap(mas[i], mas[min]);
	}
}