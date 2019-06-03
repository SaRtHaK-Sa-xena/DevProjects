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

private:
	static const int tableSize = 10;

	struct item
	{
		string name;
		string favDrink;
		item* next;
	};

	item* HashTable[tableSize];
};