// Battle Simulator - Resubmit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Sims.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "ClassConstructors.h"
#include "Sort.h"
#include <string>
#include <time.h>
using namespace std;

int main()
{
	//---------------------------------Initializing--------------------------------------
	srand(time(NULL));
	string ar[] = { "BLUE Scout","BLUE Knight", "BLUE Commander" };
	string RAR[] = { "RED Scout","RED Knight", "RED Commander" };
	TeamBlue b_arr[3];
	TeamRed r_arr[3];
	int arrLength = sizeof(b_arr) / sizeof(b_arr[0]);
	int r_arrLength = sizeof(r_arr) / sizeof(r_arr[0]);
	int randomHealth = 1 + rand() % 10;
	//int randomAttack = 1 + rand() % 10;
	char turn = 'B';
	int x = 1;
	int y = 2;
	//----------------------------------------------------------------------------------



	//Assigning Stats for BlueTeam
	for (int i = 0; i < arrLength; i++)
	{
		int randomAttack = 1 + rand() % 10;
		b_arr[i].B_SetHealth(randomHealth * x); //Set random health between 1-10
		x++;
		for (int j = 0; j < arrLength; j++)
		{
			b_arr[i].B_SetAttack(r_arr[i].R_SetAttack(randomAttack)); //set the TeamBLue attack to equal the TeamReds[0-3]attack
		}
	}

	//Assigning Stats for RedTeam
	for (int i = 0; i < r_arrLength; i++)
	{
		int randomAttack = 1 + rand() % 10;
		r_arr[i].R_SetHealth(randomHealth * y); //sets health for every position to 1-10
		y++;
		for (int j = 0; j < r_arrLength; j++)
		{
			r_arr[i].R_SetAttack(b_arr[i].B_SetAttack(randomAttack)); //set the positions of red attack to TeamBlue attack
		}
	}


	//print array Blue, array Red, then have turns, to attack position 1
	//loop to check if a team member is 'alive'
	while ((b_arr[0].B_GetHealth() > 0 || b_arr[1].B_GetHealth() > 0 || b_arr[2].B_GetHealth() > 0) && (r_arr[0].R_GetHealth() > 0 || r_arr[1].R_GetHealth() > 0 || r_arr[2].R_GetHealth() > 0))
	{

		//system("CLS");
		if (turn == 'B')
		{
			printBlue(b_arr, 0, arrLength, ar); //print function that prints the Health, damaged Health, and then sorts it and prints it
			cin.get();
			turn = 'R';
		}
		else if (turn == 'R')
		{
			printRed(r_arr, 0, r_arrLength, RAR);
			cin.get();
			turn = 'B';
		}
	}
	if (b_arr[0].B_GetHealth() == 0 && b_arr[1].B_GetHealth() == 0 && b_arr[2].B_GetHealth() == 0)
	{
		cout << "Red Team Has Won The Battle!!!" << endl;
	}
	else if(r_arr[0].R_GetHealth() == 0 && r_arr[1].R_GetHealth() == 0 && r_arr[2].R_GetHealth() == 0)
	{
		cout << "Blue Team Has Won The Battle!!!" << endl;
	}
	cout << "\nGameOver";
	cin.get();
	//End of Simulation
}


int TeamBlue::B_GetHealth()
{
	if (health < 0)
	{
		health = 0;
	}
	return health;
}
void TeamBlue::B_SetHealth(int h) //set BlueTeam health
{
	health = h;
}

int TeamBlue::B_GetAttack() //display attack, and return health - attack
{
	
	cout << "Took Damage From Red Army: " << attack << endl;
	return health -= attack;
}

int TeamBlue::B_SetAttack(int a) //setting attack - used for random
{
	attack = a;
	return a;
}


int TeamRed::R_GetHealth()
{
	if (health < 0)
	{
		health = 0;
	}
	return health;
}
void TeamRed::R_SetHealth(int h) //setting RedTeam health - random used
{
	health = h;
}

int TeamRed::R_GetAttack()
{
	cout << "Took Damage From Blue Army: " << attack; //return health after damage
	return health -= attack;
}
int TeamRed::R_SetAttack(int a) //I put 10, so if I input in something.R_SetAttack(B_SetAttack) then it will make attack = 10
{
	attack = a;
	return attack;
}



