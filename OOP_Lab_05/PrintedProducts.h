#pragma once
#include <iostream>

class PrintedProducts
{
private:
	std::string AuthorName;
	std::string title;
	int pages;
protected:
	virtual void Print(std::ostream& out) = 0 ; 
public:
	PrintedProducts();
	PrintedProducts(const std::string AuthorName, const std::string title, const int pages);
	virtual ~PrintedProducts();

	PrintedProducts(const PrintedProducts& obj);

	const std::string GetAuthorName() const;
	const std::string GetTitle() const;
	const int GetPages() const;

	virtual const double GetPaperConsumption() = 0;
	friend std::ostream& operator<<(std::ostream& out,  PrintedProducts& v);
};

