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
protected:
	void Print(std::ostream& out);
public:
	Newspaper();
	Newspaper(
		const std::string AuthorName,
		const std::string title,
		int pages,
		const int pageHeight,
		const int pageWidth,
		const int Amount,
		const int Period);
	~Newspaper();

	const int GetAmount() const;
	const int GetPeriod() const;
	const int GetPageHeight() const;
	const int GetPageWidth() const;

	const double GetPaperConsumption();
};

