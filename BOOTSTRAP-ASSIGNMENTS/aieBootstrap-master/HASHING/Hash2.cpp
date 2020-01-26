#include "Hash2.h"
#include <time.h>
using namespace std;


void hashClass::AddItem(char name[50], char book[50], int id)
{
	//for easier reference
	char empty[10] = { 'e','m','p','t','y' };

	int index = Hash(name);

	//finds index then checks if it's empty
	if (HashTable[index]->name == empty) 
	{
		//then sets its name, book, item code to user input
		HashTable[index]->name = name;
		HashTable[index]->favBookName = book;
		HashTable[index]->itemCode = id;
	}
	else
	{
		item* Ptr = HashTable[index]; // at beginning 
		item* n = new item; //make n new item
		n->name = name; //create n to store name
		n->favBookName = book; //store book
		n->itemCode = id; // store id
		n->next = NULL; //then make the next null
		while (Ptr->next != NULL) //then check while ptr->next not equal to null
		{
			//iterate until last itme
			Ptr = Ptr->next; 
		}
		//now at last
		//make the next item of Ptr->next = n
		Ptr->next = n;
		//Now the n is at the end of List
	}
}


hashClass::hashClass()
{
	// creates an empty hash table
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
	return count; //the amount of items
}


void hashClass::PrintTable()
{
	//Previous:
	//============================================================================
	int number;
	//for (int i = 0; i < tableSize; i++)
	//{
	//	number = NumberOfItemsInIndex(i); //number will equal no. of items in List
	//	cout << "---------------------------\n";
	//	cout << "index = " << i << endl;
	//	cout << "Name: " << HashTable[i]->name << endl;
	//	cout << "Favourite Book Name: " << HashTable[i]->favBookName << endl;
	//	cout << "Unique Identifier: " << HashTable[i]->itemCode << endl;
	//	cout << "# of items = " << number << endl;
	//	cout << "---------------------------\n";
	//	

	//	item* Ptr = HashTable[i]; //makes the Ptr set to hashtable[index]
	//	cout << "index " << i << " contains the following item\n";

	//	// while that ptr is not null
	//	while (Ptr != NULL)
	//	{
	//		cout << "-------------------\n";
	//		cout << "Name: " << Ptr->name << endl;
	//		cout << "Book: " << Ptr->favBookName << endl;
	//		cout << "Unique ID: " << Ptr->itemCode << endl;
	//		cout << "-------------------\n";

	//		Ptr = Ptr->next;
	//	}
	//}
	//============================================================================


	//New Attempt:
	//============================================================================
	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i); //number will equal no. of items in List
		//displaying all data in all index
		cout << "Displaying Items In Index: " << i << endl;
		cout << "---------------------------\n";
		cout << "index = " << i << endl;
		cout << "Name: " << HashTable[i]->name << endl;
		cout << "Favourite Book Name: " << HashTable[i]->favBookName << endl;
		cout << "Unique Identifier: " << HashTable[i]->itemCode << endl;
		cout << "# of items = " << number << endl;
		if (number != 0)
		{
			PrintItemsInIndex(i);
		}
		cout << "---------------------------\n";
	}
}

//uses the id as key to display details
void hashClass::searchThroughID(int unique_id)
{
	bool keepSearching = true;
	int number = 0;
	
	if (keepSearching)
	{
		for (int i = 0; i < tableSize; i++)
		{
			number = NumberOfItemsInIndex(i);

			//look for items
			item *Ptr = HashTable[i];

			for (int j = 0; j < number; j++)
			{
				if(Ptr->itemCode == unique_id)
				{
					cout << "-------------------\n";
					cout << "Name: " << Ptr->name << endl;
					cout << "Book: " << Ptr->favBookName << endl;
					cout << "Unique ID: " << Ptr->itemCode << endl;
					cout << "-------------------\n";
				}
				Ptr = Ptr->next;
			}
		}
	}
}

