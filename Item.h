//declaration of class to support flipped items
#ifndef ITEM
	#define ITEM

#include <iostream>
#include <string>
using namespace std;

class Item
{
 public: //member functions
	//constructors
	Item(); //default constructor
	Item(string, int, int, int); //overloaded constructor to initialize Name, Buy, Sell, and Quantity
	
	//extractors
	string getName() const;
	int getProfit() const;
	
	//mutators
	void setProfit(int);
	
	//support for assignments and output to log file
	const Item& operator=(const Item&);
	friend ostream& operator<<(ostream&, const Item&);

 private: //data attributes
	string Name;
	int Buy, Sell, Quantity, Profit;
};

#endif //end of class
