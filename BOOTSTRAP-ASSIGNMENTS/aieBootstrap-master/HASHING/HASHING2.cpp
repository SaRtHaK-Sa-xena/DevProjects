// HASHING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Hash2.h"

#include <string>
using namespace std;

int main()
{
	
	hashClass Hashuse;
	char name[50];
	char book[50];
	int ID = 0;
	bool cont = true;
	char choice = '0';
	string options;



	while (cont)
	{	
		cout << "---(a)dd---(r)emove---(f)ind---(u)pdate---(p)rint---(e)xit---" << endl;
		cin >> choice;

		switch (choice)
		{
		case'a':
			//Adds a new ITEM to HASH TABLE
			cout << "\t\t\t adding..." << endl;
			cout << "Enter Name: " << endl;
			cin.ignore(1);
			cin.getline(name, 50);
			cout << "Enter Favourite Book: " << endl;
			cin.getline(book,50);
			cout << "Enter Unique id: " << endl;
			cin >> ID;
			Hashuse.AddItem(name, book, ID);
			break;
		case'r':
			//Removes the intended NAME and its CONTENTS
			cout << "\t\t\t removing..." << endl;
			cout << "Find Person: " << endl;
			cin >> name;
			Hashuse.RemoveItem(name);
			break;


		case'f':
			//Finds either ID or BOOK depending on name
			cout << "\t\t\t Finding..." << endl;
			cout << "find (book) or (id)" << endl;
			cin >> options;
			if (options == "book")
			{
				cout << "Enter Person's name to search: " << endl;
				cin >> name;
				cout << "Finding Book Name..." << endl;
				cout << endl;
				cout << "===========================" << endl;
				Hashuse.FindBook(name);
				cout << "===========================" << endl;
				break;
			}
			else if (options == "id")
			{
				cout << "Enter Person's name to search" << endl;
				cin >> name;
				cout << "Finding ID..." << endl;
				cout << endl;
				cout << "===========================" << endl;
				Hashuse.FindID(name);
				cout << "===========================" << endl;
				break;
			}
			else
			{
				cout << "\t\t\t Wrong input...\n \t\t\t try again later..." << endl;
				break;
			}
			break;


		case'p':
			//Prints Table
			cout << "\t\t\t Printing..." << endl;
			Hashuse.PrintTable();
			break;

		case'u':
			//Updates Book Title
			cout << "\t\t\t Updating..." << endl;
			cout << "Updating Book Name.." << endl;
			cout << endl;
			cout << "===========================" << endl;
			cout << "Which Person's book would you like to update" << std::endl;
			cout << "Enter Person's name to Update: " << endl;
			cin >> name;
			Hashuse.OverwriteBook(name);
			cout << "===========================" << endl;
			break;
		case'e':
			return 0;
		default:
			cout << "Pick one of the options listed" << endl;
		}
	}

	//===============
	/*while (name != "exit")
	{
		cout << "Remove ";
		cin >> name;
		if (name != "exit")
		{
			Hashy.RemoveItem(name);
		}
	}*/
	//================
	//Hashy.PrintItemsInIndex(2);

	//Hashy.PrintItemsInIndex(8);
	//Hashy

	/*int index;
	hashClass hashObject;
	index = hashObject.Hash("Paula");
	cout << "Index = " << index << endl;*/
}


