#include "PrintedProducts.h"
#include <iostream>


PrintedProducts::PrintedProducts()
{
	this->AuthorName = " ";
	this->pages = 0;
	this->title = " ";
}

PrintedProducts::PrintedProducts(const PrintedProducts& obj)
{
	AuthorName = obj.AuthorName;
	title = obj.title;
	pages = obj.pages;
}

PrintedProducts::PrintedProducts(const std::string AuthorName, const std::string title, const int pages)
{
	if (pages < 0)
	{
		throw "Incorrect number of pages";
	}

	this->AuthorName = AuthorName;
	this->title = title;
	this->pages = pages;
}

PrintedProducts::~PrintedProducts() { }

const std::string PrintedProducts::GetAuthorName() const
{
	return this->AuthorName;
}


const std::string PrintedProducts::GetTitle() const
{
	return this->title;
}

const int PrintedProducts::GetPages() const
{
	return this->pages;
}

PrintedProducts& PrintedProducts::operator=(PrintedProducts obj)
{
	Swap(obj);
	return *this;
}

void PrintedProducts::Swap(PrintedProducts& obj)
{
	std::swap(pages,obj.pages);
	std::swap(title, obj.title);
	std::swap(AuthorName, obj.AuthorName);
}

