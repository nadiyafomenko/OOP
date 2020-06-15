#pragma once
#include <iostream>

class PrintedProducts
{
private:
	std::string AuthorName;
	std::string title;
	int pages;
	void Swap(PrintedProducts& obj);
public:
	PrintedProducts();
	PrintedProducts(const PrintedProducts& obj);
	PrintedProducts(const std::string AuthorName, const std::string title, const int pages);
	~PrintedProducts();

	const std::string GetAuthorName() const;
	const std::string GetTitle() const;
	const int GetPages() const;

	PrintedProducts& operator = (PrintedProducts obj);
	
};

