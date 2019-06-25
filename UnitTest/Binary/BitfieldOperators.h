#pragma once

int BinaryToDecimal(int Array[], int size)
{
	int total = 0; //at 0
	int exponent = size-1; // one number less than size of array
	for (int i = 0; i < size; i++)
	{
		//Starts at the amount of numbers
		if (Array[i] == 1) //starts at array[0] and then if array[0] == 1 
		{
			total = total + 1 * (2 ^ exponent); //if 1 then 1 * 2 by the exponent of size at default
		}
		else
		{
			total = total + 0 * (2 ^ exponent); //if 0 then 0*2 by exponent of size
		}
		exponent--; //exponent decrements
	}
	return total;
}


// 1 1 0 1 1
// 0x01 (1) << 5
// 









//t = 5;
//expo = 4;
//1st iteration to = 16 [i=0]
//expo = 3;
//2nd iteration to = 16 + 8 = 24[i=1]
//expo = 2;
//3rd iteration to = 24 + 0 = 24[i=2]
//expo = 1;
//4th iteration to = 24 + 2 = 26[i=3]
//expo = 0 
//5th iteration to = 26 + 1 = 27[i=4]
//expo -1
