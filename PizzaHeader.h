#pragma once
#include <iostream>;
#include <iomanip>;
using namespace std;

//// HEADER FILE
class Pizza
{
public:
	Pizza()               // default Constructor
	{
		size = 0;
		style = 0;
		topping[12] = 0;
		sum = 0;
		sauce = 0;

	}

	///no mutator functions were used in this project, for they were not needed.


	int PizzaSz(int sz); 				// Accessor functions
	int PizzaSty(int sty);
	int PizzaTop(int top);
	void disPizzaSty(int y);
	void disPizzaSz(int x);
	void disPizzaTop(int z);
	int priceperPizza(int p);
	int PizzaSau(int sau);
	void disPizzaSau(int q);

private:
	////Private class variables
	int size;
	int style;
	int topping[12];
	int sum; 
	int sauce;
};