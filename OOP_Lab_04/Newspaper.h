#pragma once
#include "PrintedProducts.h"
#include <iostream>

class Newspaper : public PrintedProducts
{
private:
	int pageHeight = 0;
	int pageWidth = 0;
	int Amount = 0;
	int Period = 0;
	void Swap(Newspaper& obj);
	const std::string NamePeriod() const;
public:
	Newspaper();											
	Newspaper(
		const std::string AuthorName, 
		const std::string title, 
		const double pages, 
		const int pageHeight,
		const int pageWidth,
		const int Amount, 
		const int Period);
	~Newspaper();
	Newspaper(const Newspaper& obj);						

	const int GetAmount() const;
	const int GetPeriod() const;
	const int GetPageHeight() const;
	const int GetPageWidth() const;

	const long double GetNewspaperCost() const;

	Newspaper& operator = (Newspaper obj);					// TODO: asignment operator inheritance
	friend std::ostream& operator << (std::ostream& out, const Newspaper& product);
};

