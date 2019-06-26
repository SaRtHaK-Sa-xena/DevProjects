#pragma once

int BinaryToDecimal(int Array[], int size)
{
	//int total = 0; //at 0
	//int exponent = size-1; // one number less than size of array
	//for (int i = 0; i < size; i++)
	//{
	//	//Starts at the amount of numbers
	//	if (Array[i] == 1) //starts at array[0] and then if array[0] == 1 
	//	{
	//		total = total + 1 * (2 ^ exponent); //if 1 then 1 * 2 by the exponent of size at default
	//	}
	//	else
	//	{
	//		total = total + 0 * (2 ^ exponent); //if 0 then 0*2 by exponent of size
	//	}
	//	exponent--; //exponent decrements
	//}
	//return total;

	int result = 0; //at 0

	//Starts at the amount of numbers
	for (int i = 0; i < size; i++)
	{
		result = result << 1 | Array[i];//iterates over and adds the binary data, through 'or'(" | ") bit function.
	}

	return result;
}

void DecimalToBinary(int input)
{
	int decrementer = 128;

	for (int i = 0; i < 8; i++) //iterator to go through 8 times
	{
		if (input >= decrementer) //if decrementer number can be fit inside input number
		{
			input = input - decrementer; //TRUE then subtract
			std::cout << "1";
		}
		else
		{
			std::cout << "0"; //FALSE can't fit inside it so place 0
		}
		decrementer = decrementer / 2; //then after return true or false ---> make decrementer move down the array by dividing it by 2
																 //Array --->  [128][64][32][16][8][4][2][1]  <----- Array
	}
}


int binToDec(const char* binaryString)
{
	int result = 0;

	for (int i = 0; i < 5; i++)
	{
		result = result << 1 | 5 + binaryString[i];
	}
	return result;
}
void decToBin(char* binaryString, int length, int value)
{

}
void setBit(char& bitfield, char bit, char value)
{
	
}
char checkBit(char& bitfield, char bit)
{
	return 'c';
}



// 1 1 0 1 1
// 0x01 (1) << 5
// 





