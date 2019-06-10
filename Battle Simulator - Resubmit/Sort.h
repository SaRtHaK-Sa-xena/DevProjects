#pragma once
using namespace std;
//Function Used

//-----------------------------------------Swapping--------------------------------------------
//Example function for swapping
void swapFunction(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}



//Swapping for Team Blue
void swapFunctionBlue(TeamBlue *fp, TeamBlue *gp)
{
	TeamBlue temporary = *fp;
	*fp = *gp;
	*gp = temporary;
}
//Swapping for Team Red
void swapFunctionRed(TeamRed *ep, TeamRed *rp)
{
	TeamRed temporary = *ep;
	*ep = *rp;
	*rp = temporary;
}



//------------------------------------------Sorting--------------------------------------------

//Sorting Team Blue
void sortBlueTeam(TeamBlue arr[], int &x)
{
	for (int i = 0; i <= x - 1; i++)
	{
		for (int j = 0; j < x - 1; j++)
		{
			if (arr[j].B_GetHealth() < arr[j + 1].B_GetHealth())
			{
				swapFunctionBlue(&arr[j], &arr[j + 1]);
			}
		}
	}
}



//Sorting Team Red
void sortRedTeam(TeamRed arr[], int &y)
{
	for (int i = 0; i <= y - 1; i++)
	{
		for (int j = 0; j < y - 1; j++)
		{
			if (arr[j].R_GetHealth() < arr[j + 1].R_GetHealth())
			{
				swapFunctionRed(&arr[j], &arr[j + 1]);
			}
		}
	}
}


//-----------------------------------------------Other Functions Used---------------------------------------------------------

void printBlue(TeamBlue arr[], int i, int length, string ar[])
{
	cout << "====================Battle=============" << endl;
	cout << "Health: " << arr[i].B_GetHealth() << endl;
	arr[i].B_GetAttack();
	cout << "\nHealth: " << arr[i].B_GetHealth() << endl;
	sortBlueTeam(arr, length);
	cout << endl;
	cout << "================Blue Battle Summary=============" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "Name: " << ar[i] << "\nHealth: " << arr[i].B_GetHealth() << "\n" << endl;
	}
	cout << "======================================" << endl;
}

void printRed(TeamRed arr[], int i, int length, string ar[])
{
	cout << "====================Battle=============" << endl;
	cout << "Health: " << arr[i].R_GetHealth() << endl;
	arr[i].R_GetAttack();
	cout << "\nHealth: " << arr[i].R_GetHealth() << endl;
	sortRedTeam(arr, length);
	cout << endl;
	cout << "====================Red Battle Summary=============" << endl;
	for (int i = 0; i < length; i++)
	{
		cout << "Name: " << ar[i] << "\nHealth: " << arr[i].R_GetHealth() << "\n" << endl;
	}
	cout << "======================================" << endl;
}
