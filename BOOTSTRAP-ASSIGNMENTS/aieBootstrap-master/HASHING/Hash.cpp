#include "Hash.h"
using namespace std;


void hashClass::AddItem(string name, string drink)
{
	int index = Hash(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->favDrink = drink;
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
	}
}


hashClass::hashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->favDrink = "empty";
		HashTable[i]->next = NULL;
	}
}


int hashClass::Hash(string key)
{
	int hash = 0;
	int index;

	

	for (int i = 0; i < key.length(); i++)
	{
		hash = hash + (int)key[i];
		cout << "hash = " << hash << endl;
	}

	index = hash % tableSize;

	return index;
}
