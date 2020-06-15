#include "Newspaper.h"
#include "PrintedProducts.h"


void Newspaper::Swap(Newspaper& obj)
{
	std::swap(Amount, obj.Amount);
	std::swap(pageHeight, obj.pageHeight);
	std::swap(pageWidth, obj.pageWidth);
	std::swap(Period, obj.Period);
}

const std::string Newspaper::NamePeriod() const
{

	return std::string();
}

Newspaper::Newspaper(): PrintedProducts()
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

Newspaper::Newspaper(const Newspaper& obj) : PrintedProducts(obj)
{
	pageHeight = obj.pageHeight;
	pageWidth = obj.pageWidth;
	Amount = obj.Amount;
	Period = obj.Period;
}



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

const long double Newspaper::GetNewspaperCost() const
{
	long double result = (pageWidth* pageHeight)*GetPages();
	result *= GetAmount();
	return result;
}

Newspaper& Newspaper::operator=(Newspaper obj)
{
	PrintedProducts::operator=(obj);
	Swap(obj);
	return *this;
}


std::ostream& operator<<(std::ostream& out, const Newspaper& product)   
{
	out
		<< "Title:" << "\t\t\t\t" << product.GetTitle() << std::endl
		<< "Author:" << "\t\t\t\t" << product.GetAuthorName() << std::endl
		<< "Pages:" << "\t\t\t\t" << product.GetPages() << std::endl
		<< "Page size:" << "\t\t\t" << product.GetPageWidth() << " x " << product.GetPageHeight()<< std::endl
		<< "Amount:" << "\t\t\t\t" << product.GetAmount() << std::endl
		<< "Period" << "\t\t\t\t" << product.GetPeriod() << std::endl
		<< "Paper consumption for one newspaper:  " << product.GetNewspaperCost() / product.GetAmount() << "  sq.m." << std::endl
		<< "Paper consumption for " << product.GetAmount() << " newspapers:   "
		<< product.GetNewspaperCost() << "  sq.m." << std::endl;

	return out;
}

