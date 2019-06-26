// Binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <time.h>
#include "BitfieldOperators.h"

using namespace std;

const char BinaryData[] = { "00011011" };
const char BinaryDat2[] = { "00000001" };
const char BinaryDat3[] = { "11010101" };
char BinaryNumber[8];

int main()
{
	char inventory = 0;
	char choice = '0';
	string variable;
	bool cont = true;
	bool check;

	//========Intialization=========
	const char CHAINSAW = 1 << 2;
	const char PISTOL = 1 << 3;
	const char CHAINGUN = 1 << 4;
	int n_number = 0;
	int temp = 0;
	//========Intialization=========

	//weapons[rand() % 10];
	while (cont)
	{
		cout << "(r)un Main Test----(d)isplay--(b)itfield_Example----" << endl;
		cin >> choice;
		switch (choice)
		{
		    case'r':
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
				cout << "============TEST FOR CHAINSAW==========" << endl;
				cout << "----Enter to clear[0] or set[1]----" << endl;
				cin >> n_number;
				setBit(inventory, 2, n_number); //this is to check if CHAINSAW
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

				cout << "===========TEST FOR PISTOL==============" << endl;
				cout << "----Enter to clear[0] or set[1]----" << endl;
				cin >> n_number;
				setBit(inventory, 3, n_number);

				if (checkBit(inventory, 3) == '1')
				{
					cout << "PISTOL set" << endl;
				}
				else
				{
					cout << "PISTOL not set" << endl;
				}
				cout << "Try Clearing it this time or Setting it if you previously cleared it" << endl;
				cout << "----Enter to clear[0] or set[1]----" << endl;
				cin >> n_number;
				setBit(inventory, 3, n_number);
				if (checkBit(inventory, 4) == '1')
				{
					cout << "PISTOL set" << endl;
				}
				else
				{
					cout << "PISTOL not set" << endl;
				}


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
		    	break;
			case'e':
				return 0;
				break;
			case'b':
				cout << "Run Test For Binary Data --> (b)" << endl;
				cout << "OR" << endl;
				cout << "Would You Like To Enter Decimal Data --> (d)" << endl;
				cin >> variable;
				if (variable == "b")
				{
					//convert function
					//binary-->Decimal

					cout << "========================================" << endl;
					//================ TEST 1
					cout << "Binary Data = 00011011" << endl;
					cout << "Result: " << binToDec(BinaryData) << endl;

					system("PAUSE");

					cout << "Actual Result: 27" << endl;
					if (binToDec(BinaryData) == 27)
					{
						cout << "Check Passed..." << endl;
					}
					else
					{
						cout << "Check Failed..." << endl;
						cout << "Result does not match Actual Result" << endl;
					}
					cout << "========================================" << endl;
					//================ TEST 2
					
					cout << "Binary Data = 00000001" << endl;
					cout << "Result: " << binToDec(BinaryDat2) << endl;

					system("PAUSE");

					cout << "Actual Result: 1" << endl;
					if (binToDec(BinaryDat2) == 1)
					{
						cout << "Check Passed..." << endl;
					}
					else
					{
						cout << "Check Failed..." << endl;
						cout << "Result does not match Actual Result" << endl;
					}
					cout << "========================================" << endl;
					//================ TEST 2
					cout << "Binary Data = 11010101" << endl;
					cout << "Result: " << binToDec(BinaryDat3) << endl;

					system("PAUSE");

					cout << "Actual Result: 213" << endl;
					if (binToDec(BinaryDat3) == 213)
					{
						cout << "Check Passed..." << endl;
					}
					else
					{
						cout << "Check Failed..." << endl;
						cout << "Result does not match Actual Result" << endl;
					}
					cout << "========================================" << endl;
				}
				else if (variable == "d")
				{
					//-----------------KEY-------------------------
					// [1]--> temp = decimal number to be inputted
					cout << "Enter the Decimal of your choice" << endl;
					cin >> temp;


					decToBin(BinaryNumber, 8, temp);//Decimal-->binary
					cout << "Converting..." << endl;
					cout << "Finished Converting..." << endl;

					cin.get();
					cout << "Binary: " << endl;
					cout << BinaryNumber << endl;
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
}
