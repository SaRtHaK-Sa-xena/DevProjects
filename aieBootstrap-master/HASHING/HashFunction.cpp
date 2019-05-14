// HASHING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "HashFunction.h"

using namespace std;

//Addition
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
//Addtion

//Subtraction
namespace HasFunction
{
	//implementation of a basic addition hash
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
//Subtraction

//Add Two Character Arrays
namespace HasFunction
{
	//implementation of a basic addition hash
	unsigned int thirdHash(const char* data, const char* data2, unsigned int length)
	{
		/*unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash *= data[i];
		}
		return hash;*/
		unsigned int hash = 0;
		unsigned int hash2 = 0;
		unsigned int result;
		for (int i = 0; i < length; i++)
		{
			hash = hash + data[i];
			hash2 = hash2 + data2[i];
			result = hash + hash2;
		}
		return result;
		
	}
}
//Add Two Character Arrays

//Subtract Two Character Arrays
namespace HasFunction
{
	//implementation of a basic addition hash
	unsigned int fourthHash(const char* data, const char* data2, unsigned int length)
	{
		unsigned int hash = 0;
		unsigned int hash2 = 0;
		unsigned int result;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash = hash + data[i];
			hash2 = hash2 + data2[i];
		}
		if (hash > hash2)
		{
			result = hash - hash2;
		}
		else
		{
			result = hash2 - hash;
		}
		return result;
	}
}
//Subtract Two Character Arrays

//Multiply Two Character Arrays
namespace HasFunction
{
	//implementation of a basic addition hash
	unsigned int fifthHash(const char* data, const char* data2, unsigned int length)
	{
		unsigned int hash = 0;
		unsigned int hash2 = 0;
		unsigned int result;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash = hash + data[i];
			hash2 = hash2 + data2[i];
		}
		result = hash * hash2;
		return result;
	}
}
//Multiply Two Character Arrays



int main()
{
	bool cont = true;
	char choice = '0';
	char t[4] = "TED";
	char sample[4] = "SAM";
	
	//Works==============================
	int a = HasFunction::badHash(t, 4);
	cout << a << endl;

	int s = HasFunction::secondHash(t, 4);
	cout << s << endl;
	

	int m = HasFunction::thirdHash(t, sample, 4);
	cout << m << endl;

	int d = HasFunction::fourthHash(t, sample, 4);
	cout << d << endl;

	int MultiplyBoth = HasFunction::fifthHash(t, sample, 4);
	cout << MultiplyBoth << endl;
	//Works==============================

	

	//char t[25] = "Sample";
	//unsigned int length;
	//int x = HasFunction::badHash(t, 25);
	//cout << x << endl;
	//cout << badHash(t, length);
}


