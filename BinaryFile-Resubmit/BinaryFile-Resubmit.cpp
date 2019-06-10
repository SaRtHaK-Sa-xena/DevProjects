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
		file.seekp(154, ios::beg);//24 //was 44 //was 64
	}
	else if (n == 3)
	{
		file.seekp(154 * 2, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekp(154 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(154 * 4, ios::beg); //was 65
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
		file.seekg(154 * 1, ios::beg); //was 44 //was 64
	}
	else if (n == 3)
	{
		file.seekg(154 * 2, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(154 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(154 * 4, ios::beg);
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

		//=========INITIALZING==========
		int ID = 0;
		char fullName[50];
		char Title[50];
		char Date[50];
		//=========INITIALZING==========

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
		
		
		//=============Get Name==========
		cout << "Enter Your Full Name: " << endl;
		cin.ignore(1, '\n');
		cin.getline(fullName, 50);
		//=============Get Name==========


		//=============Get Title==========
		cout << "Enter Title Of Book" << endl;
		cin.ignore(0, '\n');
		cin.getline(Title, 50);
		//=============Get Title==========

		//=============Get Date==========
		cout << "Enter Date Borrowed: " << endl;
		cin.ignore(0, '\n');
		cin.getline(Date, 50);
		//=============Get Date==========


		Data[n].setDate(Date);
		Data[n].setFullName(fullName);
		Data[n].setTitle(Title);


		//------- Used to test the Pointer for writing------
		//int w_pos = writeToFile.tellp();
		//cout << "Location To Write Set To: " << w_pos << endl;
		//-------------------------------------------------

		//Write ID and NAME
		writeToFile.write((char*)&ID, sizeof(int));
		writeToFile.write((char*)&fullName, sizeof(char) * 50);//10
		writeToFile.write((char*)&Title, sizeof(char) * 50);
		writeToFile.write((char*)&Date, sizeof(char) * 50);

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
		

		//==========GET NAME, TITLE, DATE=============
		char fullName[50];//10
		Data[n].getFullName(fullName);

		char Title[50];
		Data[n].getTitle(Title);

		char Date[50];
		Data[n].getDate(Date);
		//==========GET NAME, TITLE, DATE=============



		//==================GET ID=============================
		int temp = Data[n].getID(); //making temp 
		readToFile.read((char*)&temp, sizeof(int)); //reading ID
		Data[n].setID(temp); //setting to temp
		cout << "ID: " << Data[n].getID();
		//==================GET ID=============================


		
		readToFile.read((char*)&fullName, sizeof(char) * 50);//10
		cout << endl;
		cout << "Full Name: " << fullName;

		readToFile.read((char*)&Title, sizeof(char) * 50);
		cout << endl;
		cout << "Title: " << Title;

		readToFile.read((char*)&Date, sizeof(char) * 50);
		cout << endl;
		cout << "Date Entried: " << Date << endl;
		
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
		file.seekp(154 + 4, ios::beg); //added 20 //was 24 //was 44 + 4 -> 44 * 2 + 4 //was 44
	}
	else if (n == 3)
	{
		file.seekp(154 * 2 + 4, ios::beg);
	}
	else if (n == 4)
	{
		file.seekp(154 * 3 + 4, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(154 * 4 + 4, ios::beg);
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
		file.seekg(154 + 4, ios::beg); //was 24 //was 44
	}
	else if (n == 3)
	{
		file.seekg(154 * 2 + 4, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(154 * 3 + 4, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(154 * 4 + 4, ios::beg);
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
		char fullName[50];		
		//===========INITIALIZE=============


		cout << "Enter Full Name: " << endl;
		cin.ignore(1, '\n');
		cin.getline(fullName, 50);
	

		//======Overwrites========
		Data[n].setFullName(fullName);
		Write_NAME(fileToOverWrite, n); //set before NAME
		//======Overwrites========

		fileToOverWrite.write((char*)&fullName, sizeof(char) * 50);


		//--------Used to check Position in file-----------
		/*int w_pos = fileToOverWrite.tellp();
		cout << "Location To Write Set To: " << w_pos << endl;*/

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
	char SearchArray[50];
	//===========INITIALIZING==========


	//==============Enters Into Array To Search===========
	cin.ignore(1, '\n');
	cin.getline(SearchArray, 50);
	//==============Enters Into Array To Search===========

	for (int i = 0; i < 5; i++)
	{
		char FullName[50];
		Data[i].getFullName(FullName);
		Read_NAME(file, i);
		file.read((char*)&FullName, sizeof(char) * 50);
		if (!strcmp(SearchArray, FullName))
		{
			cout << "Location Found at Index: " << i << endl;
		}
	}

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




