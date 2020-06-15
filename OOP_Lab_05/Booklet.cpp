#include "Booklet.h"
#include "PrintedProducts.h"

void Booklet::Print(std::ostream& out)
{
	out
		<< "Boolket table: " << std::endl
		<< "Title:" << "\t\t\t\t" << GetTitle() << std::endl
		<< "Author:" << "\t\t\t\t" << GetAuthorName() << std::endl
		<< "Pages:" << "\t\t\t\t" << GetPages() << std::endl
		<< "Page size:" << "\t\t\t" << GetPageWidth() << " x " << GetPageHeight() << std::endl
		<< "Amount:" << "\t\t\t\t" << GetAmount() << std::endl
		<< "Paper consumption:" << "\t\t" << GetPaperConsumption() << std::endl;
}

Booklet::Booklet() : PrintedProducts()
{
	this->Amount = 0;
	this->pageHeight = 0;
	this->pageWidth = 0;
}

Booklet::Booklet(
	const std::string AuthorName,
	const std::string title,
	int pages,
	const int pageHeight,
	const int pageWidth,
	const int Amount
) : PrintedProducts(AuthorName, title, pages)
{
	if (Amount < 0) {
		throw "wrong amount";
	}
	this->pageHeight = pageHeight;
	this->pageWidth = pageWidth;
	this->Amount = Amount;
}

Booklet::~Booklet() { }

const int Booklet::GetAmount() const
{
	return this->Amount;
}

const int Booklet::GetPageHeight() const
{
	return this->pageHeight;
}

const int Booklet::GetPageWidth() const
{
	return this->pageWidth;
}

const double Booklet::GetPaperConsumption()
{
	const double height = this->GetPageHeight();
	const double amount = this->GetAmount();
	const double width = this->GetPageWidth();
	const double result = (height * width) * amount;
	return result;
}

