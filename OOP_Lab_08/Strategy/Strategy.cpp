#include <iostream>
#include <string>

#include "PrintedProducts.h"
#include "Newspaper.h"
#include "Booklet.h"

#include "Context.h"
#include "BookletConsumption.h"
#include "NewspaperConsumption.h"


void PrintTable(PrintedProducts** mas);



int main() {
	
	PrintedProducts* mas[2];

	mas[0] = new Newspaper("Newapaper author", "Newspaper", 126, 12, 1, 10, 2);
	mas[1] = new Booklet("Booklet author", "Booklet", 10, 24, 2, 1);

	PrintTable(mas);

	Context* n_context = new Context(new NewspaperConsumption);
	double n_result = n_context->CalculateConsumption(12, 1, 10, 2);
	std::cout << "Newspaper paper consumption: " << n_result << std::endl;

	Context* b_context = new Context(new BookletConsumption);
	double b_result = b_context->CalculateConsumption(10, 24, 2, 1);
	std::cout << "Booklet paper consumption: " << b_result << std::endl;

}



void PrintTable(PrintedProducts** mas)
{
	for (int i = 0; i < 2; i++) {
		std::cout << (*mas[i]) << std::endl;
	}
}
