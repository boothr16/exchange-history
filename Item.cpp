// support functions for logging statistics on item flips
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

Item::Item() //default constructor
{
	Name = " ";
	Buy = Sell = Quantity = Profit = 0;
}

Item::Item(string n, int b, int s, int q) //overloaded constructor
{
	Name = n;
	Buy = b;
	Sell = s;
	Quantity = q;
	Profit = 0;
}

string Item::getName() const
{
	return Name;
}

int Item::getProfit() const
{
	return Profit;
}

void Item::setProfit(int p)
{
	Profit = p;
}

// support for assignments
const Item& Item::operator=(const Item& i)
{
	// bypass self assignment
	if (this != &i)
	{
		Name = i.Name;
		Buy = i.Buy;
		Sell = i.Sell;
		Quantity = i.Quantity;
		Profit = i.Profit;
	}
	return *this;
}

// support for output to log file 
ostream& operator<<(ostream& out, const Item& i)
{
	out << setw(20) << i.Name << "\t"
		<< setw(20) << i.Profit << "\t";
	return out;
}

// end of the class member functions
