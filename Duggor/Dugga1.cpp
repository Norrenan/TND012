#include <iomanip>		
#include <iostream>

using namespace std;


int main()
{
	//ints and doubles given at the beggining of the exercise
	int numb_trees = 0;
	double tree_height = 0.0;
	int extra = 0;

	//sizes of trees
	constexpr int  SMALL = 1;
	constexpr int  MEDIUM = 2;
	constexpr int  LARGE = 3;

	//prices for trees
	constexpr double PRIS1 = 50;
	constexpr double PRIS2 = 109;
	constexpr double PRIS3 = 199;
	constexpr double PRIS4 = 299.50;

	double price_trees = 0;
	double delivery = 0;
	double planting = 0;

	//to avoid magic numbers there were many variables made 
	constexpr double MAX_DELIVERY = 600;
	constexpr double DELIVERY_COST = 120;
	double price = 0;

	constexpr double DIVIDER = 0.5;

	//total cost
	double total = 0;

	//used to not repeat code
	bool invalid_input = false;

	//sets the max digits to 2 digits
	cout << fixed << setprecision(2);

	//user is asked to write some numbers for the program
	do
	{
		cout << "Number of trees purchased: ";
		cin >> numb_trees;

		cout << "Tree height: ";
		cin >> tree_height;

		cout << "Extra services (0 -> none, 1 -> delivery, 2 -> planting): ";
		cin >> extra;

		invalid_input = (numb_trees <= 0 || tree_height <= 0 || extra < 0 || extra >= 3); //used to not repeat code

		if (invalid_input)
		{
			cout << "Purchase information not valid!!" << endl;
		}

	} while (invalid_input);

	//calculation of prices for parts (trees and extra services)

	//price trees. "price = PRIS(number)" is meant to change the price on the invoice to the correct one.
	if (tree_height < SMALL)
	{
		price = PRIS1;
		price_trees = numb_trees * PRIS1;

	}
	else if (tree_height >= SMALL && tree_height < MEDIUM)
	{
		price = PRIS2;
		price_trees = numb_trees * PRIS2;
	}
	else if (tree_height >= MEDIUM && tree_height < LARGE)
	{
		price = PRIS3;
		price_trees = numb_trees * PRIS3;
	}
	else
	{
		price = PRIS4;
		price_trees = numb_trees * PRIS4;
	}

	//price for delivery or price for planting. 
	switch (extra)
	{
	case 1:
		delivery = numb_trees * DELIVERY_COST;
		if (delivery > MAX_DELIVERY)			//if max delivery becomes over the MAX (600) it will get reset to 600
		{
			delivery = MAX_DELIVERY;
		}
		break;
	case 2: planting = price_trees * DIVIDER;
		break;
	}

	//calculation of the total price that will be shown on the invoice.
	total = price_trees + delivery + planting;

	//displaying invoice with price and everything
	cout << "==============================" << endl;
	cout << "          Invoice             " << endl;
	cout << "==============================" << endl;


	cout << numb_trees << " trees * " << price << " each: " << price_trees << endl;
	cout << "Delivery charge: " << delivery << endl;
	cout << "Planting charge: " << planting << endl;
	cout << "................" << endl;
	cout << "Total amount due: " << total << endl;

	return 0;
}