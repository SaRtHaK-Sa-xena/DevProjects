// IntroProject___3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "Class.h"
#include <string>
using namespace std;


//======================RESET FUNCTION=============================================
void Reset(int n)
{
	cin >> n;
}
//======================END RESET FUNCTION================================


//===================Setting File Pointer(read and write) ================
void setWritePos(ofstream &file, int n)
{
	if (n == 1)
	{
		file.seekp(0, ios::beg);
	}
	else if (n == 2)
	{
		file.seekp(44, ios::beg);//24
	}
	else if (n == 3)
	{
		file.seekp(44 * 2, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekp(44 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(44 * 4, ios::beg);
	}
	/*if (n == 1)
	{
		file.seekp(0, ios::beg);
	}
	else if (n == 2)
	{
		file.seekp(14, ios::beg);
	}
	else if (n == 3)
	{
		file.seekp(14 * 2, ios::beg);
	}
	else if (n == 4)
	{
		file.seekp(14 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(14 * 4, ios::beg);
	}*/
}
void setReadPos(ifstream &file, int n)
{
	if (n == 1)
	{
		file.seekg(0, ios::beg);
	}
	else if (n == 2)
	{
		file.seekg(44 * 1, ios::beg);
	}
	else if (n == 3)
	{
		file.seekg(44 * 2, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(44 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(44 * 4, ios::beg);
	}
	else
	{
		cout << "Error" << endl;
		cout << "Max Limit: 5" << endl;
		cout << "Enter another Index" << endl;
		Reset(n);
	}
	/*if (n == 1)
	{
		file.seekg(0, ios::beg);
	}
	else if (n == 2)
	{
		file.seekg(14 * 1, ios::beg);
	}
	else if (n == 3)
	{
		file.seekg(14 * 2, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(14 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(14 * 4, ios::beg);
	}
	else
	{
		cout << "Error" << endl;
		cout << "Max Limit: 5" << endl;
		cout << "Enter another Index" << endl;
		Reset(n);
	}*/
}
//=======================End FilePointer Function ========================

Record Data[5]; //initialize class array


//===========WRITE BIN. FILE FUNCTION ====================================[EDITTED]
void Write(int n)
{
	ofstream writeToFile;
	writeToFile.open("BinaryFile.dat", ios::out | ios::binary | ios::app); //open file
	if (writeToFile.is_open())
	{
		int ID = 0;// initialize

		//===========NEXT EDIT=============

		//=============NAME==========
		char fullName[20];//10
		char firstName[10];//5
		char secondName[10];//5
		//=============NAME==========

		//============TITLE==========
		char Title[20];
		char firstWord[10];
		char secondWord[10];
		//============TITLE==========


		//===========NEXT EDIT=============

		//=====ORIGINAL==========
		//char name[10]; // initialize
		//=====ORIGINAL==========

		//======EDITTED========
		//string Full_Name;
		//======EDITTED========



		// Gain ID AND NAME
		cout << "What ID: " << endl;
		cin >> ID;
		while (cin.fail())
		{
			cout << "Error" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a number please: " << endl;
			cin >> ID;
		}

		//============NEXT EDIT============

		//=============Get Name============
		cout << "Enter Your Full Name: " << endl;
		cin >> firstName >> secondName;
		//=============Get Name============

		//=============Get Title==========
		cout << "Enter Title Of Book" << endl;
		cin >> firstWord >> secondWord;
		//=============Get Title==========


		//===========FULL NAME=============
		strcpy_s(fullName, firstName);
		strcat_s(fullName, " ");
		strcat_s(fullName, secondName);
		//===========FULL NAME=============

		//===========FULL TITLE============
		strcpy_s(Title, firstWord);
		strcat_s(Title, " ");
		strcat_s(Title, secondWord);
		//===========FULL TITLE============

		Data[n].setTitle(Title);
		Data[n].setFullName(fullName);
		//============NEXT EDIT============


		//===========EDITTED==================
		//cout << "Enter Your Full Name: " << endl;
		//cin.ignore(10,'\n');
		//getline(cin, Full_Name); // Enter Full Name
		//Data[n].setFullName(Full_Name); //Sets Data Index [n] to  have Full Name 
		//===========EDITTED==================

		//=========ORIGINAL=================
		//cout << "Enter Name: " << endl;
		//cin >> name;
		//Data[n].setName(name);
		//=========ORIGINAL=================


		//------- Used to test the Pointer for writing------
		//int w_pos = writeToFile.tellp();
		//cout << "Location To Write Set To: " << w_pos << endl;
		//-------------------------------------------------

		//Write ID and NAME
		writeToFile.write((char*)&ID, sizeof(int));

		//====================NEXT EDIT=========================
		writeToFile.write((char*)&fullName, sizeof(char) * 20);//10
		writeToFile.write((char*)&Title, sizeof(char) * 20);
		//====================NEXT EDIT=========================

		//====================EDITTED===========================
		//writeToFile.write((char*)&Full_Name, sizeof(char) * 10); //strlen for size
		//====================EDITTED===========================


		//=================ORIGINAL===================
		//writeToFile.write((char*)&name, sizeof(char) * 10);
		//=================ORIGINAL===================

		Data[n].setID(ID);	//set, and continue
	}
	writeToFile.close();
}
//==========END WRITE BIN. FILE FUNCTION =================================


//===============read TEXT FILE FUNCTION==================================
void ReadTXT()
{
	//reads all lines of text
	ifstream file;
	file.open("SampleText.txt", ios::in);
	if (file.is_open())
	{
		string variable;
		while (getline(file, variable))
		{
			cout << variable << "\n";
		}
		file.close();
	}
}
//===============End ReadText File function===============================


//==============READ BIN. FUNCTION =======================================[EDITTED]
void Read(int n)
{
	ifstream readToFile;
	Record Log;
	readToFile.open("BinaryFile.dat", ios::in | ios::binary);
	if (readToFile.is_open())
	{
		setReadPos(readToFile, n); //setting file pointer to INDEX
		//------------------------------------------------
		//int r_pos = readToFile.tellg();
		//cout << "Location To Read Set To: " << r_pos << endl;
		//------------------------------------------------ Used for testing file pointer to read
		
		//========ORIGINAL==========
		//char range[10];
		//Data[n].getName(range);
		//========ORIGINAL==========

		//==============NEXT EDIT==========================
		char fullName[20];//10
		Data[n].getFullName(fullName);

		char Title[20];
		Data[n].getTitle(Title);
		//==============NEXT EDIT==========================


		//=============EDITTED=============================
		//char Full_Name[10];
		//Data[n].getFullName(Full_Name); //seems to work
		//=============EDITTED=============================



		int temp = Data[n].getID(); //making temp 
		readToFile.read((char*)&temp, sizeof(int)); //reading ID
		Data[n].setID(temp); //setting to temp
		cout << "ID: " << Data[n].getID();


		//=======================NEXT EDIT=====================
		readToFile.read((char*)&fullName, sizeof(char) * 20);//10
		cout << endl;
		cout << "Full Name: " << fullName;


		readToFile.read((char*)&Title, sizeof(char) * 20);
		cout << endl;
		cout << "Title: " << Title;
		//=======================NEXT EDIT=====================


		//==============EDITTED================================
		//readToFile.read((char*)&Full_Name, sizeof(char) * 10);
		//cout << endl;
		//cout << "Full Name: " << Full_Name;
		//==============EDITTED================================


		//========ORIGINAL==============
		//readToFile.read((char*)&range, sizeof(char) * 10); //reading NAME
		//cout << endl;
		//cout << "Name: " << range;
		//========ORIGINAL==============


		//Printed ID AND NAME
	}
	readToFile.close();
}
//=============END READ BIN.FUNCTION ======================================



//================SET READ AND WRITE FILE POINTER FUNTION==================
void Write_NAME(ofstream &file, int n)
{
	//sets at beginning of NAME
	if (n == 1)
	{
		file.seekp(4, ios::beg);
	}
	else if (n == 2)
	{
		file.seekp(24 + 4, ios::beg);
	}
	else if (n == 3)
	{
		file.seekp(24 * 2 + 4, ios::beg);
	}
	else if (n == 4)
	{
		file.seekp(24 * 3 + 4, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(24 * 4 + 4, ios::beg);
	}
	////sets at beginning of NAME
	//if (n == 1)
	//{
	//	file.seekp(4, ios::beg);
	//}
	//else if (n == 2)
	//{
	//	file.seekp(14 + 4, ios::beg);
	//}
	//else if (n == 3)
	//{
	//	file.seekp(14 * 2 + 4, ios::beg);
	//}
	//else if (n == 4)
	//{
	//	file.seekp(14 * 3 + 4, ios::beg);
	//}
	//else if (n == 5)
	//{
	//	file.seekp(14 * 4 + 4, ios::beg);
	//}
}
void Read_NAME(ifstream &file, int n)
{
	//sets at beginning of NAME
	if (n == 1)
	{
		file.seekg(4, ios::beg);
		//file.seekg(4, ios::beg);
	}
	else if (n == 2)
	{
		file.seekg(24 + 4, ios::beg);
	}
	else if (n == 3)
	{
		file.seekg(24 * 2 + 4, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(24 * 3 + 4, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(24 * 4 + 4, ios::beg);
	}
	////sets at beginning of NAME
	//if (n == 1)
	//{
	//	file.seekg(4, ios::beg);
	//	//file.seekg(4, ios::beg);
	//}
	//else if (n == 2)
	//{
	//	file.seekg(14 + 4, ios::beg);
	//}
	//else if (n == 3)
	//{
	//	file.seekg(14 * 2 + 4, ios::beg);
	//}
	//else if (n == 4)
	//{
	//	file.seekg(14 * 3 + 4, ios::beg);
	//}
	//else if (n == 5)
	//{
	//	file.seekg(14 * 4 + 4, ios::beg);
	//}
}
//============END SET READ AND WRITE FILE POINTER FUNTION==================



//========================UPDATE NAME FUNCTION===================================
void Overwrite_NAME(int n)
{
	ofstream fileToOverWrite;
	fileToOverWrite.open("BinaryFile.dat", ios::in | ios::out | ios::binary);
	if (fileToOverWrite.is_open())
	{
		setWritePos(fileToOverWrite, n); //set position in file at INDEX

		//===========INITIALIZE=============
		char fullName[20];
		char firstName[10];
		char secondName[10];
		//===========INITIALIZE=============


		cout << "Enter Full Name: " << endl;
		cin >> firstName >> secondName;

		//=====Writes Name
		strcpy_s(fullName, firstName);
		strcat_s(fullName, " ");
		strcat_s(fullName, secondName);
		//=====Writes Name

		//======Overwrites========
		Data[n].setFullName(fullName);
		Write_NAME(fileToOverWrite, n); //set before NAME
		//======Overwrites========

		fileToOverWrite.write((char*)&fullName, sizeof(char) * 20);

		//===================ORIGINAL=======================
		//char name[10]; //10
		//cout << "Enter Name: " << endl;
		//cin >> name;
		//Data[n].setName(name);
		//Write_NAME(fileToOverWrite, n); //set before NAME


		//--------Used to check Position in file-----------
		/*int w_pos = fileToOverWrite.tellp();
		cout << "Location To Write Set To: " << w_pos << endl;*/

		//fileToOverWrite.write((char*)&name, sizeof(char) * 20); //writes name over that data //10
		//===================ORIGINAL=======================

	}

}
//=====================END UPDATE NAME FUNCTION===================================


//================================UPDATE ID FUNCTION============================
void OVERWRITE_Integer(int n)
{
	ofstream fileToOverwrite;
	fileToOverwrite.open("BinaryFile.dat", ios::in | ios::out | ios::binary);
	if (fileToOverwrite.is_open())
	{
		//Obtain ID
		int ID = 0;
		cout << "What ID: " << endl;
		cin >> ID;
		while (cin.fail())
		{
			cout << "Error" << endl;
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Enter a number please: " << endl;
			cin >> ID;
		}
		setWritePos(fileToOverwrite, n); //set at specific INDEX

		//-----------Used to test file pointer------------
		//int w_pos = fileToOverwrite.tellp();
		//cout << "Location To Write Set To: " << w_pos << endl;
		//--------------------------------------------------

		fileToOverwrite.write((char*)&ID, sizeof(int)); //writes ID over data
		Data[n].setID(ID); //set and continue
	}
	fileToOverwrite.close();
}
//=========================END UPDATE ID FUNCTION==============================


//=================SEARCH BY NAME FUNCTION=====================================
void search_integer()
{
	ifstream file;
	file.open("BinaryFile.dat", ios::in | ios::binary);

	//===========INITIALIZING==========
	char SearchArray[20];
	char firstComponent[10];
	char secondComponent[10];
	//===========INITIALIZING==========


	//==============Enters Into Array To Search===========
	cin >> firstComponent >> secondComponent;
	strcpy_s(SearchArray, firstComponent);
	strcat_s(SearchArray, " ");
	strcat_s(SearchArray, secondComponent);
	//==============Enters Into Array To Search===========

	for (int i = 0; i < 5; i++)
	{
		char FullName[20];
		Data[i].getFullName(FullName);
		Read_NAME(file, i);
		file.read((char*)&FullName, sizeof(char) * 20);
		if (!strcmp(SearchArray, FullName))
		{
			cout << "Location Found at Index: " << i << endl;
		}
	}

	//=========================ORIGINAL==================================================
	//char ToSearch[10]; //get temp array
	//cin >> ToSearch;
	//for (int i = 0; i < 5; i++) //loop throught the Data[i] <- positioon to find name
	//{
	//	char name[10];
	//	Data[i].getName(name); //store it
	//	Read_NAME(file, i); //set pointer before NAME
	//	file.read((char*)&name, sizeof(char) * 10); //read over name
	//	if (!strcmp(ToSearch, name)) //compare strings( ToSearch and range_test)
	//	{
	//		cout << "Location Found at Index: " << i << endl; //print i, which is the index
	//	}
	//}
	//=========================ORIGINAL==================================================

}
//================END SEARCH BY NAME FUNCTION==================================

int main()
{
	//-----------------Initialization-------------
	bool cont = true;
	char choice = '0';
	int n = 0;
	string response;
	//-----------------Initialization-----------
	while (cont)
	{
		cout << "\t\t\t==========Choose==========" << endl;
		cout << "------------------(R)ead====(W)rite====(u)pdate===(S)earch====(E)xit-----------------" << endl;

		//Text File Sample--------------------------------
		cout << "\n\n\n\nWould You Like To Read A Sample Text(y)" << endl;
		cout << " ____________" << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "| ~~~~~~~~~~ |" << endl;
		}
		//-------------------------------------------

		cout << endl;
		cin >> choice;
		switch (choice)
		{
		case'r':
			cout << "\t\t\t reading..." << endl;
			cout << "Which Index To Read: " << endl;
			cin >> n; //takes index
			Read(n);
			break;
		case'w':
			cout << "\t\t\t writing..." << endl;
			Write(n); //takes index
			break;
		case'e':
			cout << "\t\t\t Closing Program..." << endl;
			return 0;
		case 'y':
			cout << "\t\t\t Opening Sample Text..." << endl;
			ReadTXT(); //opens sample text
			break;
		case 'u':
			//Updates record accordingly
			cout << "\t\t\t Updating Record..." << endl;
			cout << "\t\t\t Which Record To update?" << endl;
			cout << "Update Record No: ";
			cin >> n;
			//Either change Name or ID
			cout << "Would you like to edit the ID or NAME?" << endl;
			cout << "Enter ==================>(id) or (name)" << endl;
			cin >> response;
			if (response == "name")
			{
				Overwrite_NAME(n);
			}
			else if (response == "id")
			{
				OVERWRITE_Integer(n);
			}
			else
			{
				cout << "Entered something else" << endl;
				cout << "-exiting command-" << endl;
				break;
			}
			break;
		case's':
			//searches record accordingly
			cout << "\t\t\t Searching Index..." << endl;
			cout << "Enter Name To find: " << endl;
			search_integer();
			cout << endl;
			cout << "\t\t\t Searching by Name..." << endl;
			break;
		default:
			cout << "Please Choose one of the Options listed" << endl;
			break;
		}
	}
	cont = false;
	return 0;

}