//uses the book name as key to display details
void hashClass::searchThroughName(string book_Name)
{
	bool keepSearching = true;
	int number = 0;

	if (keepSearching)
	{
		for (int i = 0; i < tableSize; i++)
		{
			number = NumberOfItemsInIndex(i);

			//look for items
			item *Ptr = HashTable[i];

			for (int j = 0; j < number; j++)
			{
				if (Ptr->favBookName == book_Name)
				{
					cout << "-------------------\n";
					cout << "Name: " << Ptr->name << endl;
					cout << "Book: " << Ptr->favBookName << endl;
					cout << "Unique ID: " << Ptr->itemCode << endl;
					cout << "-------------------\n";
				}
				Ptr = Ptr->next;
			}
		}
	}
}

void hashClass::PrintItemsInIndex(int index)
{
	item* Ptr = HashTable[index]; //makes the Ptr set to hashtable[index]

	//if that ptr is empty then return it is empty
	if (Ptr->name == "empty")
	{
		cout << "index = " << index << "is empty";
	}
	else
	{
		//if not empty return that index
		cout << "index " << index << " contains the following item\n";

		// while that ptr is not null
		while (Ptr != NULL)
		{
			cout << "-------------------\n";
			cout << "Name: " << Ptr->name << endl;
			cout << "Book: " << Ptr->favBookName << endl;
			cout << "Unique ID: " << Ptr->itemCode << endl;
			cout << "-------------------\n";

			Ptr = Ptr->next;
		}
		//until all contents of that index have been printed
	}
}


void hashClass::FindBook(string name)
{
	//int index = Hash(name)
	int index = Hash(name);
	bool foundName = false;
	string book;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		//if name found display its' book
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
	string book;
	int number = 0;

		for (int i = 0; i < tableSize; i++)
		{
			number = NumberOfItemsInIndex(i);

			//look for items
			item *Ptr = HashTable[i];

			for (int j = 0; j < number; j++)
			{
				if (Ptr->name == name)
				{
					cout << "-----------PREVIOUS DATA--------\n";
					cout << "Name: " << Ptr->name << endl;
					cout << "Book: " << Ptr->favBookName << endl;
					cout << "Unique ID: " << Ptr->itemCode << endl;
					cout << "-----------PREVIOUS DATA--------\n";

					cout << "Enter New Book Title: " << endl;
					cin >> book;
					Ptr->favBookName = book;
				}
				Ptr = Ptr->next;
			}
		}
}

void hashClass::OverwriteId(string name)
{
	int newID;
	int number = 0;

	for (int i = 0; i < tableSize; i++)
	{
		number = NumberOfItemsInIndex(i);

		//look for items
		item *Ptr = HashTable[i];

		for (int j = 0; j < number; j++)
		{
			if (Ptr->name == name)
			{
				cout << "-----------PREVIOUS DATA--------\n";
				cout << "Name: " << Ptr->name << endl;
				cout << "Book: " << Ptr->favBookName << endl;
				cout << "Unique ID: " << Ptr->itemCode << endl;
				cout << "-----------PREVIOUS DATA--------\n";

				cout << "Enter New Unique ID: " << endl;
				cin >> newID;
				Ptr->itemCode = newID;
			}
			Ptr = Ptr->next;
		}
	}
}

void hashClass::FindID(string name)
{
	//sets Index to that hash element
	int index = Hash(name);
	bool foundName = false;
	int id_no;

	item* Ptr = HashTable[index];
	while (Ptr != NULL)
	{
		//if name found displays its ID
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

	srand(time(NULL));

	int randomAmount = 1 + rand() % 10;

	const int amount = 50;

	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash + (int)key[i]) * amount; //17 is random value that might be causing the problem
	}

	index = hash % tableSize; //index returned is the remainder between hash divided by table size

	//makes sure hash is not a negative number
	while (index < 0)
	{
		index = randomAmount + index;
	}

	return index; //returned index
}
