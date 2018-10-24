#include <iostream>;
#include <iomanip>;
#include <string>;
#include "PizzaHeader.h";
using namespace std;

/// Global Variables
Pizza arr[25];
string name;
string phone;
int quantity = 0;
int styleP = 0;
int sz = 0;
int SideNum = 25;
int sides[25];
int sdPrice = 0;
int sumTotal = 0;
int sau = 0;

/// Functions not used in Pizza Class
int Sides(int x);
int calcSidePrice(int y);
void disSides(int z);
int CalcPizzaPrice(int w);


int main()
{
	
	//// Start with name and phone #
	cout << endl;
	cout << endl;
	cout << "Hello! Before you select your pizza, what will the order name be?" << endl;
	getline(cin,name);
	cout << "Great! Now what is the phone number for the order?" << endl;
	getline(cin,phone);
	
	//// Display pricing and sizes first, then ask how many pizzas are going to be ordered 
	cout << endl;
	cout << "Here are the prices of pizza:" << endl;
	cout << "Small Pizza ($8)" << endl;
	cout << "Medium Pizza ($10)" << endl;
	cout << "Large Pizza ($12)" << endl;
	cout << "($2 per topping, no matter the size)" << endl;
	cout << endl;



	//////Enter number of pizzas here.

	cout << "How many pizzas will there be? (No more than 25)" << endl;

	cin >> quantity;
	while (quantity < 1 || quantity > 25)
	{
		cout << "Sorry that is an invalid number of pizzas, please enter again." << endl;
		cout << "(We require pizza orders to be somewhere between 1 and 25 pizzas)." << endl;
		cin >> quantity;
	}
	
	/// Put a loop here to go through every pizza

	
	for (int i = 0; i < quantity; i++)
	{
		//// Work through each pizza, determining size, style and what/how many toppings

		// SIZE
		cout << endl;
		cout << "For pizza #"<< i+1 << ", what size will it be?" << endl;
		cout << "(1 for small, 2 for medium, and 3 for large)" << endl;
		/// Enter Size Here
		cin >> sz;
		while (sz < 1 || sz > 3)
		{
			cout << "Sorry that is an invalid size choice, please enter again." << endl;
			cout << "Size: ";
			cin >> sz;
		}
		arr[i].PizzaSz(sz);


	
		/// STYLE
		cout << endl;
		cout << "And what style will it be?" << endl;
		cout << "1. Deep Dish" << endl;
		cout << "2. Thick Crust" << endl;
		cout << "3. Thin Crust" << endl;
		cout << "Enter style by corresponding number (1, 2, or 3)" << endl;
		// Enter Style Here
		
		cin >> styleP;
		while (styleP < 1 || styleP > 3)
		{
			cout << "Sorry that is an invalid style choice, please enter again." << endl;
			cout << "Style: ";
			cin >> styleP;
		}
		arr[i].PizzaSty(styleP);

		cout << endl;


		/// SAUCE
		cout << "We also have a nice selection of sauces, which one would you like for the pizza?" << endl;
		cout << "1. Red" << endl;
		cout << "2. BBQ" << endl;
		cout << "3. White" << endl;
		cout << "4. Basil Pesto" << endl;
		//ENTER SAUCE
		cin >> sau;
		while (sau < 1 || sau > 4)
		{
			cout << "Sorry, that is an invalid sauce choice, please enter again." << endl;
			cout << "Sauce: ";
			cin >> sau;

		}
		arr[i].PizzaSau(sau);


		/// TOPPINGS
		
		arr[i].PizzaTop(1);
		cout << endl;
	}

	Sides(1); //// Ask about the sides

//// Finish with receipt of entire order
// name and phone first, and then list the pizzas with all details of size, style, and all the toppings.
	
	cout << "------------------------------" << endl;
	cout << "            RECEIPT           " << endl;

	cout << name << " " << phone << endl;
	/// Loop below will display all the pizzas with each detail.
	for (int i = 0; i < quantity; i++)
	{
		
		cout << endl;
		cout << "Pizza #" << i + 1 << ": " << endl;
		arr[i].disPizzaSz(1);
		arr[i].disPizzaSty(1);
		arr[i].disPizzaSau(1);
		arr[i].disPizzaTop(1);
		cout << setw(15) << "$" << arr[i].priceperPizza(1);
		
		cout << endl;
	}
	
	//Another function to show the sides ordered 
	disSides(1);
	sdPrice = calcSidePrice(1);

	cout << endl;
	// And another function for the total price, to finish out the receipt. 
	sumTotal = CalcPizzaPrice(1);
	int Total = 0;
	Total = sumTotal + sdPrice;

	cout << "Total Price" << setw(10) << "$" << Total << endl;
	cout << "------------------------------" << endl;

	cout << endl;
	cout << "Thank you " << name << " for ordering from us! Each pizza takes about 5 minutes so your order will be ready" << endl;
	cout << "in about " << quantity * 5 << " minutes to pick up. Thanks again!" << endl;
	return 0;
}





