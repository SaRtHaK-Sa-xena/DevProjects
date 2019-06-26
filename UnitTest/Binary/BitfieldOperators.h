#pragma once

int binToDec(const char* binaryString)
{
	int result = 0;

	for (int i = 7; i > -1; i--) //starting iterator at the end of the array
	{
		if (binaryString[i] == '1')
		{
			result = result | 1 << 7 /*maxSize*/ - i; //size puts it at the end of the array, then end - 1, so it always is furthest right
			//result = result << 1 | 5 + binaryString[i];
		}
		//else--> number is 0, so it shouldn't get result to calculate it
	}
	return result; //returns correct decimal
}

void decToBin(char* binaryString, int length, int value)
{
	int decrementer = 128;
	for (int i = 0; i < length; i++)//iterate over as many numbers as there are in array-->(8)
	{
		if (value >= decrementer)
		{
			value = value - decrementer;//TRUE then subtract
			binaryString[i] = '1'; //since true, write 1 inside binaryString
		}
		else
		{
			binaryString[i] = '0';//FALSE can't fit inside it so place 0
		}
		decrementer = decrementer / 2;//then after return true or false ---> make decrementer move down the array by dividing it by 2
																 //Array --->  [128][64][32][16][8][4][2][1]  <----- Array
	}
}
void setBit(char& bitfield, char bit, char value)
{
	//create temporary char to create a bit in that place, for being created or being cleared
	// 0 = cleared, 1 = set

	char temporary = 1 << bit; //moves it to the intended bit
	if (value == 1) //if we are setting it
	{
		bitfield |= temporary; //sets that position to equal 1.
	}
	else //if we are clearing it, so 0
	{
		bitfield ^= temporary; //sets that position to equal 0.
	}

}
char checkBit(char& bitfield, char bit)
{
	//make temporary char to return the position of variable in field
	char temporary = 1 << bit; /*<-- This shifts it by "bit" and moves*/
	if ((bitfield & temporary) == temporary) /*To the variable we want to use.*/
	{
		return '1'; //if 1 then it has been set
	}
	else
	{
		return '0'; //if 0 then hasn't been set
	}
}