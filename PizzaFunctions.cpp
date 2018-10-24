#include "PizzaHeader.h";

///Implementation file


// Accessor functions
int Pizza::PizzaSz(int sz) ///function to determine size/price of pizza.
{   
	
	if (sz == 1)
	{
	size = 8;
	}
		
	else if (sz == 2)
	{
	size = 10;
	}
		
	else if (sz == 3)
	{
	size  = 12;
	}
		
	return size;
}				
int Pizza::PizzaSty(int sty) ///funciton to determine the style of pizza.
{ 
	style = sty;
	
	return style; 
}
int Pizza::PizzaSau(int sau) ///function to determine the sauce of the pizza.
{
	sauce = sau;
	return sauce;
}
int Pizza::PizzaTop(int top) ///function to determine the desired toppings of each pizza.
{ 

	///TOPPINGS
	cout << endl;
	cout << "Now for the toppings:" << endl;
	cout << "1. Ham" << "            " << "7. Jalapenos" << endl;
	cout << "2. Bacon" << "          " << "8. Sun Dried Tomatoes" << endl;
	cout << "3. Pineapple" << "      " << "9. Chicken" << endl;
	cout << "4. Sausage" << "        " << "10. Spinach" << endl;
	cout << "5. Pepperoni" << "      " << "11. Olives" << endl;
	cout << "6. Extra Cheese" << "   " << "12. Mushrooms" << endl;
	cout << endl;
	cout << "Which topping(s) would you like? After each topping is selected, press Enter before entering in the next topping." << endl;
	cout << "(Enter 0 when finished selecting toppings, up to 12 toppings allowed, and duplicates are ok.)" << endl;
	//// ENTER IN TOPPINGS HERE
	int TopArrSz = 12;
	for (int i = 0; i < TopArrSz; i++)
	{
		topping[i] = 0;
	}
	int tops;
	int m = 0;
	for (int m = 0; m < TopArrSz; m++)
	{
		cin >> tops;
		if (tops == 0)
			break;
		while (tops < 0 || tops > 12)
		{
			cout << "Sorry that is an invalid number for the toppings, please enter again the desired topping." << endl;
			cin >> tops;
		}
		if (tops == 0)
			break;
		topping[m] = tops;
	}

	return topping[12]; 
}

///Need to create void functions that will display what has been entered in the above orders for each pizza
void Pizza::disPizzaSz(int x) ///display the size on the reciept. 
{
	if (size == 8)
		cout << "Size: Small" << endl;
	else if (size == 10)
		cout << "Size: Medium" << endl;
	else if (size == 12)
		cout << "Size: Large" << endl;

}

void Pizza::disPizzaSty(int y) ///display the style of pizza on the reciept.
{
	if (style == 1)
		cout << "Style: Deep Dish" << endl;
	else if (style == 2)
		cout << "Style: Thick Crust" << endl;
	else if (style == 3)
		cout << "Style: Thin Crust" << endl;
}
void Pizza::disPizzaSau(int q) ///display the selected sauce of the pizza on the reciept.
{
	if (sauce == 1)
		cout << "Sauce: Red" << endl;
	else if (sauce == 2)
		cout << "Sauce: BBQ" << endl;
	else if (sauce == 3)
		cout << "Sauce: White" << endl;
	else if (sauce == 4)
		cout << "Sauce: Basil Pesto" << endl;

}

void Pizza::disPizzaTop(int z) /// displaying all the toppings order for each pizza on the reciept.
{
	cout << "Toppings:" << endl;
		if (topping[0] == 0)
			cout << "  None" << endl;
	for (int i = 0; i < 12; i++)
	{
		
		if (topping[i] == 1)
			cout << "  Ham" << endl;
		else if (topping[i] == 2)
			cout << "  Bacon" << endl;
		else if (topping[i] == 3)
			cout << "  Pineapple" << endl;
		else if (topping[i] == 4)
			cout << "  Sausage" << endl;
		else if (topping[i] == 5)
			cout << "  Pepperoni" << endl;
		else if (topping[i] == 6)
			cout << "  Extra Cheese" << endl;
		else if (topping[i] == 7)
			cout << "  Jalapenos" << endl;
		else if (topping[i] == 8)
			cout << "  Sun Dried Tomatoes" << endl;
		else if (topping[i] == 9)
			cout << "  Chicken" << endl;
		else if (topping[i] == 10)
			cout << "  Spinach" << endl;
		else if (topping[i] == 11)
			cout << "  Olives" << endl;
		else if (topping[i] == 12)
			cout << "  Mushroom" << endl;
	}

}

int Pizza::priceperPizza(int p) // Calculating the total price of each pizza.
{

	int sumtop = 0;

	for (int i = 0; i < 12; i++)
	{
		if (topping[i] != 0)
			sumtop += 2;
	}
	sum = size + sumtop;

	return sum;
}