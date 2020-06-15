#include <iostream>
#include <string>
#include "StackIterator.h"
#include "Stack.hpp"

int main()  {
	
	try {
		Stack<std::string>* q = new Stack<std::string>();

		q->Push("first");
		q->Push("second");
		q->Push("third");
		q->Push("fourth");
		q->Push("fifth");
		q->Push("sixth");

		StackIterator<std::string> iter = q->Iterator();

		std::cout << "Test Iterator" << std::endl;
		std::cout << "Printing elements in stack order (first in - first out):" << std::endl;

		while (iter.hasNext())
		{
			std::cout << iter.getNext() << std::endl;
		}

		delete q;
		std::cout << "Stack deleted" << std::endl;
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
	
}
