// HASHING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Hash.h"

using namespace std;

int main()
{
	hashClass Hashy;
	string name = "";


	Hashy.AddItem("Paul", "Locha");
	Hashy.AddItem("Kim", "Iced Mocha");
	Hashy.AddItem("Emma", "Strawberry Smoothy");
	Hashy.AddItem("Annie", "Hot Chocolate");
	Hashy.AddItem("Sarah", "Passion Tea");
	Hashy.AddItem("Pepper", "Caramel Mocha");
	Hashy.AddItem("Mike", "Chai Tea");
	Hashy.AddItem("Steve", "Apple Cider");
	Hashy.AddItem("Bill", "Root Beer");
	Hashy.AddItem("Marie", "Skinny Latte");
	Hashy.AddItem("Susan", "Water");
	Hashy.AddItem("Joe", "Green Tea");

	Hashy.PrintItemsInIndex(2);

	while (name != "exit")
	{
		cout << "Remove ";
		cin >> name;
		if (name != "exit")
		{
			Hashy.RemoveItem(name);
		}
	}

	Hashy.PrintItemsInIndex(2);

	//Hashy.PrintItemsInIndex(8);
	//Hashy

	/*int index;
	hashClass hashObject;
	index = hashObject.Hash("Paula");
	cout << "Index = " << index << endl;*/
}


