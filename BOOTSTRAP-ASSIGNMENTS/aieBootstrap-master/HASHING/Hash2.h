#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class hashClass
{
public:
	hashClass();

	int Hash(string key); //location to find

	void AddItem(string name, string book, int ID); //items to be added

	int NumberOfItemsInIndex(int index); // for displaying items

	void PrintTable(); //displays entire list

	void PrintItemsInIndex(int index); // displays in index

	void FindBook(string name); // finds by name--> displays book
	void OverwriteBook(string name); // finds by name--> edits book

	void FindID(string name); // finds by name--> displays ID


	void RemoveItem(string name); // removes key, therefore removing the index's values

private:
	static const int tableSize = 10;

	struct item
	{
		string name;
		string favBookName;
		int itemCode;
		item* next;
	};

	item* HashTable[tableSize];
};