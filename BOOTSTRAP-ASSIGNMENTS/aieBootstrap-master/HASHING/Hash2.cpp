#include "Hash2.h"
using namespace std;


void hashClass::AddItem(string name, string book, int id)
{
	int index = Hash(name);

	if (HashTable[index]->name == "empty")
	{
		HashTable[index]->name = name;
		HashTable[index]->favBookName = book;
		HashTable[index]->itemCode = id;
	}
	else
	{
		item* Ptr = HashTable[index];
		item* n = new item;
		n->name = name;
		n->favBookName = book;
		n->itemCode = id;
		n->next = NULL;
		while (Ptr->next != NULL)
		{
			Ptr = Ptr->next; //until last item in list
		}
		//now at last
		Ptr->next = n; //last item linked to first
	}
}


hashClass::hashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		HashTable[i] = new item;
		HashTable[i]->name = "empty";
		HashTable[i]->favBookName = "empty";
		HashTable[i]->itemCode = 0;
		HashTable[i]->next = NULL;
	}
}


int hashClass::NumberOfItemsInIndex(int index)
{
	int count = 0;
	//count until reaches NULL
	if (HashTable[index]->name == "empty")
	{
		return count; //if at End Of list return Count
	}
	else
	{
		count++; //if not count increments and Ptr Moves Forward
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}
	return count; //
}

void hashClass::PrintTable()
{
	int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i); //number will equal no. of items in List
		cout << "---------------------------\n";
		cout << "index = " << i << endl;
		cout << HashTable[i]->name << endl;
		cout << HashTable[i]->favBookName << endl;
		cout << "Unique Identifier: " << HashTable[i]->itemCode << endl;
		cout << "# of items = " << number << endl;
		cout << "---------------------------\n";


	}
}



void hashClass::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index];

	if (Ptr->name == "empty")
	{
		cout << "index = " << index << "is empty";
	}
	else
	{
		cout << "index " << index << " contains the following item\n";

		while (Ptr != NULL)
		{
			cout << "-------------------\n";
			cout << "Name: " << Ptr->name << endl;
			cout << "Book: " << Ptr->favBookName << endl;
			cout << "Unique ID: " << Ptr->itemCode << endl;
			cout << "-------------------\n";

			Ptr = Ptr->next;
		}
	}
}


void hashClass::FindBook(string name)
{
	int index = Hash(name);
	bool foundName = false;
	string book;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			book = Ptr->favBookName;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		cout << "Favorite Book = " << book << endl;
	}
	else
	{
		cout << name << "'s info wasn't found in the Hash table\n";
	}
}

void hashClass::OverwriteBook(string name)
{
	int index = Hash(name);
	bool foundName = false;
	string book;
	string newBook;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			book = Ptr->favBookName;
			cout << "Enter New Book Title: " << endl;
			cin >> newBook;
			book = newBook;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		cout << "Favorite Book = " << book << endl;
	}
	else
	{
		cout << name << "'s info wasn't found in the Hash table\n";
	}
}

void hashClass::FindID(string name)
{
	int index = Hash(name);
	bool foundName = false;
	int id_no;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		if (Ptr->name == name)
		{
			foundName = true;
			id_no = Ptr->itemCode;
		}
		Ptr = Ptr->next;
	}
	if (foundName == true)
	{
		cout << name << "'s Unique Identifier = " << id_no << endl;
	}
	else
	{
		cout << name << "'s info wasn't found in the Hash table\n";
	}
}




void hashClass::RemoveItem(string name)
{
	int index = Hash(name); //hashes name and makes that number equal index

	item* delPtr;
	item* P1;
	item* P2;

	//if bucket is empty
	if (HashTable[index]->name == "empty" && HashTable[index]->favBookName == "empty")
	{
		cout << name << " was not found in the Hash Table\n";
	}

	
	//if only 1 item contained in bucket and that item has matching name
	else if (HashTable[index]->name == name && HashTable[index]->next == NULL)//only one item in index 
	{
		HashTable[index]->name = "empty"; //set to empty
		HashTable[index]->favBookName = "empty"; //set to empty
		HashTable[index]->itemCode = 0;
		cout << name << " was removed from the Hash Table\n";

	}

	//if additional items are contained in index
	//if match is located in the first item in the bucket but there are more items in the bucket
	else if (HashTable[index]->name == name)
	{
		delPtr = HashTable[index]; //pointer poiting to first item to delete in index
		HashTable[index] = HashTable[index]->next; //points to the new first item
		delete delPtr;

		cout << name << " was removed from the Hash Table\n";
	}


	//if bucket contains items but first item is not a match
	else
	{
		P1 = HashTable[index]->next; //pointing to second item
		P2 = HashTable[index];//p2 trailing behind p1

		while (P1 != NULL && P1->name != name) //as long as pointer pointing at value and name not equal to name
		{
			//move up one item
			P2 = P1;
			P1 = P1->next;
		}
		//case 3,1 - no match
		if (P1 == NULL)
		{
			cout << name << " was not found in the Hash Table\n";
		}
		else
		{
			delPtr = P1; //to rremce
			P1 = P1->next; //very next poiinter
			P2->next = P1; //since the pointer previously pointed at P1 which is being deleted, P1 now points next, and P2 points to the new P1's next

			delete delPtr;
			cout << name << " was removed from the Hash Table\n";
		}


	}
	
}




int hashClass::Hash(string key)
{
	int hash = 0;
	int index;

	

	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * 17;
	}

	index = hash % tableSize;

	return index;
}
