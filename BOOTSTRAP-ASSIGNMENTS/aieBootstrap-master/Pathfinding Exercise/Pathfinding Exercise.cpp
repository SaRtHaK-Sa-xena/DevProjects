// Pathfinding Exercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int Array[3][3] = { {1, 2, 3 }, {4, 5, 6}, {7, 8, 9}
};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << Array[i][j];
		}
		std::cout << std::endl;
	}
}