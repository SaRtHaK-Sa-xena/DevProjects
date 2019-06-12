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
		file.seekp(254, ios::beg);//24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekp(254 * 2, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekp(254 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(254 * 4, ios::beg); //was 65
	}
	else if (n == 5)
	{
		file.seekp(254 * 4, ios::beg); //was 65
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
		file.seekg(254 * 1, ios::beg); //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekg(254 * 2, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(254 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(254 * 4, ios::beg);
	}
	else
	{
		cout << "Error" << endl;
		cout << "Max Limit: 5" << endl;
		cout << "Try Again later" << endl;
		//Reset(n);
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

Record Data[10]; //initialize class array


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
		char Author[50];
		char BookStatus[50];
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

		//=============Get Author=========
		cout << "Enter Author Of Book" << endl;
		cin.ignore(0, '\n');
		cin.getline(Author, 50);
		//=============Get Author=========

		//=========Get Book Status========
		cout << "Enter Book Status " << "\n(1 = In Library)--(2 = Lost)--(3 = Damaged)" << endl;
		cin.ignore(0, '\n');
		cin.getline(BookStatus, 50);
		//=========Get Book Status========

		//=============Get Date==========
		cout << "Enter Date Borrowed: " << endl;
		cout << "(DD/MM/YY)" << endl;
		cin.ignore(0, '\n');
		cin.getline(Date, 50);
		//=============Get Date==========


		Data[n].setDate(Date);
		Data[n].setFullName(fullName);
		Data[n].setTitle(Title);
		Data[n].setAuthor(Author);
		Data[n].setStatus(BookStatus);

		//------- Used to test the Pointer for writing------
		//int w_pos = writeToFile.tellp();
		//cout << "Location To Write Set To: " << w_pos << endl;
		//-------------------------------------------------

		//Write ID and NAME
		writeToFile.write((char*)&ID, sizeof(int));// ID
		writeToFile.write((char*)&fullName, sizeof(char) * 50);//10 // FULL NAME
		writeToFile.write((char*)&Title, sizeof(char) * 50); // TITLE
		writeToFile.write((char*)& Author, sizeof(char) * 50); // AUTHOR
		writeToFile.write((char*)& BookStatus, sizeof(char) * 50); // BOOK STATUS
		writeToFile.write((char*)&Date, sizeof(char) * 50); // DATE

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

//=================EDIT LATEST READ FUNCTION===========================
void Read_ID(ifstream &file, int n)
{
	if (n == 1)
	{
		file.seekg(0, ios::beg);
	}
	else if (n == 2)
	{
		file.seekg(254, ios::beg);//24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekg(254 * 2, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekg(254 * 3, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(254 * 4, ios::beg); //was 65
	}
}

void Read_Title(ifstream& file, int n)
{
	if (n == 1)
	{
		file.seekg(54, ios::beg);
	}
	else if (n == 2)
	{
		file.seekg(254*1 + 54, ios::beg);//24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekg(254 * 2 + 54, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekg(254 * 3 + 54, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(254 * 4 + 54, ios::beg); //was 65
	}
}

void Read_Author(ifstream& file, int n)
{
	if (n == 1)
	{
		file.seekg(104, ios::beg);
	}
	else if (n == 2)
	{
		file.seekg(254 * 1 + 104, ios::beg);//24 //was 44 //was 64 //was 154 + 54
	}
	else if (n == 3)
	{
		file.seekg(254 * 2 + 104, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekg(254 * 3 + 104, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(254 * 4 + 104, ios::beg); //was 65
	}
}

void Read_Status(ifstream& file, int n)
{
	if (n == 1)
	{
		file.seekg(154, ios::beg); //154 was 204
	}
	else if (n == 2)
	{
		file.seekg(254 * 1 + 154, ios::beg);//24 //was 44 //was 64 //was 154 + 54
	}
	else if (n == 3)
	{
		file.seekg(254 * 2 + 154, ios::beg);//24*2
	}
	else if (n == 4)
	{
		file.seekg(254 * 3 + 154, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(254 * 4 + 154, ios::beg); //was 65
	}
}
//=================EDIT LATEST READ FUNCTION===========================





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


		char Author[50];
		Data[n].getAuthor(Author);

		char BookStatus[50];
		Data[n].getStatus(BookStatus);

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

		readToFile.read((char*)& Author, sizeof(char) * 50);
		cout << endl;
		cout << "Author: " << Author;

		readToFile.read((char*)& BookStatus, sizeof(char) * 50);
		cout << endl;
		cout << "Book Status:" << BookStatus << endl;

		readToFile.read((char*)&Date, sizeof(char) * 50);
		cout << endl;
		cout << "Date Entried: " << Date << endl;
		
		//Search by Unique ID, Name, Title, Author, Book Status, 

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
		file.seekp(254 + 4, ios::beg); //For debugging Purposes--->//added 20 //was 24 //was 44 + 4 -> 44 * 2 + 4 //was 44 // was 154
	}
	else if (n == 3)
	{
		file.seekp(254 * 2 + 4, ios::beg);
	}
	else if (n == 4)
	{
		file.seekp(254 * 3 + 4, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(254 * 4 + 4, ios::beg);
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
		
	}
	else if (n == 2)
	{
		file.seekg(254 + 4, ios::beg);//For debugging Purposes---> //was 24 //was 44 //was 154
	}
	else if (n == 3)
	{
		file.seekg(254 * 2 + 4, ios::beg);
	}
	else if (n == 4)
	{
		file.seekg(254 * 3 + 4, ios::beg);
	}
	else if (n == 5)
	{
		file.seekg(254 * 4 + 4, ios::beg);
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

void Write_Title(ofstream& file, int n)
{
	if (n == 1)
	{
		file.seekp(54, ios::beg);
	}
	else if (n == 2)
	{
		file.seekp(254 * 1 + 54, ios::beg);//For debugging Purposes--->//24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekp(254 * 2 + 54, ios::beg);//For debugging Purposes--->//24*2
	}
	else if (n == 4)
	{
		file.seekp(254 * 3 + 54, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(254 * 4 + 54, ios::beg);//For debugging Purposes--->was 65
	}
}

void Write_Author(ofstream &file, int n)
{
	if (n == 1)
	{
		file.seekp(104, ios::beg); //For debugging Purposes--->104
	}
	else if (n == 2)
	{
		file.seekp(254 * 1 + 104, ios::beg);//For debugging Purposes--->//24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekp(254 * 2 + 104, ios::beg);//For debugging Purposes--->//24*2
	}
	else if (n == 4)
	{
		file.seekp(254 * 3 + 104, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(254 * 4 + 104, ios::beg); //For debugging Purposes--->//was 65
	}
}

void Write_Status(ofstream &file, int n)
{
	if (n == 1)
	{
		file.seekp(154, ios::beg); //For debugging Purposes--->154
	}
	else if (n == 2)
	{
		file.seekp(254 * 1 + 154, ios::beg);//For debugging Purposes--->//24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekp(254 * 2 + 154, ios::beg);//For debugging Purposes--->24*2
	}
	else if (n == 4)
	{
		file.seekp(254 * 3 + 154, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(254 * 4 + 154, ios::beg); //For debugging Purposes--->was 65
	}
}

void Write_Date(ofstream &file, int n)
{
	if (n == 1)
	{
		file.seekp(204, ios::beg);//For debugging Purposes--->204
	}
	else if (n == 2)
	{
		file.seekp(254 * 1 + 204, ios::beg);//For debugging Purposes--->24 //was 44 //was 64 //was 154
	}
	else if (n == 3)
	{
		file.seekp(254 * 2 + 204, ios::beg);////For debugging Purposes--->24*2
	}
	else if (n == 4)
	{
		file.seekp(254 * 3 + 204, ios::beg);
	}
	else if (n == 5)
	{
		file.seekp(254 * 4 + 204, ios::beg); ////For debugging Purposes--->was 65
	}
}

void OVERWRITE_Title(int n)
{
	ofstream fileToOverWrite;
	fileToOverWrite.open("BinaryFile.dat", ios::in | ios::out | ios::binary);
	if (fileToOverWrite.is_open())
	{
		setWritePos(fileToOverWrite, n); //set position in file at INDEX

		//===========INITIALIZE=============
		char fullTitle[50];
		//===========INITIALIZE=============


		cout << "Enter Title: " << endl;
		cin.ignore(1, '\n');
		cin.getline(fullTitle, 50);


		//======Overwrites========
		Data[n].setTitle(fullTitle);
		Write_Title(fileToOverWrite, n); //set before NAME
		//======Overwrites========

		fileToOverWrite.write((char*)& fullTitle, sizeof(char) * 50);


		//--------Used to check Position in file-----------
		/*int w_pos = fileToOverWrite.tellp();
		cout << "Location To Write Set To: " << w_pos << endl;*/

	}
}

void OVERWRITE_Author(int n)
{
	ofstream fileToOverWrite;
	fileToOverWrite.open("BinaryFile.dat", ios::in | ios::out | ios::binary);
	if (fileToOverWrite.is_open())
	{
		setWritePos(fileToOverWrite, n); //set position in file at INDEX

		//===========INITIALIZE=============
		char fullAuthor[50];
		//===========INITIALIZE=============


		cout << "Enter Author: " << endl;
		cin.ignore(1, '\n');
		cin.getline(fullAuthor, 50);


		//======Overwrites========
		Data[n].setAuthor(fullAuthor);
		Write_Author(fileToOverWrite, n); //set before NAME
		//======Overwrites========

		fileToOverWrite.write((char*)& fullAuthor, sizeof(char) * 50);


		//--------Used to check Position in file-----------
		/*int w_pos = fileToOverWrite.tellp();
		cout << "Location To Write Set To: " << w_pos << endl;*/

	}
}

void OVERWRITE_BookStatus(int n)
{
	ofstream fileToOverWrite;
	fileToOverWrite.open("BinaryFile.dat", ios::in | ios::out | ios::binary);
	if (fileToOverWrite.is_open())
	{
		setWritePos(fileToOverWrite, n); //set position in file at INDEX

		//===========INITIALIZE=============
		char fullStatus[50];
		//===========INITIALIZE=============


		cout << "Enter Status: " << endl;
		cin.ignore(1, '\n');
		cin.getline(fullStatus, 50);


		//======Overwrites========
		Data[n].setStatus(fullStatus);
		Write_Status(fileToOverWrite, n); //set before NAME
		//======Overwrites========

		fileToOverWrite.write((char*)& fullStatus, sizeof(char) * 50);


		//--------Used to check Position in file-----------
		/*int w_pos = fileToOverWrite.tellp();
		cout << "Location To Write Set To: " << w_pos << endl;*/

	}
}

void OVERWRITE_Date(int n)
{
	ofstream fileToOverWrite;
	fileToOverWrite.open("BinaryFile.dat", ios::in | ios::out | ios::binary);
	if (fileToOverWrite.is_open())
	{
		setWritePos(fileToOverWrite, n); //set position in file at INDEX

		//===========INITIALIZE=============
		char fullDate[50];
		//===========INITIALIZE=============


		cout << "Enter Status: " << endl;
		cin.ignore(1, '\n');
		cin.getline(fullDate, 50);


		//======Overwrites========
		Data[n].setStatus(fullDate);
		Write_Date(fileToOverWrite, n); //set before NAME
		//======Overwrites========

		fileToOverWrite.write((char*)& fullDate, sizeof(char) * 50);


		//--------Used to check Position in file-----------
		/*int w_pos = fileToOverWrite.tellp();
		cout << "Location To Write Set To: " << w_pos << endl;*/

	}
}

//=================SEARCH BY NAME FUNCTION=====================================
void search_integer()
{
	ifstream file;
	file.open("BinaryFile.dat", ios::in | ios::binary);

	//===========INITIALIZING==========
	char SearchArray[50];
	char SearchTitleArray[50];
	char SearchingAuthor[50];
	char SearchingBookStatus[50];
	int ID_no = 0;

	//===========INITIALIZING==========


	

	string choice;
	cout << "Search By (name)---unique(id)------(author)----(title)-----Book(status)" << endl;
	cin >> choice;


	//=================================NAME==================================
	if (choice == "name")
	{
		cout << "Enter Name To find: " << endl;
		//==============Enters Into Array To Search===========
		cin.ignore(1, '\n');
		cin.getline(SearchArray, 50);
		//==============Enters Into Array To Search===========
		for (int i = 0; i < 5; i++)
		{

			char FullName[50];
			Data[i].getFullName(FullName);
			Read_NAME(file, i);
			file.read((char*)& FullName, sizeof(char) * 50);
			if (!strcmp(SearchArray, FullName))
			{
				cout << "--------------------------------------" << endl;
				cout << "Location Found at Index: " << i << endl;
				Read(i);
				cout << "--------------------------------------" << endl;
			}
		}
	}
	//=================================NAME==================================

	//=================================ID==================================
	else if (choice == "id")
	{
		cout << "Which Id To Search For: " << endl;
		cin >> ID_no;
		for (int i = 0; i < 5; i++)
		{
			int Temp_ID = Data[i].getID(); //Get ID from Index 0 = 2
			Read_ID(file, i); // Set to read from 0 so beginning
			file.read((char*)& Temp_ID, sizeof(int)); //read 4 bytes
			if (Temp_ID == ID_no) //if that (data[0]==2) == ID which is 4 
			{
				cout << "--------------------------------------" << endl;
				cout << "Location Found at Index: " << i << endl;
				Read(i);
				cout << "--------------------------------------" << endl;
			}
		}
	}
	//=================================ID==================================

	else if (choice == "author")
	{
		//show books by author
		// show books by Title
		cout << "Enter Author To find: " << endl;
		//==============Enters Into Array To Search===========
		cin.ignore(1, '\n');
		cin.getline(SearchingAuthor, 50);
		//==============Enters Into Array To Search===========
		for (int i = 0; i < 5; i++)
		{

			char FullAuthor[50];
			Data[i].getAuthor(FullAuthor);
			Read_Author(file, i); //---------change this
			file.read((char*)& FullAuthor, sizeof(char) * 50);
			if (!strcmp(SearchingAuthor, FullAuthor))
			{
				cout << "--------------------------------------" << endl;
				cout << "Location Found at Index: " << i << endl;
				Read(i);
				cout << "--------------------------------------" << endl;
			}
		}

	}
	else if (choice == "title")
	{
		// show books by Title
		cout << "Enter Title To find: " << endl;
		//==============Enters Into Array To Search===========
		cin.ignore(1, '\n');
		cin.getline(SearchTitleArray, 50);
		//==============Enters Into Array To Search===========
		for (int i = 0; i < 5; i++)
		{

			char FullTitle[50];
			Data[i].getTitle(FullTitle);
			Read_Title(file, i);
			file.read((char*)& FullTitle, sizeof(char) * 50);
			if (!strcmp(SearchTitleArray, FullTitle))
			{
				cout << "--------------------------------------" << endl;
				cout << "Location Found at Index: " << i << endl;
				Read(i);
				cout << "--------------------------------------" << endl;
			}
		}

	}
	else if (choice == "status")
	{
		// show books by Title
		cout << "Enter Status To find: " << endl;
		//==============Enters Into Array To Search===========
		cin.ignore(1, '\n');
		cin.getline(SearchingBookStatus, 50);

		//==============Enters Into Array To Search===========
		for (int i = 0; i < 5; i++)
		{

			char Status[50];
			Data[i].getStatus(Status);
			Read_Status(file, i);
			file.read((char*)& Status, sizeof(char) * 50);
			if (!strcmp(SearchingBookStatus, Status))
			{
				cout << "--------------------------------------" << endl;
				cout << "Location Found at Index: " << i << endl;
				Read(i);
				cout << "--------------------------------------" << endl;
			}
		}



		//=============================EDIT======================================
		//cout << "(1)In Library----(2)Lost------(3)Damaged" << endl;
		/*string StatusChoice;
		string Temp;
		string Temp2;
		cin >> StatusChoice;



		if (StatusChoice == "1")
		{
			Temp = "In Library";
			Temp2 = "1";


			for (int i = 0; i < 5; i++)
			{
				char Status[50];
				Data[i].getStatus(Status);
				Read_Status(file, i);
				file.read((char*)& Status, sizeof(char) * 50);
				if (!strcmp(Temp.c_str(), Status))
				{
					cout << "--------------------------------------" << endl;
					cout << "Location Found at Index: " << i << endl;
					Read(i);
					cout << "--------------------------------------" << endl;
				}
				else if (!strcmp(Temp.c_str(), Status))
				{
					cout << "--------------------------------------" << endl;
					cout << "Location Found at Index: " << i << endl;
					Read(i);
					cout << "--------------------------------------" << endl;
				}
			}

		}
		else if (StatusChoice == "2")
		{
			Temp = "Lost";
			Temp2 = "2";

			cin.ignore(0, '\n');
			cin.getline(SearchingBookStatus, 50);

			for (int i = 0; i < 5; i++)
			{
				char Status[50];
				Data[i].getStatus(Status);
				Read_Status(file, i);
				file.read((char*)& Status, sizeof(char) * 50);
				if (!strcmp(SearchingBookStatus, Status))
				{
					cout << "--------------------------------------" << endl;
					cout << "Location Found at Index: " << i << endl;
					Read(i);
					cout << "--------------------------------------" << endl;
				}
				else if (!strcmp(SearchingBookStatus, Temp2.c_str()))
				{
					cout << "--------------------------------------" << endl;
					cout << "Location Found at Index: " << i << endl;
					Read(i);
					cout << "--------------------------------------" << endl;
				}
			}
		}
		else if (StatusChoice == "3")
		{
			Temp = "Damaged";
			Temp2 = "3";

			cin.ignore(0, '\n');
			cin.getline(SearchingBookStatus, 50);

			for (int i = 0; i < 5; i++)
			{
				char Status[50];
				Data[i].getStatus(Status);
				Read_Status(file, i);
				file.read((char*)& Status, sizeof(char) * 50);
				if (!strcmp(SearchingBookStatus, Status))
				{
					cout << "--------------------------------------" << endl;
					cout << "Location Found at Index: " << i << endl;
					Read(i);
					cout << "--------------------------------------" << endl;
				}
				else if (!strcmp(SearchingBookStatus, Temp2.c_str()))
				{
					cout << "--------------------------------------" << endl;
					cout << "Location Found at Index: " << i << endl;
					Read(i);
					cout << "--------------------------------------" << endl;
				}
			}
		}*/

	}
	else
	{
		cout << "Pick A Option Listed..." << endl;
		search_integer();
	}

}
//================END SEARCH BY NAME FUNCTION==================================

int main()
{
	//-----------------Initialization-------------
	bool cont = true;
	bool incorrectStatement = false;
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
			if (n > 5)
			{
				cout << "Max Limit is 5" << endl;
				n = 5;
				cout << "Displaying Last Index Entry" << endl;
				cout << "===========================" << endl;
			}
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
			cout << "\t\t\t Which Record Index To update?" << endl;
			search_integer();
			cout << "Update Record Index No: ";
			cin >> n;

			while (incorrectStatement == false)
			{
				//Either change Name or ID
				cout << "Would you like to edit?" << endl;
				cout << "Enter ==================>(id)---(name)----(title)----(author)-----(status)-----(date)---" << endl;
				cin >> response;

				//=============NAME=================
				if (response == "name")
				{
					Overwrite_NAME(n);
					incorrectStatement = true;
				}
				//=============NAME=================

				//=============ID=================
				else if (response == "id")
				{
					OVERWRITE_Integer(n);
					incorrectStatement = true;

				}
				//=============ID=================

				//==============TITLE=================
				else if (response == "title")
				{
					OVERWRITE_Title(n);
					incorrectStatement = true;

				}
				//==============TITLE=================

				//==============AUTHOR================
				else if (response == "author")
				{
					OVERWRITE_Author(n);
					incorrectStatement = true;

				}
				//==============AUTHOR================

				//=============STATUS=================
				else if (response == "status")
				{
					OVERWRITE_BookStatus(n);
					incorrectStatement = true;

				}
				//=============STATUS=================

				//=============DATE===================
				else if (response == "date")
				{
					OVERWRITE_Date(n);
					incorrectStatement = true;

				}
				//=============DATE===================

				else
				{
					incorrectStatement = false;
					cout << "Entered something else" << endl;
					cout << "-exiting command-" << endl;
					cout << "==============================" << endl;
					//break;
				}
			}
			break;
		case's':
			//searches record accordingly
			cout << "\t\t\t Searching Index..." << endl;
			search_integer();
			cout << endl;
			cout << "\t\t\t Searching..." << endl;
			break;
		default:
			cout << "Please Choose one of the Options listed" << endl;
			break;
		}
	}
	cont = false;
	return 0;

}




