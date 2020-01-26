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
		cout << "---(a)dd---(r)emove---(f)DisplaySpecificInfo---(u)pdate---(p)rint---(e)xit---" << endl;
		cout << "\n ---(s)Search---" << endl;
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
			while (cin.fail())
			{
				cout << "Error" << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cout << "Enter a number please: " << endl;
				cin >> ID;
			}
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
			cout << endl;
			cout << "===========================" << endl;
			cout << "Which Person's details would you like to update" << std::endl;
			cout << "Enter Person's name to Update: " << endl;
			cin >> name;

			cout << "Would you like to update the ID or the Book Name" << endl;
			cout << "Enter 'id' or 'book'" << endl;

			cin >> options;

			if (options == "id")
			{
				cout << "===========================" << endl;
				Hashuse.OverwriteId(name);
				cout << "===========================" << endl;
			}
			else if (options == "book")
			{
				cout << "===========================" << endl;
				Hashuse.OverwriteBook(name);
				cout << "===========================" << endl;
			}
			else
			{
				cout << "Incorrect input entered, please try again later" << endl;
			}
			break;
		case'e':
			return 0;

		case's':
			//Searches using ID or NAME
			cout << "\t\t\t Searching..." << endl;
			cout << "Do you want to search using ID or Book Name" << endl;
			cout << "===== Enter 'id' or 'book' =======" << endl;

			cin >> options;
			if (options == "book")
			{
				cout << "Enter Book Name To Use As Key" << endl;
				cin >> options;
				Hashuse.searchThroughName(options);
				break;
			}
			else if (options == "id")
			{
				cout << "Enter ID To Use As Key" << endl;
				cin >> ID;
				while (cin.fail())
				{
					cout << "Error" << endl;
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Enter a number please: " << endl;
					cin >> ID;
				}
				Hashuse.searchThroughID(ID);
				break;
			}
			else
			{
				cout << "\t\t\t Wrong input...\n \t\t\t try again later..." << endl;
				break;
			}

		default:
			cout << "Pick one of the options listed" << endl;
		}
	}
}


