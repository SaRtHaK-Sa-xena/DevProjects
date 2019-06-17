// HASHING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Hash.h"

using namespace std;

int main()
{
	hashClass Hashy;
	hashClass Hashuse;
	string name = "";
	string book = "";
	int ID = 0;
	bool cont = true;
	char choice = '0';
	string options;

	while (cont)
	{	
		cout << "------(a)dd-------(r)emove-------(f)ind----(p)rint---(e)xit---" << endl;
		cin >> choice;

		switch (choice)
		{
		case'a':
			cout << "\t\t\t adding..." << endl;
			cout << "Enter Name: " << endl;
			cin >> name;
			cout << "Enter Favourite Book: " << endl;
			cin >> book;
			cout << "Enter Unique id: " << endl;
			cin >> ID;
			Hashuse.AddItem(name, book, ID);
			break;
		case'r':
			cout << "\t\t\t removing..." << endl;
			cout << "Find Person: " << endl;
			cin >> name;
			Hashuse.RemoveItem(name);
			break;


		case'f':
			cout << "\t\t\t Finding..." << endl;
			cout << "find (name) or (id)" << endl;
			cin >> options;
			if (options == "name")
			{
				cout << "Enter name to search: " << endl;
				cin >> name;
				cout << "Finding By Name..." << endl;
				Hashuse.FindBook(name);
				break;
			}
			else if (options == "id")
			{
				cout << "Enter name to search" << endl;
				cin >> name;
				cout << "Finding their unique id..." << endl;
				Hashuse.FindId(name);
				break;
			}
			else
			{
				cout << "\t\t\t Wrong input...\n \t\t\t try again later..." << endl;
				break;
			}
			break;


		case'p':
			cout << "\t\t\t Printing" << endl;
			Hashuse.PrintTable();
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


