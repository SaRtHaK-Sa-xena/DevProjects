// HASHING.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include "HashFunction.h"

using namespace std;

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

namespace HasFunction
{
	//implementation of a basic addition hash
	unsigned int thirdHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash *= data[i];
		}
		return hash;
	}
}

namespace HasFunction
{
	//implementation of a basic addition hash
	unsigned int fourthHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; ++i)
		{
			hash /= data[i];
		}
		return hash;
	}
}

int main()
{
	bool cont = true;
	char choice = '0';
	char t[25] = "TED";
	
	//Works==============================
	int a = HasFunction::badHash(t, 25);
	cout << a << endl;
	int s = HasFunction::secondHash(t, 25);
	cout << s << endl;
	//Works==============================

	int m = HasFunction::thirdHash(t, 25);
	cout << m << endl;
	int d = HasFunction::fourthHash(t, 25);
	cout << d << endl;
	

	

	//char t[25] = "Sample";
	//unsigned int length;
	//int x = HasFunction::badHash(t, 25);
	//cout << x << endl;
	//cout << badHash(t, length);
}


