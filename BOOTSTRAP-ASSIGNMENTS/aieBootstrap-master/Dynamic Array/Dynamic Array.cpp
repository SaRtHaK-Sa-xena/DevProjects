// Dynamic Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DynamicArrayClass.h"
#include "Node.h"


using namespace std;

int main()
{
	char choice = '0';
	bool cont = true;
	int a_value;

	DynamicArrayClass *dynamic_array;


	while (cont)
	{
		cout << "----------(a)dd-------(r)emove------(m)odify-------(f)ind----" << endl;
		cout << endl;

		cin >> choice;
		switch (choice)
		{
		case'a':
			cout << "\t\t\t Adding..." << endl;
			cin >> a_value;
			dynamic_array->insert(a_value);
		default:
			cout << "Choose one of the options listed" << endl;
		}
	}
	return 0;
}


