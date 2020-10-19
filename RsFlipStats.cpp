//for file I/O
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Item.h"

//declaration of functions
int findItem(Item[], string, int);
int calcProfit(int, int, int); //(try to move this function to Item.cpp!)
void swap(Item, Item);
void selectionSort(Item[], int);
//void quickSort(Item[], int, int); (try to use this instead of selectionSort! function definition commented out at bottom of file)

//implementation of main program
int main()
{
	// 1. Connect to I/O files
	ifstream fin("flips.txt");
	ofstream fout("flipStatLog.txt");

	//objects used to store data
	const int LIST_LENGTH = 100;
	string name;
	int buyprice, sellprice, quant, profit, index = 0;
	int numItems = 0;
	int grandTotal = 0;

	// 2. Output descriptive message
	fout << "This program tracks the statistics on "
		 << "flipped items \nand sorts the items by most profitable.\n";

	// 3. Declare array of LIST_LENGTH Items
	Item list[LIST_LENGTH];

	// 4. Read data for first Item in input file
	fin >> name >> buyprice >> sellprice >> quant;

	// 5. Begin EOF-controlled while loop
	while (!fin.eof())
	{
		// 6. Check if the item is in the list of logged items already by finding the item's index
		index = findItem(list, name, numItems);

		// 7. If the items is NOT in the list
		if (index == -1)
		{
			Item it(name, buyprice, sellprice, quant); //parameterized constructor sets all attributes from raw input
			profit = calcProfit(buyprice, sellprice, quant);
			it.setProfit(profit); //updates item's profit
			list[numItems] = it; //adds new item to list with all associated attributes
			numItems += 1;
		} 

		// 8. Else item name already in list
		else
		{
			list[index].setProfit(calcProfit(buyprice, sellprice, quant) + list[index].getProfit()); //add to item's running profit
		}

		// 9. Read next line from input file
		fin >> name >> buyprice >> sellprice >> quant;
	} //end while


	// 10. SORT LIST IN ORDER OF ITEMS' PROFIT
	selectionSort(list, numItems);

	// 11. Display items and associated total profit
	fout << "\n\nItem\t\t    Profit\n"
		<< "----------\t    -------\n";
	for (int i = 0; i < numItems; i++)
	{
		grandTotal += list[i].getProfit();
		fout << left << setw(20) << list[i].getName() << setw(20) << list[i].getProfit() << endl;
	}

	fout << "\nGrand total: " << grandTotal;


	// 12. Disconnect from I/O files
	fin.close();
	fout.close();
} //end main

//findItem function checks list of logged Items for index of current item. Returns -1 if the item is not in the list already, and if it is, returns the item's index
int findItem(Item list[], string Name, int numberOfItems)
{
	// 1. Assume that the item is NOT in the list
	int Save = -1; //placeholder variable

	// 2. Loop over the list length
	for (int i = 0; i < numberOfItems; i++)
	{
		if (list[i].getName() == Name)
		{
			Save = i;
			break;
		}
	}
	return Save;
}

//calcProfit function takes the buy price, sell price, and amount traded as inputs and returns the total gain/loss
int calcProfit(int b, int s, int q)
{
	int Profit = (s - b) * q;
	return Profit;
}

//swap function swaps the positions of two items in an array
void swap(Item *a, Item *b)
{
	Item temp = *a;
	*a = *b;
	*b = temp;
}

//selectionSort function uses the selection sort algorithm to sort the items in the array by their Profit values (selectionSort is called after total profits for each item are determined)
void selectionSort(Item list[], int numberOfItems)
{
	int smallestIndex; //placeholder variable

	//loop over Index from 0 to (list size - 1)
	for (int Index = 0; Index < (numberOfItems - 1); Index++)
	{
		//assume item is position 0 has the smallest Profit value
		smallestIndex = Index;
		for (int minIndex = Index + 1; minIndex < numberOfItems; minIndex++) //minIndex starts and ends at one position to the right of Index
		{
			//if next item's Profit is less than the current item's Profit, set next element to smallest index
			if (list[minIndex].getProfit() < list[smallestIndex].getProfit())
				smallestIndex = minIndex;
		}
		//swap smallest element into place
		if (Index != smallestIndex)
			swap(&list[Index], &list[smallestIndex]);
	}
}


//quickSort function uses the quick-sort algorithm to sort the items in an array by their Profit values (quickSort is called after total profits from each item are determined)
/*void quickSort(Item list[], int leftIndex, int numberOfItems)  //left index starts at 0
{
	int rightIndex = numberOfItems - 1; //right index starts at (array size - 1)

	if (leftIndex >= rightIndex) //no need to sort arrays of size 0 or 1
		return;

	int pivot = list[rightIndex].getProfit(); //choose pivot to be last element in subarray's profit value

	int cnt = leftIndex; //index indicating the split between elements smaler than pivot and elements greater than pivot

	for (int i = leftIndex; i <= rightIndex; i++)
	{
		if (list[i].getProfit() <= pivot) //if the current element's profit is less than or equal to pivot...
		{
			swap(&list[cnt], &list[i]); //...then swap the two items so that the smaller profit is to the left of all elements greater than pivot
			cnt++;
		}
	}
	quickSort(list, leftIndex, cnt - 2); //recursively sort the left side of pivot
	quickSort(list, cnt, rightIndex); //recursively sort the right side of pivot
}*/

