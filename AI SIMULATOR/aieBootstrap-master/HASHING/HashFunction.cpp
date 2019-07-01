// HASHING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "HashFunction.h"

using namespace std;

//Addition of a Char Array
namespace HasFunction
{
	//implementation of a basic addition hash
	unsigned int badHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash += data[i];
		}
		return hash;
	}
}


//Subtraction of a char array
namespace HasFunction
{
	//implementation of a basic subtraction hash
	unsigned int secondHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
		{
			//hash -= data[i];
			hash = hash - data[i];
		}
		return hash;
	}
}


//Adding Two Char Arrays
namespace HasFunction
{
	//implementation of Adding two character array
	unsigned int thirdHash(const char* data, const char* data2, unsigned int length)
	{
		unsigned int hash = 0;
		unsigned int hash2 = 0;

		unsigned int result;
		for (unsigned int i = 0; i < length; ++i)
		{
			hash = hash + data[i];
			hash2 = hash2 + data2[i];
			result = hash + hash2;
		}
		return result;
	}
}


//Multiplying Two Char Array
namespace HasFunction
{
	//implementation of a multiplication hash
	unsigned int fourthHash(const char* data, const char* data2, unsigned int length)
	{
		unsigned int hash = 0;
		unsigned int hash2 = 0;
		int result;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash = hash + data[i];
			hash2 = hash2 + data2[i];
			result = hash * hash2;
		}
		return result;
	}
}

int main()
{
	bool cont = true;
	//char choice = '0';
	char t[4] = "TED";
	char sample[4] = "JIM";
	
	//=============Adding Together A char Array=======
	int a = HasFunction::badHash(t, 4);
	cout << a << endl;

	//=============Subtracting Together A char Array=======
	int s = HasFunction::secondHash(t, 4);
	cout << s << endl;
	
	
	//Adding Two char Arrays
	int m = HasFunction::thirdHash(t, sample, 4);
	cout << m << endl;

	//Multiplying Two Char Arrays
	int d = HasFunction::fourthHash(t, sample, 25);
	cout << d << endl;
	

	

	//char t[25] = "Sample";
	//unsigned int length;
	//int x = HasFunction::badHash(t, 25);
	//cout << x << endl;
	//cout << badHash(t, length);
}


