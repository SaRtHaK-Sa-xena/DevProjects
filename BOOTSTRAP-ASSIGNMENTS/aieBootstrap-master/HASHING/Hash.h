#pragma once
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

class hashClass
{
public:
	hashClass();
	int Hash(string key);
	void AddItem(string name, string drink);
	int NumberOfItemsInIndex(int index);
	void PrintTable();
	void PrintItemsInIndex(int index);
	void FindDrink(string name);
	void RemoveItem(string name);

private:
	static const int tableSize = 4;

	struct item
	{
		string name;
		string favDrink;
		item* next;
	};

	item* HashTable[tableSize];
};