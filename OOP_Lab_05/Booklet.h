#pragma once
#include "PrintedProducts.h"
#include <iostream>

class Booklet : public PrintedProducts 
{
private:
	int pageHeight = 0;
	int pageWidth = 0;
	int Amount = 0;
protected:
	void Print(std::ostream& out);
public:
	Booklet();
	Booklet(
		const std::string AuthorName,
		const std::string title,
		int pages,
		const int pageHeight,
		const int pageWidth,
		const int Amount
	);
	~Booklet();

	const int GetAmount() const;
	const int GetPageHeight() const;
	const int GetPageWidth() const;

	const double GetPaperConsumption() override;
};

