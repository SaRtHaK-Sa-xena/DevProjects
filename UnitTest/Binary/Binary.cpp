// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include "BitfieldOperators.h"

using namespace std;

const char BinaryData = 11011;

const char CHAINSAW = 0x01;
const char PISTOL = 0x01 << 1;
const char SHOTGUN = 0x01 << 2;
const char SUPER_SHOTGUN = 0x01 << 3;
const char CHAINGUN = 0x01 << 4;
const char ROCKET_LAUNCHER = 0x01 << 5;
const char PLASMA_GUN = 0x01 << 6;
const char BFG9000 = 0x01 << 7;

const int WEAPONS_COUNT = 9;

const char* weapons[] = { "Fists","Chainsaw", "Pistol", "Shotgun", "Super Shotgun", "Chaingun", "Rocket Launcher", "Plasma Gun", "BFG 9000" };

void printInventoy(char inventory);
void addToInventory(char& inventory, char weapon);

int main()
{
	srand(time(NULL));
	char inventory = 0;
	char choice = '0';
	string variable;
	bool cont = true;
	char weapon[20];
	char weapon2;

	int bitArray[50];
	int bitNo;
	int Decimal;
	int temp;

	weapons[rand() % 10];

	while (cont)
	{
		cout << "(a)dd----(d)isplay--(b)itfield_Example----" << endl;
		cin >> choice;
		switch (choice)
		{
		    case'a':
		    	cout << "\t\t\t adding..." << endl;
		    	cout << "Enter Gun Name: " << endl;
		    	
				cin >> variable;
				if (variable == "Chainsaw")
				{
					addToInventory(inventory, CHAINSAW);
				}
				else if (variable == "Chaingun")
				{
					addToInventory(inventory, CHAINGUN);
				}
				else if (variable == "Pistol")
				{
					addToInventory(inventory, PISTOL);
				}
				else if (variable == "Shotgun")
				{
					addToInventory(inventory, SHOTGUN);
				}
				else if (variable == "Super Shotgun")
				{
					addToInventory(inventory, SUPER_SHOTGUN);
				}
				else if (variable == "Rocket Launcher")
				{
					addToInventory(inventory, ROCKET_LAUNCHER);
				}
				else if (variable == "Plasma Gun")
				{
					addToInventory(inventory, PLASMA_GUN);
				}
				else if (variable == "BFG9000")
				{
					addToInventory(inventory, BFG9000);
				}
		    	//addToInventory(inventory, drw);
		    	break;
		    case'd':
		    	cout << "\t\t\t displaying..." << endl;
		    	cout << "=========Display============" << endl;
		    	printInventoy(inventory);
				break;
			case'e':
				return 0;
				break;
			case'b':
				cout << "Would You Like To Enter Binary Data --> (b)" << endl;
				cout << "OR" << endl;
				cout << "Would You Like To Enter Decimal Data --> (d)" << endl;
				cout << "Enter A(a), if you would like" << endl;
				cin >> variable;
				if (variable == "b")
				{
					//cout << "Enter size of binary data" << endl;
					//cin >> temp;

					//cout << "Enter the binary of your choice" << endl;
					//for (int i = 0; i < temp; i++)
					//{
						//cout << "Enter First Binary Number: " << i + 1 << endl;
						//cin >> bitArray[i];
					//}
					cout << "Result: " << binToDec(&BinaryData);
					//cout << "Converting..." << endl;
					////convert function
					////binary-->Decimal
					//cout << "Decimal: " << endl;
					//cout << BinaryToDecimal(bitArray, temp) << endl;
					//cin.get();

					//cout << "Finished Converting..." << endl;

				}
				else if (variable == "d")
				{
					//-----------------KEY-------------------------
					// [1]--> temp = decimal number to be inputted
					cout << "Enter the Decimal of your choice" << endl;
					cin >> temp;
					cout << "Converting..." << endl;
					//convert function
					//Decimal-->binary
					cout << "Finished Converting..." << endl;

					cin.get();
					cout << "Binary: " << endl;
					DecimalToBinary(temp);

				}
				break;
			default:
				cout << "Try Again" << endl;
				break;
		}
	}


	//AND operator is a bitwise, if the name matches then it prints that bit value
	//OR operator to set individual bits in the bitfield inventory |= ROCKET_LAUNCHER; 
	//* operator to Toggle a bit in the bitfield, if set, to clear and if was clear, want to set.

	cin.get();
}

void printInventoy(char inventory)
{
	cout << weapons[0] << " | ";
	for (int i = 1; i < WEAPONS_COUNT; i++)
	{
		char mask = 0x01 << i - 1;
		if ((inventory & mask) == mask)
		{
			cout << weapons[i] << " | ";
		}
	}
	cout << endl;
}

void addToInventory(char& inventory, char weapon)
{
	inventory |= weapon; //adds to inventory
}