int Sides(int x)
{

//// SIDES 
	cout << endl;
	cout << "We also have a wide selection of sides and dessert options to choose from to go along with your great pizza!" << endl;
	cout << "1. Buffalo Wings" << "    " << "6. Caesar Salad" << endl;
	cout << "2. BBQ Wings" << "        " << "7. French Fries" << endl;
	cout << "3. Garlic Bread" << "     " << "8. Pasta" << endl;
	cout << "4. Cheesy Bread" << "     " << "9. Dessert Pizza" << endl;
	cout << "5. Garden Salad" << "     " << "10. Cookie Platter" << endl;
	cout << "Each side is $4." << endl;
	cout << endl;
	cout << "So can we interest you in any sides with your order?" << endl;
	cout << "(Enter corresponding number(s). Enter 0 when done or if no sides are wanted. No more than 25 sides allowed.)" << endl;
	
	///// ENTER SIDE SELECTION HERE
	for (int i = 0; i < SideNum; i++)
	{
		sides[i] = 0;
	}
	int side;
	int h = 0;
	for (int h = 0; h < SideNum; h++)
	{
		cin >> side;
		if (side == 0)
			break;
		while (side < 0 || side > 10)
		{
			cout << "Sorry that is an invalid number for the sides, please enter again the desired side." << endl;
			cin >> side;
		}
		if (side == 0)
			break;
		sides[h] = side;
	}

	return sides[25];

}

int calcSidePrice(int y) 
{

	/////Total cost of Sides


	int sum = 0;
	for (int i = 0; i < SideNum; i++)
	{
		if (sides[i] != 0)
		{
			sum++;
		}
	}
	sdPrice = sum * 4;

	cout << setw(15) << "$" << sdPrice << endl;

	return sdPrice;
}


void disSides(int z) ///function to display the sides
{

	cout << "Sides: " << endl;
	if (sides[0] == 0)
		cout << "  None" << endl;
	for (int i = 0; i < 25; i++)
	{
		if (sides[i] == 1)
			cout << "  Buffalo Wings" << endl;
		else if (sides[i] == 2)
			cout << "  BBQ Wings" << endl;
		else if (sides[i] == 3)
			cout << "  Garlic Bread" << endl;
		else if (sides[i] == 4)
			cout << "  Cheesy Bread" << endl;
		else if (sides[i] == 5)
			cout << "  Garden Salad" << endl;
		else if (sides[i] == 6)
			cout << "  Caesar Salad" << endl;
		else if (sides[i] == 7)
			cout << "  French Fries" << endl;
		else if (sides[i] == 8)
			cout << "  Pasta" << endl;
		else if (sides[i] == 9)
			cout << "  Dessert Pizza" << endl;
		else if (sides[i] == 10)
			cout << "  Cookie Platter" << endl;

	}
}



int CalcPizzaPrice(int w) ///function to calculate the total price of the pizzas (but not the total of the order)
{

	for (int i = 0; i < quantity; i++)
	{

		sumTotal += arr[i].priceperPizza(1);

	}
	return sumTotal;
}