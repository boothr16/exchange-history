# exchange-history
A program that tracks history, performance, and sorts results from OSRS trades

This program requires the files RsFlipStats.cpp, Item.h, and Item.cpp to run successfully. A running log of items, buy prices, sell prices, and quantities are kept in a text file. The program will iterate through this input file and calculate the net profit from each item. After EOF is reached, items are sorted via the selection sort algorithm by most profitable, and a grand total profit is displayed. flipStatLog.txt is a sample output file.
