// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include "BitfieldOperators.h"

using namespace std;

const char BinaryData[] = { "11011" };
char BinaryNumber[8];

//const char MACHETE = 0;
//const char CHAINSAW = 0x01;
//const char PISTOL = 0x01 << 1;
//const char SHOTGUN = 0x01 << 2;
//const char SUPER_SHOTGUN = 0x01 << 3;
//const char CHAINGUN = 0x01 << 4;
//const char ROCKET_LAUNCHER = 0x01 << 5;
//const char PLASMA_GUN = 0x01 << 6;
//const char BFG9000 = 0x01 << 7;
//
//const int WEAPONS_COUNT = 10;
//
//const char* weapons[] = { "Fists","Chainsaw", "Pistol", "Shotgun", "Super Shotgun", "Chaingun", "Rocket Launcher", "Plasma Gun", "BFG 9000"};

//const char weapon[] = { MACHETE, CHAINSAW, PISTOL, SHOTGUN, SUPER_SHOTGUN, CHAINGUN, ROCKET_LAUNCHER, PLASMA_GUN, BFG9000 };

//void printInventoy(char inventory);
void addToInventory(char& inventory, char weapon);

int main()
{
	srand(time(NULL));
	char inventory = 0;
	char choice = '0';
	string variable;
	bool cont = true;
	char weapon[20];


	int bitArray[50];
	int bitNo;
	int Decimal;
	int temp;
	int i;

	//========Intialization=========
	const char CHAINSAW = 1 << 2;
	const char PISTOL = 1 << 3;
	const char CHAINGUN = 1 << 4;
	int n_number = 0;
	//========Intialization=========

	//weapons[rand() % 10];
	while (cont)
	{
		cout << "(a)dd----(d)isplay--(b)itfield_Example----" << endl;
		cin >> choice;
		switch (choice)
		{
		    case'a':
		    	cout << "\t\t\t testing..." << endl;

									/*TEST*/
				//manually add Chainsaw, Pistol, Chaingun to inventory
				inventory |= CHAINSAW; //set to 00000100
				inventory |= PISTOL; //set to 00010000
				inventory |= CHAINGUN; //set to 00001000
				//====================================================

				
				//add through Setbit function, First check if it has
				//been set, then return set. After that check if it has
				//been set and clear it, then check if it has been clea-
				//-red.
				cout << "----Enter to clear[0] or set[1]----" << endl;
				cin >> n_number;
				setBit(inventory, 2, 0); //this is to check if CHAINSAW
										 //is set, so if set to 1 it'll
										 //keep the value.
				if (checkBit(inventory, 2) == '1')
				{
					cout << "CHAINSAW set" << endl;
				}
				else
				{
					cout << "CHAINSAW not set" << endl;
				}
				//=====================================================

				system("PAUSE");
				cout << "========================================" << endl;
				//Use checkbit to see if that value is set to '1' or '0
				if (checkBit(inventory, 2) == '1')
				{
					cout << "Check Passed: " << "The Position was set" << endl;
					cout << "CHAINSAW has been set in inventory" << endl;
				}
				else
				{
					cout << "CHAINSAW WAS NOT SET" << endl;
				}
				cout << "========================================" << endl;
				if (checkBit(inventory, 3) == '1')
				{
					cout << "Check Passed: " << "The Position was set" << endl;
					cout << "PISTOL has been set in inventory" << endl;
				}
				else
				{
					cout << "PISTOL WAS NOT SET" << endl;
				}
				cout << "========================================" << endl;
				if (checkBit(inventory, 4) == '1')
				{
					cout << "Check Passed: " << "The Position was set" << endl;
					cout << "CHAINGUN has been set in inventory" << endl;
				}
				else
				{
					cout << "CHAINGUN WAS NOT SET" << endl;
				}
				//=====================================================

				system("PAUSE");




		    	cout << "Enter Gun Name: " << endl;
				cin >> variable;

				//cout << "Enter Item No: " << endl;
				//cin >> temp;

				//cout << "Which Weapon" << endl;
				//cin >> i;
				//setBit(inventory, weapon[i], temp);

				//cin >> variable;
				//if (variable == "Chainsaw")
				//{
				//	if ((inventory & CHAINSAW) == CHAINSAW)
				//	{
				//		cout << "Yes, True" << endl;
				//	}
				//}
				//else if (variable == "Chaingun")
				//{
				//	addToInventory(inventory, CHAINGUN);
				//}
				//else if (variable == "Pistol")
				//{
				//	addToInventory(inventory, PISTOL);
				//}
				//else if (variable == "Shotgun")
				//{
				//	addToInventory(inventory, SHOTGUN);
				//}
				//else if (variable == "Super Shotgun")
				//{
				//	addToInventory(inventory, SUPER_SHOTGUN);
				//}
				//else if (variable == "Rocket Launcher")
				//{
				//	addToInventory(inventory, ROCKET_LAUNCHER);
				//}
				//else if (variable == "Plasma Gun")
				//{
				//	addToInventory(inventory, PLASMA_GUN);
				//}
				//else if (variable == "BFG9000")
				//{
				//	addToInventory(inventory, BFG9000);
				//}
		    	break;
		    case'd':
		    	cout << "\t\t\t displaying..." << endl;
		    	cout << "=========Display============" << endl;
		    	//printInventoy(inventory);
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
					cout << "Result: " << binToDec(BinaryData);
					//convert function
					//binary-->Decimal
				}
				else if (variable == "d")
				{
					//-----------------KEY-------------------------
					// [1]--> temp = decimal number to be inputted
					cout << "Enter the Decimal of your choice" << endl;
					cin >> temp;
					decToBin(BinaryNumber, 8, temp);
					cout << "Converting..." << endl;
					//convert function
					//Decimal-->binary
					cout << "Finished Converting..." << endl;

					cin.get();
					cout << "Binary: " << endl;
					cout << BinaryNumber;
					//DecimalToBinary(temp);

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

//void printInventoy(char inventory)
//{
//	cout << weapons[0] << " | ";
//	for (int i = 1; i < WEAPONS_COUNT; i++)
//	{
//		char mask = 0x01 << i - 1;
//		if ((inventory & mask) == mask)
//		{
//			cout << weapons[i] << " | ";
//		}
//	}
//	cout << endl;
//}

void addToInventory(char& inventory, char weapon)
{
	inventory |= weapon; //adds to inventory
}