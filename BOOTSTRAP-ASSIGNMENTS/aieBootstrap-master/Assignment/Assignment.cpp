// Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "time.h"
#include <string>
using namespace std;


int main()
{
	cout << "Start! " << endl;
	srand(time(NULL));
	string red = "red";
	string blue = "blue";
	string yellow = "yellow";
	string green = "green";
	char arrayOfColours[4] = { 'R','B','G','Y' };


	int rounds = 1;

	////while (rounds <= 5)
	////{
	////	cout << "Starting Round! " << endl;
	////	int difficulty = 1;
	////	const int Rounds = 1;
	////	char temporaryArray[Rounds]; //1
	////	for (int i = 0; i < difficulty; i++) //difficulty  
	////	{
	////		temporaryArray[i] = arrayOfColours[rand() % difficulty];
	////		arrayOfColours[i] = temporaryArray[i];
	////		cout << arrayOfColours[i] << endl;
	////	}

	////	char AnswerArray[Rounds];
	////	for (int i = 0; i < difficulty; i++)
	////	{
	////		cout << "Enter: " << endl;
	////		cin >> AnswerArray[i];
	////	}

	////	if (AnswerArray[difficulty] == arrayOfColours[difficulty]
	////		&& AnswerArray[difficulty] == arrayOfColours[difficulty]
	////		&& AnswerArray[difficulty] == arrayOfColours[difficulty]
	////		&& AnswerArray[difficulty] == arrayOfColours[difficulty])
	////	{
	////		cout << "Correct! " << endl;
	////	}
	////	else if (AnswerArray[difficulty] == arrayOfColours[difficulty])
	////	{
	////		cout << "Correct! " << endl;
	////	}
	////	else if (AnswerArray[difficulty] == arrayOfColours[difficulty]
	////		&& AnswerArray[difficulty] == arrayOfColours[difficulty])
	////	{
	////		cout << "Correct! " << endl;
	////	}
	////	else if (AnswerArray[difficulty] == arrayOfColours[difficulty]
	////		&& AnswerArray[difficulty] == arrayOfColours[difficulty] 
	////		&& AnswerArray[difficulty] == arrayOfColours[difficulty])
	////	{
	////		cout << "Correct! " << endl;
	////	}
	////	
	////	else
	////	{
	////		cout << "Incorrect! " << endl;
	////	}
	////	difficulty++;
	////	rounds++;
	////}
	////cout << "NICE JOB! YOU WIN EVERYTHING! " << endl;

	 
	//randomize and place into array
	//char arrayTest[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	arrayTest[i] = arrayOfColours[rand() % 4]; //array[0] = random so like green in array[0]
	//	arrayOfColours[i] = arrayTest[i];//then colors[0] will equal = position array[0]
	//	cout << arrayOfColours[i] << endl;//so colors[0] equals green,- reset array[1] = colors[]
	//}

	//char AnswerArray[4];
	//for (int i = 0; i < 4; i++)
	//{
	//	cout << "Enter: " << endl;
	//	cin >> AnswerArray[i];
	//}

	//cout << "---------END----------" << endl;
	//
	//
	//if (AnswerArray[0] == arrayOfColours[0]
	//	&& AnswerArray[1] == arrayOfColours[1]
	//	&& AnswerArray[2] == arrayOfColours[2]
	//	&& AnswerArray[3] == arrayOfColours[3])
	//{
	//	cout << "Correct! " << endl;
	//}

	//else
	//{
	//	cout << "Incorrect! " << endl;
	//}
}


//---------__________________________________------------------

//for (int i = 0; i < 4; i++)
//{
//	arrayTest[i] = arrayOfColours[i]; //red equal to array pos 1 of arrayTest
//}
//
//cout << "Test Array: " << endl;
//for (int i = 0; i < 4; i++)
//{
//	cout << arrayTest[i] << endl;
//}

//---------__________________________________------------------




//cout << arrayTest[rand() % 4]; //Gets Random Value in Array





//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

	/*for (int i = 0; i < 4; i++)
	{
		cout << arrayTest[i] << endl;
	}*/

	//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+