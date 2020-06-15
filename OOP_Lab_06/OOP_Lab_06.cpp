#include <iostream>
#include "Stack.hpp"

#define MAX 5

void IntegerStack();
void DoubleStack();
void CharStack();

int main()
{
	int option = 0;
	std::cout << "Choose Stack type:\n" <<
		"1. Integer\n" <<
		"2. Double\n" <<
		"3. Char\n" << std::endl;
	std::cin >> option;
	try {
		switch (option) {
			case 1: {
				IntegerStack();
				break;
			}
			case 2: {
				DoubleStack();
				break;
			}
			case 3: {
				CharStack();
				break;
			}
			default: {
				throw "Invalid type. Try again";
			}
		}
	}
	catch (const char* msg)
	{
		std::cerr << msg << std::endl;
	}
}

void IntegerStack() {

	Stack<int>* stack = new Stack<int>();

	int item = 15;

	for (int i = 0; i < MAX; i++) {
		item += 3;
		stack->Push(item);
		int size = stack->Size();
		cout << "Push: " << item << " (size = " << size << ")" << endl;
	}
	for (int i = 0; i < 2; i++) {
		item = stack->Pop();
		int size = stack->Size();
		cout << "Pop: " << item << " (size = " << size << ")" << endl;
	}
	delete stack;
}

void DoubleStack() {

	Stack<double>* stack = new Stack<double>();

	double item = 17.4563;

	for (int i = 0; i < MAX; i++) {
		item += 3.1001;
		stack->Push(item);
		int size = stack->Size();
		cout << "Push: " << item << " (size = " << size << ")" << endl;
	}

	for (int i = 0; i < 2; i++) {
		item = stack->Pop();
		int size = stack->Size();
		cout << "Pop: " << item << " (size = " << size << ")" << endl;
	}
	delete stack;
}

void CharStack() {

	Stack<char>* stack = new Stack<char>();

	char item = 'a';

	for (int i = 0; i < MAX; i++) {
		item += 1;
		stack->Push(item);
		int size = stack->Size();
		cout << "Push: " << item << " (size = " << size << ")" << endl;
	}

	for (int i = 0; i < 2; i++) {
		item = stack->Pop();
		int size = stack->Size();
		cout << "Pop: " << item << " (size = " << size << ")" << endl;
	}

	delete stack;
}