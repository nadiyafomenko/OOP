#include "Newspaper.h"
#include "PrintedProducts.h"

void Newspaper::Print(std::ostream& out)
{
	out
		<< "Newspaper table: " << std::endl
		<< "Title:" << "\t\t\t\t" << GetTitle() << std::endl
		<< "Author:" << "\t\t\t\t" << GetAuthorName() << std::endl
		<< "Pages:" << "\t\t\t\t" << GetPages() << std::endl
		<< "Page size:" << "\t\t\t" << GetPageWidth() << " x " << GetPageHeight() << std::endl
		<< "Amount:" << "\t\t\t\t" << GetAmount() << std::endl
		<< "Period:" << "\t\t\t\t" << GetPeriod() << std::endl;
}

Newspaper::Newspaper() : PrintedProducts()
{
	this->Amount = 0;
	this->pageHeight = 0;
	this->pageWidth = 0;
	this->Period = 0;
}

Newspaper::Newspaper(
	const std::string AuthorName,
	const std::string title,
	const double pages,
	const int pageHeight,
	const int pageWidth,
	const int Amount,
	const int Period) : PrintedProducts(AuthorName, title, pages)
{
	if (Amount < 0) {
		throw "wrong amount";
	}
	this->pageHeight = pageHeight;
	this->pageWidth = pageWidth;
	this->Amount = Amount;
	this->Period = Period;
}

Newspaper::~Newspaper() { }

const int Newspaper::GetAmount() const
{
	return this->Amount;
}

const int Newspaper::GetPeriod() const
{
	return this->Period;
}

const int Newspaper::GetPageHeight() const
{
	return this->pageHeight;
}

const int Newspaper::GetPageWidth() const
{
	return this->pageWidth;
}

