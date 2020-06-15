#include <iostream>
#include <string>
#include "PrintedProducts.h"
#include "Newspaper.h"
#include "Booklet.h"


void Sort(PrintedProducts** mas);
void SetNewspaperProduct(PrintedProducts** mas);
void SetBookletProduct(PrintedProducts** mas);

int count = 0;

int main()
{
	PrintedProducts* PrintedProductsMas[15];

	try {
		int p = 0;
		do {
			char product;
			std::cout << "Choose a product:\n1. Newspaper(press n)\n2. Booklet(press b)" << std::endl;
			std::cin >> product;
			if (product == 'n') 
			{
				SetNewspaperProduct(PrintedProductsMas);
			}
			else if (product == 'b') 
			{
				SetBookletProduct(PrintedProductsMas);
			}
			else  
			{
				throw "incorrect input type. Please enter \"n\" or \"b\" only";
			}

			std::cout << "Add one more product press 0, finish press 1 \n";
			std::cin >> p;
		} while (p == 0);

		Sort(PrintedProductsMas);
		for (int i = 0; i < count; i++) {
			std::cout << "Newspaper's table: " << std::endl;
			std::cout << (*PrintedProductsMas[i]) << std::endl;
		}
	}
	catch (const char* msg) {
		std::cout << "\n" << "Error:" << "\t";
		std::cout << msg << std::endl;
	}

}


void Sort(PrintedProducts** mas) {
	for (int i = 0; i < count; i++) {
		int min = i;
		for (int j = i + 1; j < count; ++j)
		{
			if (mas[j]->GetPaperConsumption() < mas[min]->GetPaperConsumption())
				min = j;
		}
		std::swap(mas[i], mas[min]);
	}
}

void SetNewspaperProduct(PrintedProducts** mas)
{
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
		Newspaper* newspaper = new Newspaper(authorName, title, pages, pageHeight, pageWidth, amount, period);
		mas[count] = newspaper;
		count++;
	}
	catch (const char* msg) {
		std::cout << "\n" << "Error:" << "\t";
		std::cout << msg << std::endl;
	}

}

void SetBookletProduct(PrintedProducts** mas)
{
	std::string authorName;
	std::string title;
	double pages;
	std::string pageSize;
	int amount;
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

	try {
		Booklet* booklet = new Booklet(authorName, title, pages, pageHeight, pageWidth, amount);
		mas[count] = booklet;
		count++;
	}
	catch (const char* msg) {
		std::cout << "\n" << "Error:" << "\t";
		std::cout << msg << std::endl;
	}
}

